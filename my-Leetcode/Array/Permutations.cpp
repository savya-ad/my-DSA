// Problem link:- https://leetcode.com/problems/permutations/
  

class Solution {
    vector<vector<int>> arr;
public:
    void permute(vector<int> &nums, int l, int r){
        if(l==r){
            arr.push_back(nums);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            permute(nums, l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, 0,nums.size()-1);
        return arr;
    }
};
