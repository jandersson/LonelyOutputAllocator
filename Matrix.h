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
    void setRows(int rows);
    void setColumns(int columns);
    int getRows();
    int getColumns();
    void printMatrix();

};

#endif