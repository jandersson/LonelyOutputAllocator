#include "Matrix.h"
#include <vector>
Matrix::Matrix(){

}
Matrix::~Matrix(){

}
void Matrix::setRows(rows){
    this.rows = rows;
}
void Matrix::setColumns(columns){
    this.columns = columns;
}
int Matrix::getRows(){
    return this.rows;
}
int Matrix::getColumns(){
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
void Matrix::addRow(vector< int > row){

}