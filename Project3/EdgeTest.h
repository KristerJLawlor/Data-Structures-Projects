//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 3rd, 2021
//This Program is for testing the Edge class

#ifndef EDGETEST_H_INCLUDED
#define EDGETEST_H_INCLUDED
#include "Edge.h"
#include "Vertex.h"
#include <iostream>

void EdgeTest()
{
    std::cout << "\n\n----------------------------" << std::endl;
    std::cout << "TESTING EDGE CLASS\n\n" << std::endl;

    //create vertices
    Vertex e1_src("Edge1Src");
    Vertex e1_dst_e2_src("Edge1Dst&Edge2Src");
    Vertex e2_dst("Edge2Dst");

    //create edges using vertices
    Edge edge1(&e1_src, &e1_dst_e2_src, 3);
    Edge edge2(&e1_dst_e2_src, &e2_dst, 5);

    //print out edge information
    std::cout << "Edge 1: " << edge1.getSource()->getName() << " -> " << edge1.getDestination()->getName() << " weight: " << edge1.getWeight() << std::endl;

    std::cout << "Edge 2: " << edge2.getSource()->getName() << " -> " << edge2.getDestination()->getName() << " weight: " << edge2.getWeight() << std::endl;

    //construct a new edge by combining two edges together
    Edge edge1plus2(edge1, edge2);

    //print out combined edge information
    std::cout << "Combined Edge1 and Edge2: " << edge1plus2.getSource()->getName() << " -> " << edge1plus2.getDestination()->getName() << " weight: " << edge1plus2.getWeight() << std::endl;

    std::cout << "----------------------------" << std::endl;

}



#endif // EDGETEST_H_INCLUDED
