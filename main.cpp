
#define _CRT_RAND_S

#include <iostream>
#include <thread>
#include <stdlib.h>
#include "graph.h"
#include "mbox.h"

#define _CRT_RAND_S
#define MAX_BYTES = 1000
#define msg = "hot-potato!"
using namespace std;

// function for picking wait/sleep time
double rand_exponential(double mean)
{
    return -mean * log(rand_unit());
}

// function for picking recipient
double rand_range(double min, double max)
{
    return rand_unit() * (max - min) + min;
}

double rand_unit()
{
    unsigned int num;
    return rand_s(&num);
}

struct Letters
{
    int travelTime;
    int hopCount;
    Letters(int t, int h)
    {
        this->travelTime = t;
        this->hopCount = h;
    }
};

struct Args
{
    int nodeId;
    Graph graph;
    int saved;
    int forwarded;
    vector<Letters> letters;
};

void threadFunc(Args info)
{
    // make a message
    // pick a destination
    // send message
    //  recieving messages, not sending if thread is destination
}

int main()
{
    // CREATING GRAPH
    string size;

    string line;
    cout << "graph size: ";
    cin >> size;

    string path = "graph/A" + size + ".dat";

    Graph newGraph = Graph(path);
    newGraph.printgraph();
    vector<thread> threads(newGraph.getNodeNum());
    vector<Args> arguments(newGraph.getNodeNum());
    for (int i = 0; i < newGraph.getNodeNum(); i++)
    {
        arguments[i].graph = newGraph;
        arguments[i].nodeId = i;
        threads[i] = thread(threadFunc, arguments[i]);
    }

    // wait
    //  join threads
    //  have report

    return 0;
}