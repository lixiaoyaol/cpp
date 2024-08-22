/*Author: libofeng, Mail: bf_li@qq.com
 *All rights reserved*/
#include "vector_operate.hpp"
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

float& Matrix::operator()(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Matrix index out of range at ()");
    }
    return data[i*cols + j];
}

float Matrix::at(int i, int j) const {
    if(i < 0 || i >= this->rows || j < 0 || j >= this->cols) {
        throw std::out_of_range("Matrix index out of range at at()");
    }
    return this->data[i*this->cols + j];
}

void Matrix::set(int i, int j, float val) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Matrix index out of range at set()");
    }
    data[i*cols + j] = val;
}

std::vector<float> Matrix::getrow(int i) const {
    if(i < 0 || i >= rows) {
        throw std::out_of_range("Matrix index out of range at getrow()");
    }
    return std::vector<float>(data.begin() + i*cols, data.begin() + (i+1)*cols);
}

std::vector<float> Matrix::getcol(int j) const {
    if(j < 0 || j >= cols) {
        throw std::out_of_range("Matrix index out of range at getcol()");
    }
    std::vector<float> col_data;
    col_data.reserve(rows);
    for(int i=0; i<rows; i++) {
        col_data.push_back(data[i*cols + j]);
    }
    return col_data;
}

void Matrix::setrow(int i, const std::vector<float> &row) {
    if(i < 0 || i >= rows) {
        throw std::out_of_range("Matrix index out of range at setrow()");
    }
    if(row.size() != cols) {
        throw std::invalid_argument("Row size does not match matrix column size for setrow()");
    }
    for(int j=0; j<cols; j++) {
        data[i*cols + j] = row[j];
    }
}

void Matrix::setcol(int j, const std::vector<float> &col) {
    if(j < 0 || j >= cols) {
        throw std::out_of_range("Matrix index out of range at setcol()");
    }
    if(col.size() != rows) {
        throw std::invalid_argument("Column size does not match matrix row size for setcol()");
    }
    for(int i=0; i<rows; i++) {
        data[i*cols + j] = col[i];
    }
}

Matrix Matrix::getblock(int row1, int row2, int col1, int col2) const {
    if(row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows || col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) {
        throw std::out_of_range("Matrix index out of range at getblock()");
    }
    if(row1 > row2 || col1 > col2) {
        throw std::invalid_argument("Invalid block range for getblock()");
    }
    std::vector<float> block_data;
    block_data.reserve((row2-row1+1)*(col2-col1+1));
    for(int i=row1; i<=row2; i++) {
        for(int j=col1; j<=col2; j++) {
            block_data.push_back(data[i*cols + j]);
        }
    }
    return Matrix(row2-row1+1, col2-col1+1, block_data);
   
}

void Matrix::setblock(int row1, int row2, int col1, int col2, const Matrix &block) {
    if(row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows || col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) {
        throw std::out_of_range("Matrix index out of range at setblock()");
    }
    if(row1 > row2 || col1 > col2) {
        throw std::invalid_argument("Invalid block range for setblock()");
    }
    if(block.rows != row2-row1+1 || block.cols != col2-col1+1) {
        throw std::invalid_argument("Block dimensions do not match matrix block range for setblock()");
    }
    for(int i=row1; i<=row2; i++) {
        for(int j=col1; j<=col2; j++) {
            data[i*cols + j] = block.data[(i-row1)*(col2-col1+1) + (j-col1)];
        }
    }
}

Matrix::~Matrix()
{
    // std::cout << "hha" << std::endl;
}
//Matrix class functions end


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

float trace(const Matrix &mat) {
    if(mat.rows != mat.cols) {
        throw std::invalid_argument("Matrix is not square for trace");
    }
    float sum = 0;
    for(int i=0; i<mat.rows; i++) {
        sum += mat.data[i*mat.cols + i];
    }
    return sum;
}


//在将矩阵三角化的同时，可以求出行列式的值
Matrix inverse(const Matrix &mat) {
    if(mat.rows != mat.cols) {
        throw std::invalid_argument("Matrix is not square for inversion");
    }
    int n = mat.rows;
    Matrix mate = eyen(n);
    Matrix matab = matcat(mat, mate, 1);
    for(int k=0; k<n; k++) {
        float elmax = abs(mat.at(k,k));
        int id_max = k;
        for(int i=k+1; i<n; i++) {
            if(abs(mat.at(i,k)) > abs(elmax)) {
                elmax = matab.at(i,k);
                id_max = i;
            }
        }
        std::vector<float> vtemp1 = matab.getrow(k);
        std::vector<float> vtemp2 = matab.getrow(id_max);
        matab.setrow(k, vtemp2);
        matab.setrow(id_max, vtemp1);

        for(int i=k+1; i<n; i++) {
            float temp = matab.at(i,k) / matab.at(k,k);
            matab.setrow(i, vec_sub(matab.getrow(i), vec_scalar_multiply(matab.getrow(k), temp)));
        }
    }

    for(int k=n-1; k>=1; k--) {
        matab.setrow(k, vec_scalar_multiply(matab.getrow(k), 1/matab.at(k,k)));
        for(int j=k-1; j>=0; j--) {
            matab.setrow(j, vec_sub(matab.getrow(j), vec_scalar_multiply(matab.getrow(k), matab.at(j,k))));
        }
    }

    matab.setrow(0, vec_scalar_multiply(matab.getrow(0), 1/matab.at(0,0)));

    Matrix inva = matab.getblock(0, n-1, n, 2*n-1);

    return inva;
}
