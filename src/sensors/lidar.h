//
// Created by swmmbd on 2023-01-11.
//

#ifndef PCL_TEST_LIDAR_H
#define PCL_TEST_LIDAR_H

#include "../render/render.h"
#include <ctime>
#include <chrono>

const double pi = 3.1415;

struct Ray {
    Vect3 origin;
    double resolution;
    Vect3 direction;
    Vect3 castPosition;
    double castDistance;

    Ray(Vect3 setOrigin, double horizontalAngle, double verticalAngle,
        double setResolution) : origin(setOrigin), resolution(setResolution),
        direction(resolution*cos(verticalAngle)*cos(horizontalAngle),
                  resolution*cos(verticalAngle)*sin(horizontalAngle),
                  resolution*sin(verticalAngle)),
        castPosition(origin), castDistance(0) {}
};

#endif //PCL_TEST_LIDAR_H
