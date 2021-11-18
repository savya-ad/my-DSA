// problem link -: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty())
                st.push(s[i]);
            else{
                if(s[i]==st.top())
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
