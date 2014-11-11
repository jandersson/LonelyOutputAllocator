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


using namespace std;

void openDataFile(){
    /* Opens a data file for reading */
    string fileName = "mytest.txt";
    char delimiter = ' ';
    string token;
    stringstream iss;
    ifstream dataFile;
    vector<int> requestMatrix;
    string line = "";
    dataFile.open(fileName);
    int agents = 0;
    int ports = 0;
    cout << dataFile.is_open() << endl;
    if (dataFile.is_open()){
        getline(dataFile, line, ' ');
        cout << line << endl;
        agents = atoi(line.c_str());
        getline(dataFile, line);
        ports = atoi(line.c_str());
        //Get the entire line, then parse the line for spaces (whatever delimiter)
        while(getline(dataFile, line, '\n')){
            iss << line;
            while(getline(iss, token, delimiter)){
                cout << token;
                requestMatrix.push_back(atoi(token.c_str()));
            }
            iss.clear();
            cout << '\n';
        }

            }

    cout << "Agents: " << agents << endl;
    cout << "Ports: " << ports << endl;
    for(auto it = requestMatrix.begin(); it != requestMatrix.end(); it++){
        cout << *it;
    }
}

int main() {
    openDataFile();
}
