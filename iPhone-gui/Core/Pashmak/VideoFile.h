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

	unsigned int GetLength() override;
	void GotoFrame(unsigned int frame) override;
	bool GetNextFrame(std::shared_ptr<Picture>& frame) override;
};

