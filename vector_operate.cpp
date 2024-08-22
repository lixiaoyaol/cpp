#include "vector_operate.hpp"

void print_vec(std::vector<float> &vec) {
    for(int i=0; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

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

std::vector<float> vec_scalar_multiply(const std::vector<float> &vec, float a) {
    std::vector<float> new_vec(vec.size());
    for(int i=0; i<vec.size(); i++) {
        new_vec[i] = vec[i] * a;
    }
    return new_vec;
}

std::vector<float> vec_scalar_multiply(float a, const std::vector<float> &vec) {
    std::vector<float> new_vec(vec.size());
    for(int i=0; i<vec.size(); i++) {
        new_vec[i] = vec[i] * a;
    }
    return new_vec;
}

std::vector<float> vec_sub(const std::vector<float> &vec1, const std::vector<float> &vec2) {
    if(vec1.size() != vec2.size()) {
        throw std::invalid_argument("Vector dimensions do not match for vector substraction");
    }
    std::vector<float> new_vec(vec1.size());
    for(int i=0; i<vec1.size(); i++) {
        new_vec[i] = vec1[i] - vec2[i];
    }
    return new_vec;
}