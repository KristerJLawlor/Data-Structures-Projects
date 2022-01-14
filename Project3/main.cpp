//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Dec 4th, 2021
//This Program is the Main program that takes the input from Graph.txt file
//and stores this input in an object of Graph class that implements the Vertex and Edge class
//The user can select from the list provided in the UI to perform 5 different tasks for graphs

#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include "VertexTest.h"
#include "EdgeTest.h"
#include "GraphTest.h"

int main(int argc, char** argv)
{

    //v_count will hold the initial number of vertices given in graph.txt
    int v_count = 0;
    //string line will hold the lines retrieved from getline()
    std::string line;

    //create a graph object to be used by all actions
    Graph graph;

    //start input filestream and open up graph.txt
    std::ifstream fin("graph.txt");

    //Read the first value into v_count
    fin >> v_count;
    getline(fin, line); //eat the new line to prevent the underworld from taking stream inputs instead

    std::cout << "LOADING IN GRAPH..." << std::endl;

    //Read in all the vertices
    std::string v_name;
    for (int i = 0; i < v_count; i++)
    {
        getline(fin, v_name); //Read in the name of the vertex

        //Check for empty line
        if (strcmp(v_name.c_str(), "\n") == 0) continue;

        //Add the vertex to the vector
        graph.addVertex(new Vertex(v_name));
    }

    //Read in the edges from graph.txt
    while (getline(fin, line))
    {
        //Make sure there are no empty lines because it causes issues
        if (strcmp(line.c_str(), "\n") == 0) continue;

        //initialize a string stream with the line in order to read it separately
        std::stringstream line_ss(line);
        std::string src_name;
        std::string dst_name;
        int weight;

        // Read the inputs off the line
        getline(line_ss, src_name, ',');
        getline(line_ss, dst_name, ',');
        line_ss >> weight;

        //Output to test if file was read in correctly
        std::cout << src_name << "," << dst_name << "," << weight << std::endl;

        //Get the source and destination vertex pointers to create the edge
        Vertex* src_v = graph.getVertexByName(src_name);
        Vertex* dst_v = graph.getVertexByName(dst_name);

        // Create the Edge
        Edge* new_edge = new Edge(src_v, dst_v, weight);

        graph.addEdge(new_edge); // Add it to the vector of edges
        src_v->addEdge(new_edge); // Give the edge to the source vertex as well
    }

    std::cout << "LOADING COMPLETE." << std::endl;


    /*
    //Testing the classes
    VertexTest();
    EdgeTest();
    GraphTest(graph);
    */

    //Create user input variable
    char userinput;


    //MAIN MENU UI
     while(userinput != '0')
    {

        //print the UI selection screen
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
        std::cout << "\t-Welcome to Graph Man-" << std::endl <<
        "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

        std::cout << "Please Select One of the Following: " << std::endl <<
            "\t[1] Determine the Shortest Path between two nodes" << std::endl <<
            "\t[2] Print Adjacency List" << std::endl <<
            "\t[3] Perform a Breadth-First Search" << std::endl <<
            "\t[4] Perform a Depth-First Search" << std::endl <<
            "\t[5] Perform a Depth-First Search where Nodes Edges are Ordered\n\t    by Increasing Degree of Destination Node" << std::endl <<
            "\t[0] To exit Program" << std::endl <<
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "\nEnter Your Selection: " << std::endl;

        //Take user input
        userinput = getchar();

        //to get the shortest path between two nodes
        if(userinput == '1')
        {
            std::string first_node;
            std::string second_node;
            std::cout << "Enter First Node: " ;
            std::cin >> first_node;
            std::cin.sync();
            std::cout << std::endl;
            std::cout << "Enter Second Node: " ;
            std::cin >> second_node;
            std::cin.sync();
            std::cout << std::endl;

            //Call function
            std::cout << (graph.shortestPath(first_node, second_node)) << std::endl;
        }

        //to get adjacency list
        if(userinput == '2')
        {
            std::cout << "Generating Adjacency List: " << std::endl;
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
        }

        //to do breadth-first search
        if(userinput == '3')
        {
            std::string srch_node;
            std::cout << "Enter Node to Search: " << std::endl;
            std::cin >> srch_node;
            std::cin.sync();
            std::cout << "-------------" << std::endl;
            graph.BreadthFirstSearch(srch_node);
            std::cout << "-------------" << std::endl;
        }

        //to do depth-first search
        if(userinput == '4')
        {
            std::string srch_node;
            std::cout << "Enter Node to Search: " << std::endl;
            std::cin >> srch_node;
            std::cin.sync();
            std::cout << "-------------" << std::endl;
            graph.DepthFirstSearch(srch_node);
            std::cout << "-------------" << std::endl;
        }

        //to do depth-first search where node edges are ordered on degree
        if(userinput == '5')
        {
            std::string srch_node;
            std::cout << "Enter Node to Search: " << std::endl;
            std::cin >> srch_node;
            std::cin.sync();
            std::cout << "-------------" << std::endl;
            graph.DepthFirstSearchDegreeOrdered(srch_node);
            std::cout << "-------------" << std::endl;
        }

        std::cin.sync();
        std::cout << "\n\n\n";
        std::cin.sync();

    }

    return 0;
}
