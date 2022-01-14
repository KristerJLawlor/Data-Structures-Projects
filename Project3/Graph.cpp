//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 1st, 2021
//This Program is the class implementation of a Graph by using Breadth/Depth first and shortest path by using the Dijkstra's algorithm

#include "Graph.h"
#include <algorithm>
#include <iostream>

//constructor
Graph::Graph()
{
    mAdjListGenerated = false;
}

//destructor
Graph::~Graph()
{
    //dtor
}

// Add an edge to the graph
int Graph::addEdge(Edge* new_edge)
{
    mAdjListGenerated = false;

    mEdges.push_back(new_edge);
    return 0;
}

// Add a vertex to the graph
int Graph::addVertex(Vertex* new_vertex)
{
    mAdjListGenerated = false;

    mVertices.push_back(new_vertex);
    return 0;
}

//breadth first searching
void Graph::BreadthFirstSearch(std::string src_v) const
{
    //get a starting node given by user
    auto source_vertex = getVertexByName(src_v);

    //two vectors; one for visited nodes and one for yet to be visited nodes
    std::deque<Vertex*> searched_vertices, to_search;
    //push the starting node to to_search
    to_search.push_back(source_vertex);

    while (!to_search.empty())
    {
        //set the current node
        auto current_vertex = to_search.front();
        //pop the front of the nodes to search once you set it to the current vertex
        to_search.pop_front();

        //make sure the current vertex isn't the last in the list. If we don't do that, it will infinitely print out the last node
        if(std::find(searched_vertices.begin(), searched_vertices.end(), current_vertex) != searched_vertices.end())
        {
            continue;
        }

        //add the current node to the searched/visited list
        searched_vertices.push_back(current_vertex);

        std::cout << current_vertex->getName() << std::endl;

        //cycle through all the edges at the current node/vertex
        for (auto edge : current_vertex->getEdges())
        {
            //set the destination node of edge to new_vertex
            auto new_vertex = edge->getDestination();

            //add the new_vertex to the to_search list
            to_search.push_back(new_vertex);
        }
    }

}

//depth first search
void Graph::DepthFirstSearch(std::string src_v) const
{
    //get a starting node given by user
    auto source_vertex = getVertexByName(src_v);

    //two vectors; one for visited nodes and one for yet to be visited nodes
    std::deque<Vertex*> searched_vertices, to_search;
    //push the starting node to to_search
    to_search.push_back(source_vertex);

    //
    while (!to_search.empty())
    {
        //set the current node
        auto current_vertex = to_search.front();
        //pop the front of the nodes to search once you set it to the current vertex
        to_search.pop_front();

        //make sure the current vertex isn't the last in the list. If we don't do that, it will infinitely print out the last node
        if(std::find(searched_vertices.begin(), searched_vertices.end(), current_vertex) != searched_vertices.end())
        {
            continue;
        }

        //add the current node to the searched/visited list
        searched_vertices.push_back(current_vertex);

        std::cout << current_vertex->getName() << std::endl;

        //cycle through all the edges at the current node/vertex
        for (auto edge : current_vertex->getEdges())
        {
            //set the destination node of edge to new_vertex
            auto new_vertex = edge->getDestination();

            //add the new_vertex to the to_search list
            to_search.push_front(new_vertex);
        }
    }
}

// depth first degree ordered
void Graph::DepthFirstSearchDegreeOrdered(std::string src_v) const
{
    //get the starting node given by user
    auto source_vertex = getVertexByName(src_v);

    //two vectors; one for visited nodes and one for yet to be visited nodes
    std::deque<Vertex*> searched_vertices, to_search;
    //push the starting node to to_search
    to_search.push_back(source_vertex);

    //while the list of nodes to search is not empty
    while (!to_search.empty())
    {
        //set the current node
        auto current_vertex = to_search.front();
        //pop the front of the nodes to search once you set it to the current vertex
        to_search.pop_front();
        //make sure the current vertex isn't the last in the list. If we don't do that, it will infinitely print out the last node
        if(std::find(searched_vertices.begin(), searched_vertices.end(), current_vertex) != searched_vertices.end())
        {
            continue;
        }

        //add the current node to the searched/visited list
        searched_vertices.push_back(current_vertex);

        //print the current vertex name with the number of edges associated with them
        std::cout << current_vertex->getName() << ":" << current_vertex->getEdges().size() << std::endl;

        std::deque<Vertex*> new_vertices_to_check;
        //cycle through all the edges at the current node/vertex
        for (auto edge : current_vertex->getEdges())
        {
            //set the destination node of edge to new_vertex
            auto new_vertex = edge->getDestination();

            unsigned int i = 0;
            for (i = 0; i < new_vertices_to_check.size(); i++)
            {
                //insert them in order of increasing degree
                if (new_vertex->getEdges().size() < (new_vertices_to_check[i])->getEdges().size())
                {
                    break;
                }
            }
            //insert new_vertex
            new_vertices_to_check.insert(new_vertices_to_check.begin()+i, new_vertex);
        }

        to_search.insert(to_search.begin(), new_vertices_to_check.begin(), new_vertices_to_check.end());
    }
}

