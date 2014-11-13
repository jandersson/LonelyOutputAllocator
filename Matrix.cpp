#include "Matrix.h"

Matrix::Matrix(){

}
Matrix::~Matrix(){

}

void Matrix::printMatrix() {

    for(auto it = matrix.begin(); it != matrix.end(); it++){
        for (auto itt = it->begin(); itt != it->end(); itt++){
            cout << *itt;
        }
        cout << endl;
    }

}