// Problem link-:  https://leetcode.com/problems/number-of-visible-people-in-a-queue/

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        vector<int> vect(n,0);
        st.push(heights[n-1]);
        for(int i=n-2;i>=0;i--){
            int curr=heights[i];
            int count=0;
            while(!st.empty()&&st.top()<curr){
                st.pop();
                count++;
            }
            vect[i]=count;
            vect[i]+=(st.empty()?0:1);
            st.push(heights[i]);
        }
        return vect;
    }
};
