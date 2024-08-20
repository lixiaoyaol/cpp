/*Author: libofeng, Mail: bf_li@qq.com
 *All rights reserved*/

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>

class Matrix
{
public:
    int rows;
    int cols;
    std::vector<float> data;

public:
    Matrix(int rows, int cols, const std::vector<float> &data);

    //operator overload
    friend std::ostream& operator<<(std::ostream& os, const Matrix &mat);

    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(float a) const;
    friend Matrix operator*(float a, const Matrix &mat);
    Matrix operator*(const Matrix &mat) const;
    float& operator() (int i, int j);

    //Matrix class functions
    Matrix transpose() const;

    float at(int i, int j) const;
    void set(int i, int j, float val);
    std::vector<float> getrow(int i) const;
    std::vector<float> getcol(int j) const;
    void setrow(int i, const std::vector<float> &row);
    void setcol(int j, const std::vector<float> &col);
    Matrix getblock(int row1, int row2, int col1, int col2) const;
    void setblock(int row1, int row2, int col1, int col2, const Matrix &block);


    ~Matrix();
};

float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2);
Matrix matmul(const Matrix &mata, const Matrix &matb);
Matrix eyen(int n);
Matrix matcat(const Matrix &mata, const Matrix &matb, int axis);
float trace(const Matrix &mat);
Matrix inverse(const Matrix &mat);
