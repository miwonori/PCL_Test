//
// Created by swmmbd on 2023-01-11.
//

#ifndef PCL_TEST_BOX_H
#define PCL_TEST_BOX_H

#include <Eigen/Geometry>

struct BoxQ {
    Eigen::Vector3f bboxTransform;
    Eigen::Quaternionf bboxQuaternion;
    float cube_length;
    float cube_width;
    float cube_height;
};

struct Box {
    float x_min;
    float y_min;
    float z_min;
    float x_max;
    float y_max;
    float z_max;
};


#endif //PCL_TEST_BOX_H
