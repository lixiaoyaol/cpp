/*Author: libofeng, Mail: bf_li@qq.com
 *All rights reserved*/
#include "matrix_operate.hpp"


//Matrix class functions block
Matrix::Matrix(int rows, int cols, const std::vector<float> &data): rows(rows), cols(cols), data(data) {
    if (data.size() != rows*cols) {
        throw std::invalid_argument("Data size does not match matrix dimensions for construction");
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix &mat){
    for(int i=0; i<mat.rows*mat.cols; i++) {
        os << mat.data[i] << " ";
        if((i+1)%mat.cols == 0) {
            os << std::endl;}
    }
    return os;    
}

Matrix Matrix::operator+(const Matrix &mat) const {
    if(rows != mat.rows || cols != mat.cols){
        throw std::invalid_argument("Matrix dimensions do not match for addition");
    }
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        new_data[i] = data[i] + mat.data[i];
    }
    return Matrix(rows, cols, new_data);
}

Matrix Matrix::operator-(const Matrix &mat) const {
    if(rows != mat.rows || cols != mat.cols){
        throw std::invalid_argument("Matrix dimensions do not match for substraction");
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
        throw std::invalid_argument("Matrix dimensions do not match for matrix element multiplication");
    }
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        new_data[i] = data[i] * mat.data[i];
    }
    return Matrix(rows, cols, new_data);
}

Matrix Matrix::transpose() const {
    std::vector<float> new_data(rows*cols);
    for(int i=0; i<rows*cols; i++) {
        int row = i / rows;
        int col = i % rows;
        new_data[row*rows + col] =  data[col*cols + row];
    }
    return Matrix(cols, rows, new_data);
}

Matrix::~Matrix()
{
    // std::cout << "hha" << std::endl;
}
//Matrix class functions end

float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2) {
    if(vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vector dimensions do not match for vector product");
    }
    float res = 0;
    for(int i=0; i<vec1.size(); i++) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

Matrix matmul(const Matrix &mata, const Matrix &matb) {
    if(mata.cols != matb.rows) {
        throw std::invalid_argument("Matrix dimensions do not match for matrix multiplication");
    }
    std::vector<float> new_data(mata.rows*matb.cols);
    for(int i=0; i<mata.rows*matb.cols; i++){
        int row = i / matb.cols;
        int col = i % matb.cols;
        std::vector<float> row_data(mata.data.begin() + row*mata.cols, 
                                    mata.data.begin() + (row+1)*mata.cols);
        std::vector<float> col_data;
        col_data.reserve(matb.rows);
        for(int j=0; j<matb.rows; j++) {
            col_data.push_back(matb.data[j*matb.cols + col]);
        }
        new_data[i] = vec_dot(row_data, col_data);
    }
    return Matrix(mata.rows, matb.cols, new_data);
}

Matrix eyen(int n) {
    std::vector<float> data(n*n, 0);
    for(int i=0; i<n; i++) {
        data[i*n + i] = 1;
    }
    return Matrix(n, n, data);
}

Matrix matcat(const Matrix &mata, const Matrix &matb, int axis) {
    if(axis == 0) {
        if(mata.cols != matb.cols) {
            throw std::invalid_argument("Matrix dimensions do not match for concatenation");
        }
        std::vector<float> new_data((mata.rows + matb.rows) * mata.cols);
        for(int i=0; i<mata.rows*mata.cols; i++) {
            new_data[i] = mata.data[i];
        }
        for(int i=0; i<matb.rows*matb.cols; i++) {
            new_data[mata.rows*mata.cols + i] = matb.data[i];
        }
        return Matrix(mata.rows + matb.rows, mata.cols, new_data);
    }
    else if(axis == 1) {
        if(mata.rows != matb.rows) {
            throw std::invalid_argument("Matrix dimensions do not match for concatenation");
        }
        std::vector<float> new_data(mata.rows * (mata.cols + matb.cols));
        for(int i=0; i<mata.rows; i++) {
            for(int j=0; j<mata.cols; j++) {
                new_data[i*(mata.cols + matb.cols) + j] = mata.data[i*mata.cols + j];
            }
            for(int j=0; j<matb.cols; j++) {
                new_data[i*(mata.cols + matb.cols) + mata.cols + j] = matb.data[i*matb.cols + j];
            }
        }
        return Matrix(mata.rows, mata.cols + matb.cols, new_data);
    }
    else {
        throw std::invalid_argument("Invalid axis for concatenation");
    }
}
