//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 3rd, 2021
//This Program is for testing the Vertex class

#ifndef VERTEXTEST_H_INCLUDED
#define VERTEXTEST_H_INCLUDED
#include "Vertex.h"
#include "Edge.h"
#include <iostream>

void VertexTest()
{
    std::cout << "\n\n----------------------------" << std::endl;
    std::cout << "TESTING VERTEX CLASS\n\n" << std::endl;

    //create vertices
    Vertex v1_start("TestStart");
    Vertex v1_end1("TestEnd1");
    Vertex v1_end2("TestEnd2");
    Vertex v1_end3("TestEnd3");

    //create edges using vertices with added weights
    Edge e1(&v1_start, &v1_end1, 1);
    Edge e2(&v1_start, &v1_end2, 2);
    Edge e3(&v1_start, &v1_end3, 3);

    //add edges to the central node v1_start
    v1_start.addEdge(&e1);
    v1_start.addEdge(&e2);
    v1_start.addEdge(&e3);

    //loop through the edges list for central node v1_start
    std::cout << "Edges coming from v1_start: " << std::endl;
    for( auto v : v1_start.getEdges() )
    {
        //print out edge information for v1_start
        std::cout << "Destination: " << v->getDestination()->getName() << std::endl << "Weight: " << v->getWeight() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;

}



#endif // VERTEXTEST_H_INCLUDED
