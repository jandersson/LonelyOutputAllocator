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
#include <stdlib.h>

using namespace std;

void openDataFile(){
    string fileName = "mytest.txt";
    ifstream dataFile;
    string line = "";
    dataFile.open(fileName);
    int agents = 0;
    int ports = 0;
    if (dataFile.is_open()){
        while (getline(dataFile, line, ' ')){
            int agents = atoi(line.c_str());
            int ports = atoi(line.c_str());
        }
    }
    cout << agents << endl;
    cout << ports << endl;
}

int main() {
    openDataFile();
}
