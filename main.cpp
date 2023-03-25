#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "graph.h"

#define msg "hello!";

using namespace std;

int main()
{

    string filename;
    string path = "graph/";

    string line;
    cout << "file name: ";
    cin >> filename;
    path += filename;
    cout << filename << endl;
    Graph newGraph = Graph(path);
    newGraph.printgraph();
    return 0;
}