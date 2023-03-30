#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
struct Node
{
    int nodeId;
    std::vector<int> adj;
};

class Graph
{
    int vertices;
    int nodeNum;
    std::vector<Node> nodes;
    void linetoGraph(string);

public:
    Graph(string filename); // takes filename to create graph
    Node getNode(int);
    void printgraph();
    int getNodeNum();
};
