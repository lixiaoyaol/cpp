#pragma once

#include<vector>

class Matrix
{
public:
    int rows;
    int cols;
    std::vector<float> data;

public:
    Matrix(int rows, int cols, const std::vector<float> &data);

    friend std::ostream& operator<<(std::ostream& os, const Matrix mat);

    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(float a) const;
    friend Matrix operator*(float a, const Matrix &mat);
    Matrix operator*(const Matrix &mat) const;

    ~Matrix();
};

float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2);
Matrix matmul(const Matrix &mata, const Matrix &matb);