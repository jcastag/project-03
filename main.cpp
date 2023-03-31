
#define _CRT_RAND_S

#include <iostream>
#include <thread>
#include <random>
#include <cmath>
#include <stdlib.h>
#include "graph.h"
#include "mbox.h"

#define _CRT_RAND_S
#define MAX_BYTES = 1000
#define msg = "hot-potato!"
using namespace std;

double rand_unit()
{
    random_device r;
    mt19937 g(r());
    uniform_real_distribution<> d(0.0, 1.0);
    return d(g);
}

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

struct ThreadArgs
{
    int nodeId;
    int saved;
    int forwarded;
    Graph graph;
    vector<Letters> letters;
};

void threadFunc(ThreadArgs args)
{

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
    vector<ThreadArgs> arguments(newGraph.getNodeNum());
    for (int i = 0; i < newGraph.getNodeNum(); i++)
    {
        arguments[i].nodeId = i;
        arguments[i].graph = newGraph;

        threads[i] = thread(threadFunc, ref(arguments[i]));
    }

    cout << rand_range(0, 10) << endl;
    cout << rand_range(0, 10) << endl;
    cout << rand_range(0, 10) << endl;

    // wait
    //  join threads
    //  have report

    return 0;
}