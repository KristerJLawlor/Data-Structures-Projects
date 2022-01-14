//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of a Vertex/node

#ifndef VERTEX_H
#define VERTEX_H
#include <memory>
#include <string>
#include <vector>

// Forward declarations
class Edge;

class Vertex
{

    public:
        //Constructor
        Vertex(const std::string name);
        //Destructor
        virtual ~Vertex();

        //Add edge to a vertex
        int addEdge(Edge* new_edge); // Add a new edge

        //Get the edges
        std::vector<Edge*> getEdges() const
        {
            return mEdges;
        }

        //Get the name of the vertex
        std::string getName() const
        {
            return mName;
        }


    protected:

    private:
    std::string mName; //Vertex name/label
    std::vector<Edge*> mEdges; //List of the edges starting from this vertex
};

#endif // VERTEX_H
