//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of a Vertex/node

#include "Vertex.h"
#include <algorithm>
#include <cstring>
#include "Edge.h"

// Constructor for Vertex
Vertex::Vertex(const std::string name)
{
    // Assign the name
    mName = name;
}

Vertex::~Vertex()
{
    //dtor
}

// Add an edge for this vertex
int Vertex::addEdge(Edge* new_edge)
{
    mEdges.push_back(new_edge);
    return 0;
}
