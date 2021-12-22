// Problem link:- https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> vect;
        if(arr.size()<3)
            return vect;
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        for(int i=0;i<arr.size();i++){
            int sum=-1*arr[i];
            if(sum<0 )   return vect;
            if(i and arr[i]==arr[i-1])  continue;
            
            int l=i+1, r=n-1;
            while(l<r){
                int temp=arr[l]+arr[r];
                if(temp<sum)
                    l++;
                else if(temp>sum)
                    r--;
                else{
                    vect.push_back({arr[i], arr[l], arr[r]});
                    while(l<r and arr[l]==arr[++l]);
                    while(r>l and arr[r]==arr[--r]);
                }
            }
        }

        return vect;
    }
};
