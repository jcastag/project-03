
#define _CRT_RAND_S

#include <iostream>
#include <thread>
#include <stdlib.h>
#include "graph.h"
#include "mbox.h"

#define _CRT_RAND_S
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
double rand_unit(){

    unsigned int num;
    return rand_s(&num);
}




void threadFunc(Node id){

//make a message
//pick a destination
//send message
// recieving messages, not sending if thread is destination 




}


int main()
{
    // CREATING GRAPH
    string filename;
    string path = "graph/";

    string line;
    cout << "file name: ";
    cin >> filename;
    path += filename;
    cout << filename << endl;
    Graph newGraph = Graph(path);
    newGraph.printgraph();
    vector<thread> threads(newGraph.getNodeNum());

    for(int i = 0; i < newGraph.getNodeNum(); i ++){
        threads[i] = thread();   
    }

    return 0;
}