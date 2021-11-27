// Problem link:- https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n=arr.size();
        if(n==0)
            return 0;
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=val){
                arr[j]=arr[i];
                j++;
            }
        }
        return j;
    }
};
