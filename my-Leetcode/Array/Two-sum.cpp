// Problem link:- https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        unordered_map<int, int> umap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(umap.find(req)==umap.end()){
                umap[nums[i]]=i;
            }
            else{
                arr.push_back(umap[req]);
                arr.push_back(i);
                break;
            }
        }
        return arr;
    }
};
