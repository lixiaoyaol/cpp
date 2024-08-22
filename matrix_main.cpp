/*Author: libofeng, Mail: bf_li@qq.com
 *All rights reserved*/

#include<iostream>
#include<vector>
#include<string>
#include "matrix_operate.hpp"
#include "vector_operate.hpp"

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
    // Matrix mat11 = mat1;
    // cout << mat11 << endl;

    // Matrix mat = eyen(5);
    // cout << mat << endl;
    // cout << mat1 << endl;
    // cout << mat2 << endl;
    // cout << matcat(mat1, mat2, 0) << endl;
    // cout << matcat(mat1, mat2, 1) << endl;
    // vector<float> data={3, 2, 1, -10, -3, 0, -7, -5, -3};
    // Matrix mat(3, 3, data);
    // cout << trace(mat);
    // cout << mat(1,1) << endl;

    // cout << inverse(mat) << endl;
    // cout << mat.at(1, 1) << endl;
    // mat.set(1,1, 2.5);
    // cout << mat.at(1, 1) << endl;
    // cout << mat.getrow(0)[0] << " " << mat.getrow(0)[1] << endl;
    // cout << mat.getrow(1)[0] << " " << mat.getrow(1)[1] <<endl;
    // cout << mat.getcol(0)[0] << " " << mat.getcol(0)[1] << endl;
    // cout << mat.getcol(1)[0] << " " << mat.getcol(1)[1] <<endl;

    // cout << endl;

    // vector<float> row = {8, 8};
    // mat.setrow(0, row);
    // cout << mat.getrow(0)[0] << " " << mat.getrow(0)[1] << endl;

    // vector<float> col = {9, 9};
    // mat.setcol(0, col);
    // cout << mat.getcol(0)[0] << " " << mat.getcol(0)[1] << endl;

    vector<int> data={3, 2, 1, -10, -3, 0, -7, -5, -3};

    cout << data << endl;


    return 0;
}
