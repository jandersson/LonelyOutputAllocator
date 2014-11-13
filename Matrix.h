#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
class Matrix{
    std::vector< vector < int > > matrix;
    int rows;
    int columns;

    Matrix();
    ~Matrix();
    void printMatrix();

};

#endif