// Problem link:- https://leetcode.com/problems/find-peak-element/submissions/

// O(log n) solution--
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return 0;
        }
        if(n>1){
            if(arr[0]>arr[1])   return 0;
        }
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1]){
                low=mid;
                break;
            }
            if(arr[mid+1]>arr[mid])
                low=mid+1;
            else
                high= mid;
            
        }
        return low;
    }
};




// O(n) solution--
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        if(n==1)
            return 0;
        
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i+1] and arr[i]>arr[i-1])
                return i;
        
        }
        if(arr[0]>arr[1])
            return 0;
        
        return n-1;
    }
};
