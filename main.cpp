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
void printMatrix(vector< vector < int > >, string);
vector< int > checkForDuplicates(vector< vector < int >> matrix, int column, int rows);
void printVector(vector<int> counts);
vector < vector< int > > resolveDuplicates(vector < vector < int > > matrix, int column, vector < int > dupeList,
        int rows);

void openDataFile(){
    /* Opens a data file for reading
     * Reads in the first line to get the row and column numbers
      * Creates a matrix to hold the data in the data file as elements in the matrix*/
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
    // Print out the request matrix
    printMatrix(requestMatrix, "Request Matrix");

    vector<int> counts;
    for(int port = 0; port < ports; port++){
        counts.push_back(getCounts(requestMatrix, agents, port));
    }

    vector< vector < int > > countMatrix = buildCountMatrix(requestMatrix, counts, agents, ports);
    printMatrix(countMatrix, "Count Matrix");

    vector< vector < int > > grantMatrix = buildGrantMatrix(countMatrix, agents, ports);
    vector< int > dupeList;
    cout << "Entering loop\n";
    for(int column = 0; column < ports; column++){
        dupeList = checkForDuplicates(grantMatrix, column, agents);
        grantMatrix = resolveDuplicates(grantMatrix, column, dupeList, agents);
        printMatrix(grantMatrix, "Grant Matrix");
    }

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

    for (int agent = 0; agent < agents; agent++) {
        bool found = false;
        int i = 1;
        while (not found) {

            for (int port = 0; port < ports; port++) {
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
        if (found) {
            for (int port = 0; port < ports; port++) {
                if (countMatrix[agent][port] != i)
                    countMatrix[agent][port] = 0;
            }
        }

    }
    printMatrix(countMatrix, "Grant Matrix");
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

void printMatrix(vector< vector < int > > matrix, string name){
    cout << "------\n" << name << "\n" << "------\n";
    for(auto it = matrix.begin(); it != matrix.end(); it++){
        for (auto itt = it->begin(); itt != it->end(); itt++){
            cout << *itt;
        }
        cout << endl;
    }
}

vector< int > checkForDuplicates(vector< vector < int > > matrix, int column, int rows){
    /*Given a column in a matrix, checks the column for non-zero entries and stores the row index in a vector
    * Returns: a vector of row indices where a non-zero entry occurs*/
    vector< int > index_list;
    for(int row = 0; row < rows; row++){
        if (matrix[row][column]){
            index_list.push_back(row);
        }
    }
    return index_list;
}

vector< vector < int > > resolveDuplicates(vector < vector < int > > matrix, int column, vector < int > dupeList,
        int rows){
    //Select a random index from the dupeList and then set all the other elements of the matrix column to 0
    if(not dupeList.empty()){
        int randomIndex = rand() % dupeList.size();
        cout << "Random index: " << randomIndex << "\n";
        for (int row = 0; row < rows; row++){
            if(row == dupeList[randomIndex])
                continue;
            matrix[row][column] = 0;
        }
    }

    return matrix;
}

int main() {
    openDataFile();
}
