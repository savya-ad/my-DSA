// Problem link:- https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        arr.push_back({1});
        if(numRows>=2){
            arr.push_back({1,1});
        }
        for(int i=2;i<numRows;i++){
            int size=i;
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i+1;j++){
                if(j==i){
                    temp.push_back(1);
                    continue;
                }
                temp.push_back(arr[size-1][j-1]+arr[size-1][j]);
            }
            arr.push_back(temp);
        }
        return arr;
    }
};
