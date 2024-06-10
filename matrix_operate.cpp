#include<iostream>
#include<vector>
#include<stdexcept>
#include "matrix_operate.hpp"

Matrix::Matrix(int rows, int cols, const std::vector<float> &data): rows(rows), cols(cols), data(data) {}

std::ostream& operator<<(std::ostream& os, const Matrix mat){
    for(int i=0; i<mat.rows*mat.cols; i++) {
        std::cout << mat.data[i] << " ";
        if((i+1)%mat.cols == 0) {
            std::cout << std::endl;}
    }
    return os;    
}

Matrix Matrix::operator+(const Matrix &mat) const {
    if(rows != mat.rows || cols != mat.cols){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        new_data[i] = data[i] + mat.data[i];
    }
    return Matrix(rows, cols, new_data);
}

Matrix Matrix::operator-(const Matrix &mat) const {
    if(rows != mat.rows || cols != mat.cols){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        new_data[i] = data[i] - mat.data[i];
    }
    return Matrix(rows, cols, new_data);
}

Matrix Matrix::operator*(float a) const {
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++){
        new_data[i] = data[i] * a;
    }
    return Matrix(rows, cols, new_data);
}

Matrix operator*(float a, const Matrix &mat) {
    return mat * a;
}

Matrix Matrix::operator*(const Matrix &mat) const {
    if(rows != mat.rows || cols != mat.cols){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        new_data[i] = data[i] * mat.data[i];
    }
    return Matrix(rows, cols, new_data);
}

Matrix::~Matrix()
{
    // std::cout << "hha" << std::endl;
}

float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2) {
    if(vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vector dimensions do not match");
    }
    float res = 0;
    for(int i=0; i<vec1.size(); i++) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

Matrix matmul(const Matrix &mata, const Matrix &matb) {
    if(mata.cols != matb.rows) {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    std::vector<float> new_data(mata.rows*matb.cols);
    for(int i=0; i<mata.rows*matb.cols; i++){
        int row = i / matb.cols;
        int col = i % matb.cols;
        std::vector<float> row_data(mata.data.begin() + row*mata.cols, mata.data.begin() + (row+1)*mata.cols);
        std::vector<float> col_data;
        for(int j=0; j<matb.rows; j++) {
            col_data.push_back(matb.data[j*matb.cols + col]);
        }
        new_data[i] = vec_dot(row_data, col_data);
    }
    return Matrix(mata.rows, matb.cols, new_data);
}