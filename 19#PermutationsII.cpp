/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output: [[1,1,2], [1,2,1], [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

void PermutationsII(vector<int> nums, int i, int j, vector<vector<int>>& ans){
    if (i == j-1) {
        ans.push_back(nums);
        return;
    }
    for(int k = i; k < j; k++) {
        if (i != k && nums[i] == nums[k]) continue;
        swap(nums[i], nums[k]);
        PermutationsII(nums, i+1, j, ans);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;i++){
        int tp;
        cin>>tp;
        nums.push_back(tp);
    }

    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    PermutationsII(nums, 0, nums.size(), ans);
    
    for(auto num : ans){
        for(auto n: num){
            cout<<n<<" ";
        }
        cout<<"\n";
    }
    return 0;
}