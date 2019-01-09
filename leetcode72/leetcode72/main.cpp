//
//  main.cpp
//  leetcode72
//
//  Created by ziyuan Shan on 1/8/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minDistance(string word1, string word2) {
    if(word1.length()==0) return word2.length();
    if(word2.length()==0) return word1.length();
    vector<vector<int>> ans(word1.length(), vector<int>(word2.length(), 0));
    ans[0][0] = word1[0]==word2[0]? 0 : 1;
    int flag = 0;
    for(int i = 1; i < word1.length(); i++){
        if(word2[0] == word1[i] && !flag) {
            ans[i][0] = ans[i-1][0];
            flag = 1;
        }
        else{
            ans[i][0] = ans[i-1][0] + 1;
        }
    }
    flag = 0;
    for(int i = 1; i < word2.length(); i++){
        if(word1[0] == word2[i]&& !flag) {
            ans[0][i] = ans[0][i-1];
            flag = 1;
        }
        else{
            ans[0][i] = ans[0][i - 1] + 1;
        }
    }
    for(int i = 1; i < word1.length(); i++){
        for(int j = 1; j < word2.length(); j++){
            if(word1[i] == word2[j]){
                ans[i][j] = min(ans[i-1][j-1], ans[i-1][j] + 1);
                ans[i][j] = min(ans[i][j],  ans[i][j-1] + 1);
            }
            else{
                ans[i][j] = min(ans[i-1][j-1] + 1, ans[i-1][j] + 1);
                ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
            }
        }
    }
    return ans[word1.length()-1][word2.length()-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<minDistance("horsro", "ro");
    std::cout << "Hello, World!\n";
    return 0;
}
