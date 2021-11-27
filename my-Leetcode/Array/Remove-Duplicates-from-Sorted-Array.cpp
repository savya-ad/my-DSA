// Problem link:- https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
            return 0;
        int j=0;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[j]){
                j++;
                arr[j]=arr[i];
            }
        }
        return j+1;
    }
};
