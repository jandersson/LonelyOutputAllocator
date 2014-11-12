/*
ECE-427/527
Integrated Interconnection Networks
Project 2
Write a program to implement the Lonely Output Allocator.
The input to the program is (in the following exact order and format):
(1) The number of rows (input ports) and the number of columns (output ports)
of the Request Matrix
(2) The Request matrix with entries of 1 (indicating request) or 0 (indicated no request)
separated by a space

The output of the program should be (a) the Count Matrix and (b) the Grant Matrix under (b1)
the Input-First and (b2) the Output-First criterion.

Include Comments and produce output for 3 different Request matrices of your choice

Sample Input:
-------------
14 16
1 0 0 0 0 0 0 0 0 0 0 0 0...
0 1 ...
.
.
.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

//Function Prototypes
int getCounts(vector<vector <int> >, int , int);
vector<vector< int > > buildCountMatrix(vector<vector< int > >, vector<int> , int , int);
vector< vector < int > > buildGrantMatrix(vector< vector < int > >, int , int);
void printMatrix(vector< vector < int > >);

void openDataFile(){
    /* Opens a data file for reading */
    string fileName = "mytest.txt";
    char delimiter = ' ';
    string token;
    stringstream iss;
    ifstream dataFile;
    vector<vector<int> > requestMatrix;
    string line = "";
    dataFile.open(fileName);
    int agents = 0;
    int ports = 0;
    if (dataFile.is_open()){
        getline(dataFile, line, ' ');
        agents = atoi(line.c_str());
        getline(dataFile, line);
        ports = atoi(line.c_str());

        //Get the entire line, then parse the line for spaces (whatever delimiter)
        while(getline(dataFile, line, '\n')){
            vector<int> requestVector;
            iss << line;
            while(getline(iss, token, delimiter)){
                cout << token;
                requestVector.push_back(atoi(token.c_str()));
            }
            requestMatrix.push_back(requestVector);
            iss.clear();
            cout << '\n';
        }
            }

    cout << "Agents: " << agents << endl;
    cout << "Ports: " << ports << endl;
    cout << "Request Matrix\n-------\n";
    // Print out the request matrix
    printMatrix(requestMatrix);

    vector<int> counts;
    for(int port = 0; port < ports; port++){
        counts.push_back(getCounts(requestMatrix, agents, port));
    }

    vector< vector < int > > countMatrix = buildCountMatrix(requestMatrix, counts, agents, ports);
    cout << "Count Matrix\n------\n";
    printMatrix(countMatrix);

    buildGrantMatrix(countMatrix, agents, ports);
}

vector<vector< int > > buildCountMatrix(vector<vector< int > > requestMatrix, vector<int> counts, int agents, int ports){
    vector<vector < int > > countMatrix;

    for (int agent = 0; agent < agents; agent++){
        vector< int > countVector;
        countVector.resize(ports);
        countMatrix.push_back(countVector);
        for (int port = 0; port < ports; port++){
            if (requestMatrix[agent][port]){
                countMatrix[agent][port] = counts[port];
            }
        }
    }

    return countMatrix;
}

vector< vector < int > > buildGrantMatrix(vector< vector < int > > countMatrix, int agents, int ports){
    //Loop through each vector and find the lowest number
    bool found = false;
    int agent = 0;
    int i = 1;
    while(not found){

        for (int port = 0; port < ports; port++){
            cout << countMatrix[agent][port] << endl;
            if (countMatrix[agent][port] == i)
                found = true;
        }
        if (found)
            break;
        i += 1;
        if (i > agents)
            break;
    }
    //Loop through vector and set all high numbers to 0
    if(found){
        for(int port = 0; port < ports; port++){
            if (countMatrix[agent][port] != i)
                countMatrix[agent][port] = 0;
        }
    }
    cout << "Grant\n";
    printMatrix(countMatrix);
    return countMatrix;
}

int getCounts(vector<vector <int> > requestMatrix, int agents, int port){
    /*Get the number of requests for a given port and return it*/
    int requests = 0;
    for (int agent = 0; agent < agents; agent++){
        if (requestMatrix[agent][port]){
            requests += 1;
        }
    }
    return requests;
}

void printVector(vector<int> counts){
    //Print out counts vector
    for(auto it = counts.begin(); it != counts.end(); it++){
        cout << *it;
    }
}

void printMatrix(vector< vector < int > > matrix){
    for(auto it = matrix.begin(); it != matrix.end(); it++){
        for (auto itt = it->begin(); itt != it->end(); itt++){
            cout << *itt;
        }
        cout << endl;
    }
}

int main() {
    openDataFile();
}
