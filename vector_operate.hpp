#pragma once

#include <iostream>
#include <vector>


void print_vec(std::vector<float> &vec);
float vec_dot(const std::vector<float> &vec1, const std::vector<float> &vec2);
std::vector<float> vec_scalar_multiply(const std::vector<float> &vec, float a);
std::vector<float> vec_scalar_multiply(float a, const std::vector<float> &vec);
std::vector<float> vec_sub(const std::vector<float> &vec1, const std::vector<float> &vec2);