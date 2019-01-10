//
//  main.cpp
//  leetcode73
//
//  Created by ziyuan Shan on 1/8/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int h = matrix.size();
    int w = matrix[0].size();
    vector<int> height;
    vector<int> width;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(matrix[i][j] == 0){
                height.push_back(i);
                width.push_back(j);
            }
        }
    }
    for(int i = 0; i < height.size(); i++){
        for(int j = 0; j < w; j++){
            matrix[height[i]][j] = 0;
        }
    }
    for(int i = 0; i < width.size(); i++){
        for(int j = 0; j < h; j++){
            matrix[j][width[i]] = 0;
        }
    }
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix{{5}, {2}, {0}};
    setZeroes(matrix);
    std::cout << "Hello, World!\n";
    return 0;
}
