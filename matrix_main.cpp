/*Author: libofeng, Mail: bf_li@qq.com
 *All rights reserved*/

#include<iostream>
#include<vector>
#include<string>
#include "matrix_operate.hpp"

using namespace std;

int main()
{
    cout << "hello world!" << endl;

    // vector<float> data = {1, 2, 3, 4, 5, 6};
    // Matrix mat1(2, 3, data);
    // vector<float> data2 = {7, 8, 9, 10, 11, 12};
    // Matrix mat2(2, 3, data2);
    // Matrix mat3 = mat1 + mat2;
    // Matrix mat4 = mat1 - mat2;
    // Matrix mat5 = mat1 * 2;
    // Matrix mat10 = 2 * mat1;
    // Matrix mat6 = mat1 * mat2;

    // Matrix mat7(2, 3, data);
    // Matrix mat8(3, 2, data2);

    // Matrix mat9 = matmul(mat7, mat8);

    // cout << mat9 << endl;
    // cout << mat9.transpose() << endl;
    // cout << mat1 << endl;
    // cout << mat1.transpose() << endl;
    // cout << mat2 << endl;
    // cout << mat2.transpose() << endl;
    Matrix mat11 = mat1;
    cout << mat11 << endl;

    return 0;
}
