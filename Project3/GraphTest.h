//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 4th, 2021
//This Program is for testing the Graph class

#ifndef GRAPHTEST_H_INCLUDED
#define GRAPHTEST_H_INCLUDED
#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"
#include <iostream>

void GraphTest(Graph graph)
{

    std::cout << "\n\n----------------------------" << std::endl;
    std::cout << "TESTING GRAPH CLASS\n\n" << std::endl;

    //test shortest path
    std::cout << "testing shortest path from a to f" << std::endl;
    std::cout << (graph.shortestPath("a", "f")) << std::endl;
    std::cout << "-------------" << std::endl;

    //test breadth first
    std::cout << "testing breadth first" << std::endl;
    graph.BreadthFirstSearch("a");
    std::cout << "-------------" << std::endl;

    //test depth first
    std::cout << "testing depth first" << std::endl;
    graph.DepthFirstSearch("a");
    std::cout << "-------------" << std::endl;

    //test depth first search with degree
    std::cout << "testing depth first with degree" << std::endl;
    graph.DepthFirstSearchDegreeOrdered("a");
    std::cout << "-------------" << std::endl;

    //test adjacency list
    std::cout << "testing adjacency list: " << std::endl;
            std::vector<std::vector<Vertex*>> adj_list = graph.generateAdjacencyList();
            std::cout << "Adjacency list with vertices in order as in graph.txt" << std::endl;
            for(auto v : adj_list) //v is now a vector of pointers to vertices
            {
                for(auto a : v) //a is a pointer to a vertex in each vector v
                {
                    std::cout << a->getName() << " " ;
                }
                std::cout << std::endl;
                std::cout << "-------------------------" << std::endl;
            }

            std::cout << "----------------------------" << std::endl;

}

#endif // GRAPHTEST_H_INCLUDED
