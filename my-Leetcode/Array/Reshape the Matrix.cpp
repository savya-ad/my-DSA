// Problemlink:- https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> arr;
        int m=mat.size();
        int n=mat[0].size();
        if(m*n!=r*c)
            return mat;
        
        vector<int> mat_cp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat_cp.push_back(mat[i][j]);
            }
        }
        int k=0;
        for(int i=0;i<r;i++){
            vector<int> temp;
            for(int j=0;j<c;j++){
                temp.push_back(mat_cp[k++]);
            }
            arr.push_back(temp);
        }
        return arr;
    }
};
