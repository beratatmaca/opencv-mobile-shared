#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

int main(int argc, char *argv[])
{
    // Check if an image file path is provided as a command-line argument
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    // Get the image file path from the command-line arguments
    std::string imagePath = argv[1];

    // Print OpenCV version information
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "Major version: " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version: " << CV_MINOR_VERSION << std::endl;
    std::cout << "Subversion: " << CV_SUBMINOR_VERSION << std::endl;

    // Load the image
    cv::Mat image = cv::imread(imagePath);

    if (image.empty())
    {
        std::cerr << "Error: Unable to read the image at " << imagePath << std::endl;
        return -1;
    }

    // Create a dictionary of ArUco markers
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::DetectorParameters detectorParams;
    cv::aruco::ArucoDetector detector(dictionary, detectorParams);

    // Detect markers in the image
    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejected;

    detector.detectMarkers(image, markerCorners, markerIds, rejected);

    // Output details of detected markers
    if (!markerIds.empty())
    {
        std::cout << "Detected ArUco Markers:" << std::endl;
        for (size_t i = 0; i < markerIds.size(); ++i)
        {
            std::cout << "Marker ID: " << markerIds[i] << std::endl;
            std::cout << "Corners: ";
            for (size_t j = 0; j < markerCorners[i].size(); ++j)
            {
                std::cout << "(" << markerCorners[i][j].x << ", " << markerCorners[i][j].y << ") ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No ArUco markers detected." << std::endl;
    }

    return 0;
}
