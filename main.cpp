
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
    static random_device r;
    static mt19937 g(r());
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
    // gives the thread time duration
    auto now = chrono::system_clock::now;
    auto stop = now() + chrono::seconds(10);

    while (now() < stop)
    {
        // sleeping
       
    }
    // pick a destination
    // this_thread::sleep_for(chrono::milliseconds())
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

    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "threads about to join ..." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    for (int i = 0; i < newGraph.getNodeNum(); i++)
    {
        threads[i].join();
    }
    cout << "threads joined." << endl;

    //  have report

    return 0;
}