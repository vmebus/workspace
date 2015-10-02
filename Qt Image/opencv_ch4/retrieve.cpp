/*------------------------------------------------------------------------------------------*\
   This file contains material supporting chapter 4 of the cookbook:  
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
using namespace std;

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

#include "imageComparator.h"

int main()
{
	// Read reference image
    cv::Mat image= cv::imread("D://workspace//pictures//waves.jpg");
	if (!image.data)
		return 0; 

	// Display image
	cv::namedWindow("Query Image");
	cv::imshow("Query Image",image);

	ImageComparator c;
	c.setReferenceImage(image);

	// Read an image and compare it with reference
    cv::Mat input= cv::imread("D://workspace//pictures//dog.jpg");
	cout << "waves vs dog: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//marais.jpg");
	cout << "waves vs marais: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//bear.jpg");
	cout << "waves vs bear: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//beach.jpg");
	cout << "waves vs beach: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//polar.jpg");
	cout << "waves vs polar: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//moose.jpg");
	cout << "waves vs moose: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//lake.jpg");
	cout << "waves vs lake: " << c.compare(input) << endl;

	// Read an image and compare it with reference
    input= cv::imread("D://workspace//pictures//fundy.jpg");
	cout << "waves vs fundy: " << c.compare(input) << endl;

	cv::waitKey();
	return 0;
}
