#include<iostream>
#include<vector>
#include<string>
#include "matrix_operate.hpp"

using namespace std;

int main()
{
    cout << "hello world!" << endl;

    vector<float> data = {1, 2, 3, 4, 5, 6};
    Matrix mat1(2, 3, data);
    mat1.show_data();
    vector<float> data2 = {7, 8, 9, 10, 11, 12};
    Matrix mat2(2, 3, data2);
    mat2.show_data();
    Matrix mat3 = mat1 + mat2;
    mat3.show_data();
    Matrix mat4 = mat1 - mat2;
    mat4.show_data();
    Matrix mat5 = mat1 * 2;
    mat5.show_data();
    Matrix mat10 = 2 * mat1;
    mat10.show_data();
    Matrix mat6 = mat1 * mat2;
    mat6.show_data();

    Matrix mat7(2, 3, data);
    mat1.show_data();
    Matrix mat8(3, 2, data2);

    Matrix mat9 = matmul(mat7, mat8);
    mat9.show_data();

    return 0;
}
