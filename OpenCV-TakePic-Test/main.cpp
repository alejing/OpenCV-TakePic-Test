//
//  main.cpp
//  OpenCV-TakePic-Test
//
//  Created by Alejandro Franco on 23/03/16.
//  Copyright © 2016 Alejandro Franco. All rights reserved.
//

#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

String inttostr(int input)
{
    stringstream ss;
    ss << input;
    return ss.str();
}

int main(void)
{
    Mat frame;
    
    vector<int> compression_params;
    // vector that stores the compression parameters of the image
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    // specify the compression technique
    compression_params.push_back(100); //specify the compression quality
    // initialize image counter
    int photocount = 0;
    String imagename;
    int key;
    // open camera no.0  0=internal 1=external
    VideoCapture cap(1);
    // wait 30 milliseconds and check for "s" key
    while ((key = waitKey(30)) != 115)
    {
        // save captured image to frame variable
        cap >> frame;
        // show image on window named Camara
        imshow("Camara", frame);
        if (key == 'c')
        {
            // increment image number for each capture
            photocount++;
            imshow("Imagen capturada", frame);
            
            imagename = "/Users/ImagenesOpenCV/foto " + inttostr(photocount) + ".jpg";
            // finalize imagename to save
            imwrite(imagename, frame, compression_params);
            
        }
        
    }
}
