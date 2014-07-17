#pragma 
#include "Video.h"

class VideoFile
	: public Video
{
private:
	std::shared_ptr<cv::VideoCapture> myVideoCapture;

public:
	VideoFile(const std::string& filename);
	~VideoFile();

	bool GetNextFrame(std::shared_ptr<Picture>& frame) override;
};

