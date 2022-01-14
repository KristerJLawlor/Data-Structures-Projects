//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of an Edge

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <deque>
#include "Edge.h"
#include "Vertex.h"

class Graph
{
    public:
        //constructor
        Graph();
        //destructor
        virtual ~Graph();

        //add edge to the graph
        int addEdge(Edge* new_edge);
        //add vertex to the graph
        int addVertex(Vertex* new_vertex);

        //perform breadth first search
        void BreadthFirstSearch(std::string src_v) const;
        //perform depth first search
        void DepthFirstSearch(std::string src_v) const;
        //perform degree ordered depth first search
        void DepthFirstSearchDegreeOrdered(std::string src_v) const;

        //Find the shortest path
        std::string shortestPath(std::string src, std::string dst) const;
        //std::string shortestPathAlt(std::string v_src, std::string v_dst);
        //Create the adjacency list
        std::vector<std::vector<Vertex*>> generateAdjacencyList();

        Vertex* getVertexByName(std::string v_name) const;

    protected:

    private:
    //data members
    //vector of Vertex pointers
    std::vector<Vertex*> mVertices;
    //vector of Edge pointers
    std::vector<Edge*> mEdges;

    bool mAdjListGenerated;
    //vector of vectors holding pointers of Vertex type
    std::vector<std::vector<Vertex*>> mAdjList;
};

#endif // GRAPH_H
