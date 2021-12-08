// Problrm link:- https://leetcode.com/problems/house-robber/

class Solution {
public:
    int solve(vector<int>&arr, int start,vector<int> &dp){
        if(start>=arr.size())
            return 0;
        if(dp[start]!=-1)
            return dp[start];
        int curr=arr[start]+solve(arr, start+2,dp);
        int next=solve(arr,start+1,dp);
        
        dp[start]=max(curr, next);
        return dp[start];
    }
    int rob(vector<int>& arr) {
        vector<int> dp(arr.size(),-1);
        return solve(arr,0,dp);
    }
};
