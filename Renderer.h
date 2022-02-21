#ifndef RENDERER_H
#define RENDERER_H

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Box.h"

class Renderer {

    cv::Mat image_ ;

public:
    void render(std::shared_ptr<Box> box, int stepsize);

};


#endif //RENDERER_H
