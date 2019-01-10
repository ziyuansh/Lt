//
//  main.cpp
//  leetcode79
//
//  Created by ziyuan Shan on 1/9/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void dfs(vector<vector<char>>& board, string word, int s, int x, int y, bool& ans){
    if(s == word.size()){
        ans = true;
        return;
    }
    int flag = 0;
    if(x+1 < board.size() && board[x+1][y] == word[s]){
        dfs(board, word, s + 1, x+1, y, ans);
        flag = 1;
        if(ans) return;
    }
    if(x-1 >= 0 && board[x-1][y] == word[s]){
        dfs(board, word, s + 1, x-1, y, ans);
        flag = 1;
        if(ans) return ;
    }
    if(y+1 < board[0].size()&&board[x][y+1] == word[s]){
        dfs(board, word, s + 1, x, y+1, ans);
        flag = 1;
        if(ans) return ;
    }
    if(y>0 && board[x][y-1] == word[s]){
        dfs(board, word, s + 1, x, y-1, ans);
        flag = 1;
        if(ans) return ;
    }
    if(!flag){
        ans = false;
    }
    return;
}
bool exist(vector<vector<char>>& board, string word) {
    int h = board.size();
    int w = board[0].size();
    bool ans = false;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(board[i][j] == word[0]){
                if(word.length() == 1) return true;
                dfs(board, word, 1, i, j, ans);
            }
            if(ans) return true;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
//    ,{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    cout<< exist(board, word);
    std::cout << "Hello, World!\n";
    return 0;
}
