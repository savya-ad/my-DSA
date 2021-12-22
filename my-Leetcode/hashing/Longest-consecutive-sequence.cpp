// Problem link:- https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int length=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int start=it;
                int count=1;
                while(st.find(start+1)!=st.end()){
                    start++;
                    count++;
                }
                length=max(length, count);
            }
        }
        return length;
    }
};
