//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of an Edge

#include "Edge.h"
#include "Vertex.h"
#include <iostream>

Edge::Edge(Vertex* src, Vertex* dest, int weight)
{
    mName   = src->getName() + cDelim + dest->getName();
    mSrc    = src;
    mDest   = dest;
    mWeight = weight;
}

Edge::Edge(const Edge& lhs, const Edge& rhs)
{
    mName   = lhs.getName() + cDelim + rhs.getDestination()->getName();
    mSrc    = lhs.getSource();
    mDest   = rhs.getDestination();
    mWeight = rhs.getWeight() + lhs.getWeight();
}

Edge::~Edge()
{
    //dtor
}
