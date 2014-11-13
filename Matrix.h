#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
class Matrix{
private:

    std::vector< vector < int > > matrix;
    int rows;
    int columns;

public:

    Matrix();
    ~Matrix();
    void printMatrix();

};

#endif