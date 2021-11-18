// Problem link-: https://leetcode.com/problems/backspace-string-compare/

    class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st.empty())
                    st.pop();
                else
                    continue;
            }
            else
                st.push(s[i]);
        }
        string nt="";
        while(!st.empty()){
            nt+=st.top();
            st.pop();
        }
        
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st.empty())
                    st.pop();
                else
                    continue;
            }
            else{
                st.push(t[i]);
            }
        }
        string nr="";
        while(!st.empty()){
            nr+=st.top();
            st.pop();
        }
        return nr==nt;
    }
};
