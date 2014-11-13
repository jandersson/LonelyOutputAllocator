#include "Matrix.h"

Matrix::Matrix(){

}
Matrix::~Matrix(){

}
void setRows(rows){
    this.rows = rows;
}
void setColumns(columns){
    this.columns = columns;
}
int getRows(){
    return this.rows;
}
int getColumns(){
    return this.columns;
}
void Matrix::printMatrix() {

    for(auto it = matrix.begin(); it != matrix.end(); it++){
        for (auto itt = it->begin(); itt != it->end(); itt++){
            cout << *itt;
        }
        cout << endl;
    }

}