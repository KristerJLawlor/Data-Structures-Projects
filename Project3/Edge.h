//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of an Edge

#ifndef EDGE_H
#define EDGE_H
#include <memory>

// Forward declarations
class Vertex;

class Edge
{
    public:
        //Constructor takes the starting vertex, the destination vertex, and the weight
        Edge(Vertex* src, Vertex* dest, int weight);
        //Constructor takes the weight of two edges and combines them to make a combined path
        Edge(const Edge& lhs, const Edge& rhs);
        //Destructor
        virtual ~Edge();

        //get the name of the edge, which is the path between vertices
        std::string getName() const
        {
            return mName;
        }

        //return the edge's starting point
        Vertex* getSource() const
        {
            return mSrc;
        }

        //return the edge's destination point
        Vertex* getDestination() const
        {
            return mDest;
        }

        //return the edge's path weight
        int getWeight() const
        {
            return mWeight;
        }

        //Compare the weight of two edges of a vertex
        friend bool operator<(const Edge& lhs, const Edge& rhs)
        {
            return lhs.getWeight() < rhs.getWeight();
        }


    private:
        const std::string cDelim = " -> "; //to use -> as a delimiter
        std::string mName;
        Vertex* mSrc;
        Vertex* mDest;
        int mWeight;

};

#endif // EDGE_H
