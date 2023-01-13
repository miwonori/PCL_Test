//
// Created by swmmbd on 2023-01-11.
//

#include "render.h"

void renderHighway(pcl::visualization::PCLVisualizer::Ptr& viewer) {
    // units in meters
    double roadLength = 50.0;
    double roadWidth = 12.0;
    double roadHeight = 0.2;

    viewer->addCube(-roadLength/2, roadLength/2, -roadWidth/2, roadWidth/2,
                    0, 0.2, 0.2, 0.2, "highwayPavement");
    viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION,
                                        pcl::visualization::PCL_VISUALIZER_REPRESENTATION_SURFACE,
                                        "highwayPavement");
    viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR,
                                        0.2, 0.2, 0.2, "highwayPavement");
    viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_OPACITY,
                                        1.0, "highwayPavement");
    viewer->addLine(pcl::PointXYZ(-roadLength/2,-roadWidth/6, 0.01),
                    pcl::PointXYZ(roadLength/2, -roadWidth/6, 0.01), "line1");
    viewer->addLine(pcl::PointXYZ(-roadLength/2, roadWidth/6, 0.01),
                    pcl::PointXYZ(roadLength/2,  roadWidth/6, 0.01), "line2");
}

int countRays = 0;
void renderRays(pcl::visualization::PCLVisualizer::Ptr& viewer, const Vect3& origin,
                const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud) {
    for(pcl::PointXYZ point : cloud->points) {
        viewer->addLine(pcl::PointXYZ(origin.x, origin.y, origin.z), point, 1, 0,
                        0, "ray"+std::to_string(countRays));
        countRays++;
    }
}

void clearRays(pcl::visualizaton::PCLVisualizer::Ptr& viewer) {
    while(countRays) {
        countRays--;
        viewer->removeShape("ray"+std::to_string(countRays));
    }
}

void renderPointCloud(pcl::visualization::PCLVisualizer::Ptr& viewer,
                      const pcl::PointCloud<pcl::PointXYZ>Ptr& cloud,
                      str::string name, Color color=Color(1,1,1)) {
    viewer->addPointCloud<pcl::PointXYZ>(cloud, name);
    viewer->setPointCloudRenderingProperties(
            pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, name);
    viewer->setPointCloudRenderingProperties(
            pcl::visualization::PCL_VISUALIZER_COLOR, color.r, color.g, color.b,
            name);

}
void renderPointCloud(pcl::visualization::PCLVisualizer::Ptr& viewer,
                      const pcl::PointCloud<pcl::PointXYZI>Ptr& cloud,
str::string name, Color color=Color(-1,-1,-1));
void renderBox(pcl::visualization::PCLVisualizer::Ptr& viewer, Box, box, int id,
               Color color=Color(1,0,0), float opacity=1);
void renderBox(pcl::visualization::PCLVisualizer::Ptr& viewer, BoxQ, box, int id,
               Color color=Color(1,0,0), float opacity=1);