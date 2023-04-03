#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
    // Load the input video
    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened())
    {
        std::cerr << "Cannot open the video file" << std::endl;
        return -1;
    }

    // Define the initial region of interest (ROI)
    cv::Rect roi(0, 0, 100, 100);

    // Read the first frame of the video
    cv::Mat frame;
    cap >> frame;

    // Set the initial window position
    cv::Mat hsv, mask;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
    cv::inRange(hsv, cv::Scalar(0, 60, 32), cv::Scalar(180, 255, 255), mask);
    cv::Mat roi_hist;
    cv::Mat roi_hsv = hsv(roi);
    cv::calcHist(&roi_hsv, 1, 0, mask(roi), roi_hist, 1, &hsv.rows, 0);
    cv::normalize(roi_hist, roi_hist, 0, 255, cv::NORM_MINMAX);
    cv::TermCriteria term_criteria(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1);

    // Start the object tracking loop
    while (true)
    {
        // Read the next frame of the video
        cap >> frame;
        if (frame.empty()) break;

        // Perform object tracking
        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::Mat backproj;
        std::vector<cv::Mat> hsv_planes;
        cv::split(hsv, hsv_planes);
        cv::calcBackProject(&hsv_planes[0], 1, 0, roi_hist, backproj, &hsv_planes[0], 1);
        cv::bitwise_and(backproj, mask, backproj);
        cv::RotatedRect window = cv::CamShift(backproj, roi, term_criteria);

        // Draw the object tracking result
        cv::Point2f pts[4];
        window.points(pts);
        for (int i = 0; i < 4; i++)
            cv::line(frame, pts[i], pts[(i + 1) % 4], cv::Scalar(0, 255, 0), 2);
        cv::imshow("Object tracking", frame);

        // Wait for the user to press a key
        int key = cv::waitKey(1);
        if (key == 27) break;
    }

    // Release the video capture object
    cap.release();

    // Close all windows
    cv::destroyAllWindows();

    return 0;
}