//generate an adjacency list of a vector of vectors of type Vertex*
std::vector<std::vector<Vertex*>> Graph::generateAdjacencyList()
{
    //return mAdjList if mAdjListGenerated is true
    if (mAdjListGenerated)
    {
        return mAdjList;
    }

    //create vector of vectors of Vertex* with size equaling the number of vertices
    std::vector<std::vector<Vertex*>> adj_list(mVertices.size());
    for(auto e : mEdges)
    {
        //trying out find instead of using a regular linear search
        //get the position that a node is at by using find to return the iterator the node is at
        auto pos_src = std::find(mVertices.begin(), mVertices.end(), e->getSource());
        //subtracting the beginning of the vector from the iterator from find() to get an offset/index
        int idx_src = pos_src - mVertices.begin();
        //push index of node to the adj_list vector vector
        adj_list[idx_src].push_back(e->getDestination());
    }

    mAdjListGenerated = true;
    mAdjList = adj_list;

    return mAdjList;
}

// Get shortest path by using dijkstra's algorithm
std::string Graph::shortestPath(std::string v_src, std::string v_dst) const
{
    // Get the source edges and put them into a double ended queue
    auto src_edges = getVertexByName(v_src)->getEdges();
    //double ended queue of Edge pointer type
    std::deque<Edge*> edges;
    //loop through edges in src_edges and perform an insertion sort
    //Goal is to place the shortest edges in to the front of the queue
    for (auto e : src_edges)
    {
        unsigned int i = 0;
        for (i = 0; i < edges.size(); i++)
        {
            if (*e < *(edges[i]))
            {
                break;
            }
        }
        //First iteration will just insert to edges by default
        edges.insert(edges.begin()+i, e);
    }


    //get the shortest edge from the front of edges and the vertex it leads to
    auto shortest_edge = edges.front();
    auto next_vertex   = shortest_edge->getDestination();
    edges.pop_front(); // remove this shortest edge so we don't search it again

    while (next_vertex->getName() != v_dst)
    {

        std::cout << "\n-----------------\n" << std::endl;
        std::cout << "Took " << shortest_edge->getName() << std::endl;
        auto dst_edges = next_vertex->getEdges();
        for (auto e : dst_edges)
        {
            // Check if this new edge would create a loop
            if(shortest_edge->getName().find(e->getDestination()->getName()) != std::string::npos) {
                continue; // If the destination was already in the path, we have a loop, so skip this edge
            }
            // Create a new edge combining the next vertex's edges
            // with this shortest edge
            Edge* p_e = new Edge(*shortest_edge, *e);

            // Place the new edge in the correct location of the
            // edges list to keep it sorted
            unsigned int i = 0;
            for (i = 0; i < edges.size(); i++)
            {
                if (*p_e < *(edges[i])) break;
            }
            edges.insert(edges.begin()+i, p_e);

        }

        std::cout << "-------------\n" << std::endl;
        for (auto e : edges)
        {
            std::cout << e->getName() << ":" << e->getWeight() << std::endl;
        }
        std::cout << "\n-------------\n" << std::endl;

        // empty edges means there was no path from the source to the destination
        if (edges.empty()) return "No Path to Destination";

        // Grab the new shortest edge
        shortest_edge = edges.front();
        next_vertex   = shortest_edge->getDestination();
        edges.pop_front(); // remove this shortest edge so we don't search it again
    }

    return shortest_edge->getName();
}

//Search for a vertex in the graph by name and return its pointer
Vertex* Graph::getVertexByName(std::string v_name) const
{
    // Linear search through mVertices to find one with a matching name
    for (unsigned int i = 0; i < mVertices.size(); i++)
    {
        if(mVertices[i]->getName() == v_name)
        {
            return mVertices[i];
        }
    }
    return nullptr;
}
