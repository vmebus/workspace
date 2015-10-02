/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 8 of the cookbook:  
   Computer Vision Programming using the OpenCV Library. 
   by Robert Laganiere, Packt Publishing, 2011.

   This program is free software; permission is hereby granted to use, copy, modify, 
   and distribute this source code, or portions thereof, for any purpose, without fee, 
   subject to the restriction that the copyright notice may not be removed 
   or altered from any source or altered source distribution. 
   The software is released on an as-is basis and without any warranties of any kind. 
   In particular, the software is not guaranteed to be fault-tolerant or free from failure. 
   The author disclaims all warranties with regard to this software, any use, 
   and any consequent failure, is purely the responsibility of the user.
 
   Copyright (C) 2010-2011 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include "harrisDetector.h"

int main()
{
	// Read input image
    cv::Mat image= cv::imread("D://workspace//pictures//church01.jpg",0);
	if (!image.data)
		return 0; 

    // Display the image
	cv::namedWindow("Original Image");
	cv::imshow("Original Image",image);

	// Detect Harris Corners
	cv::Mat cornerStrength;
	cv::cornerHarris(image,cornerStrength,
		          3,     // neighborhood size
					 3,     // aperture size
					 0.01); // Harris parameter

   // threshold the corner strengths
	cv::Mat harrisCorners;
	double threshold= 0.0001; 
	cv::threshold(cornerStrength,harrisCorners,
                 threshold,255,cv::THRESH_BINARY_INV);

    // Display the corners
	cv::namedWindow("Harris Corner Map");
	cv::imshow("Harris Corner Map",harrisCorners);

	// Create Harris detector instance
	HarrisDetector harris;
    // Compute Harris values
	harris.detect(image);
    // Detect Harris corners
	std::vector<cv::Point> pts;
	harris.getCorners(pts,0.01);
	// Draw Harris corners
	harris.drawOnImage(image,pts);

    // Display the corners
	cv::namedWindow("Harris Corners");
	cv::imshow("Harris Corners",image);

	// Read input image
    image= cv::imread("D://workspace//pictures//church01.jpg",0);

	// Compute good features to track
	std::vector<cv::Point2f> corners;
	cv::goodFeaturesToTrack(image,corners,
		500,	// maximum number of corners to be returned
		0.01,	// quality level
		10);	// minimum allowed distance between points
	  
	// for all corners
	std::vector<cv::Point2f>::const_iterator it= corners.begin();
	while (it!=corners.end()) {

		// draw a circle at each corner location
		cv::circle(image,*it,3,cv::Scalar(255,255,255),2);
		++it;
	}

    // Display the corners
	cv::namedWindow("Good Features to Track");
	cv::imshow("Good Features to Track",image);

	// Read input image
    image= cv::imread("D://workspace//pictures//church01.jpg",0);

	// vector of keypoints
	std::vector<cv::KeyPoint> keypoints;
	// Construction of the Good Feature to Track detector 

    cv::Ptr<cv::GFTTDetector> gftt = cv::GFTTDetector::create(1000,0.01,1,3,false,0.04);
    // point detection using FeatureDetector method
    gftt->detect(image,keypoints);
	
	cv::drawKeypoints(image,		// original image
		keypoints,					// vector of keypoints
		image,						// the resulting image
		cv::Scalar(255,255,255),	// color of the points
		cv::DrawMatchesFlags::DRAW_OVER_OUTIMG); //drawing flag

    // Display the corners
	cv::namedWindow("Good Features to Track Detector");
	cv::imshow("Good Features to Track Detector",image);

	// Read input image
    image= cv::imread("D://workspace//pictures//church01.jpg",0);

	keypoints.clear();

    cv::Ptr<cv::FastFeatureDetector> fast = cv::FastFeatureDetector::create(10,true,2);

    fast->detect(image,keypoints);
	
	cv::drawKeypoints(image,keypoints,image,cv::Scalar(255,255,255),cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);

    // Display the corners
	cv::namedWindow("FAST Features");
	cv::imshow("FAST Features",image);

	// Read input image
    image= cv::imread("D://workspace//pictures//church03.jpg",0);

	keypoints.clear();
	// Construct the SURF feature detector object

    cv::Ptr<cv::xfeatures2d::SURF> surf = cv::xfeatures2d::SURF::create(2500);
    // note, that it's also far more efficient, to compute keypoints and descriptors in one go.
    std::vector<cv::KeyPoint> keypoints_object;
    cv::Mat descriptors_object;
    surf->detectAndCompute(image, cv::Mat(), keypoints_object, descriptors_object);
    // Detection of the SURF features
    surf->detect(image,keypoints);

	
	cv::Mat featureImage;
	cv::drawKeypoints(image,keypoints,featureImage,cv::Scalar(255,255,255),cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    // Display the corners
	cv::namedWindow("SURF Features");
	cv::imshow("SURF Features",featureImage);

	// Read input image
    image= cv::imread("D://workspace//pictures//church01.jpg",0);

	keypoints.clear();
    // Construct the Agast feature detector object

    cv::Ptr<cv::AgastFeatureDetector> agast = cv::AgastFeatureDetector::create(10,true,2);

    // Detect the Agast features
    agast->detect(image,keypoints);
	
	cv::drawKeypoints(image,keypoints,featureImage,cv::Scalar(255,255,255),cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    // Display the corners
    cv::namedWindow("AGAST Features");
    cv::imshow("AGAST Features",featureImage);

	// Read input image
    image= cv::imread("D://workspace//pictures//church01.jpg",0);

	keypoints.clear();

    cv::Ptr<cv::MSER> mser = cv::MSER::create(5,60,14400,0.25,0.2,200,1.01,0.003,5);
    mser->detect(image,keypoints);
	
	// Draw the keypoints with scale and orientation information
	cv::drawKeypoints(image,		// original image
		keypoints,					// vector of keypoints
		featureImage,				// the resulting image
		cv::Scalar(255,255,255),	// color of the points
		cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS); //drawing flag

    // Display the corners
	cv::namedWindow("MSER Features");
	cv::imshow("MSER Features",featureImage);

	cv::waitKey();
	return 0;
}
