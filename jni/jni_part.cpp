#include <jni.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <vector>

using namespace std;
using namespace cv;

extern "C" {
JNIEXPORT void JNICALL Java_org_opencv_samples_tutorial2_Tutorial2Activity_FindFeatures(JNIEnv*, jobject, jlong addrGray, jlong addrRgba);

JNIEXPORT void JNICALL Java_org_opencv_samples_tutorial2_Tutorial2Activity_FindFeatures(JNIEnv*, jobject, jlong addrGray, jlong addrRgba)
{
    Mat& mGr  = *(Mat*)addrGray;
    Mat& mRgb = *(Mat*)addrRgba;
    vector<KeyPoint> v;

    FastFeatureDetector detector(50);
    detector.detect(mGr, v);
    for( unsigned int i = 0; i < v.size(); i++ )
    {
        const KeyPoint& kp = v[i];
        circle(mRgb, Point(kp.pt.x, kp.pt.y), 10, Scalar(255,0,0,255));
    }

}

JNIEXPORT void JNICALL Java_org_opencv_samples_tutorial2_Tutorial2Activity_WarpFeatures(JNIEnv*, jobject, jlong addrRgba, jlong addrmRgba)
{

	Mat& input= *(Mat*)addrRgba;
	Mat& output= *(Mat*)addrmRgba;
	if(input.cols>input.rows){//450
		for(int y = 0; y< input.cols-300; y++){
			for(int x = 0; x<input.rows-300; x ++)
			{
//				Vec3b color = input.at<Vec3b>(Point(y,x));
//
//				        if(color[0] > 150 && color[1] > 150 && color[2] > 150)
//				        {
//				            color[0] = 0;
//				            color[1] = 0;
//				            color[2] = 0;
//
//				        }
//				        else
//				        {
//							color.val[0] = 255;
//							color.val[1] = 255;
//							color.val[2] = 255;
//			        }
//				Vec3b color = input.at<Vec3b>(Point(y,x));
				input.at<Vec3b>(Point(y,x))[0]=255;
				input.at<Vec3b>(Point(y,x))[1]=255;
				input.at<Vec3b>(Point(y,x))[2]=255;
			}
		}
	}

//	Vec3b color = input.at<Vec3b>(Point(10,10));
//	output.at<Vec3b>(Point(20,20))= color;
//
//	input = input + Scalar(75, 75, 75);
}


}
