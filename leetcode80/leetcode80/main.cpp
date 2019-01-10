//
//  main.cpp
//  leetcode80
//
//  Created by ziyuan Shan on 1/9/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
//    int c = 0;
//    int de = 0;
//    for(int i = 0; i < nums.size()-1; i++){
//        if(nums[i] == nums[i+1] && !c){
//            c++;
//        }
//        else if(nums[i] == nums[i+1] && c != 0){
//            vector<int>::iterator it;
//            it = find(nums.begin(), nums.end(), nums[i]);
//            nums.erase(it);
//            i--;
//        }
//        else{
//            c = 0;
//        }
//
//    }
//
//    return nums.size();
    int i = 0;
//    for (int n : nums)
//        if (i < 2 || n > nums[i-2])
//            nums[i++] = n;
//    int i = 0;
    for(int j = 0; j < nums.size(); j++){
        if(j < 2 || nums[j] > nums[i-2]){
            nums[i++] = nums[j];
        }
    }
    return i;
    return i;
}
int main(int argc, const char * argv[]) {
    vector<int> a{1,1,1,2,2,3,};
//    int i = 0;
//    a[i++] = 100;
//    cout<<a[0]<<"  " << a[1];
    cout<<removeDuplicates(a);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
