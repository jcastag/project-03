#include "graph.h"

Graph::Graph(string filename)
{
    this->vertices = 0;
    this->nodeNum = 0;

    // opening file
    string line;
    std::ifstream inputFile(filename);
    while (!inputFile.eof())
    {
        getline(inputFile, line);
        if (line[0] != '#')
        {
            linetoGraph(line);
        }
    }
}

int Graph::getNodeNum()
{
    return this->nodeNum;
}

Node Graph::getNode(int i)
{
    return this->nodes[i];
}

void Graph::linetoGraph(string line)
{
    string v;
    Node node;
    stringstream x(line);
    if (getline(x, v, ':'))
    {
        node.nodeId = stoi(v);
        this->nodeNum++;
    }
    while (getline(x, v, ','))
    {
        node.adj.push_back(stoi(v));
    }
    this->nodes.push_back(node);
}

void Graph::printgraph()
{
    for (int i = 0; i < this->nodeNum; i++)
    {
        cout << this->nodes[i].nodeId << " : ";
        for (int j = 0; j < this->nodes[i].adj.size(); j++)
        {
            cout << this->nodes[i].adj[j] << " ";
        }
        cout << endl;
    }
}