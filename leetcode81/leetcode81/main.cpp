//
//  main.cpp
//  leetcode81
//
//  Created by ziyuan Shan on 1/10/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0;
    int l = nums.size();
    if(!l) return false;
    if(nums[0] == target) return true;
    int right = l-1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            return true;
        }
        else if(nums[mid] < target){
            if(nums[mid] >= nums[l-1]) left = mid + 1;
            else {
                if(target==nums[l-1]) return true;
                right = mid - 1;
            }
        }
        else{
            if(target == nums[l-1]) return true;
            if(target > nums[l-1]){
                right = mid - 1;
            }
            else{
                if(nums[mid] > nums[l-1]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            
        }
        
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> x{1,3, 1,1,1};
    cout<< search(x, 3);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
