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

    friend std::ostream& operator<<(std::ostream& os, const Matrix &mat);

    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(float a) const;
    friend Matrix operator*(float a, const Matrix &mat);
    Matrix operator*(const Matrix &mat) const;
    float& operator() (int i, int j);

    Matrix transpose() const;

    ~Matrix();
};

float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2);
Matrix matmul(const Matrix &mata, const Matrix &matb);
Matrix eyen(int n);
Matrix matcat(const Matrix &mata, const Matrix &matb, int axis);
float trace(const Matrix &mat);
Matrix inverse(const Matrix &mat);
