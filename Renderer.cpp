#include "Renderer.h"
#include <cmath>


void Renderer::render(std::shared_ptr<Box> box, int stepsize)
{
        auto w = abs(box->leftEnd - box->rightEnd);
        auto h = abs(box->bottomEnd - box->topEnd);
        this->image_ = cv::Mat::zeros(w+5, h+5, CV_8UC3);
        cv::Scalar Color ;
        cv::rectangle(this->image_, cv::Point(box->leftEnd, box->topEnd), cv::Point(box->rightEnd, box->bottomEnd),
                      cv::Scalar(255, 255, 255),
                      3, cv::LINE_8);
        for(auto &p : box->particles_)
        {
            Color = cv::Scalar(p->color_[0], p->color_[1], p->color_[2]);
            cv::circle(this->image_, cv::Point2d(p->Center()[0], p->Center()[1]), p->Radius(), Color, -1);
        }
        imshow("2D Collision", this->image_);
        cv::waitKey(stepsize);

}