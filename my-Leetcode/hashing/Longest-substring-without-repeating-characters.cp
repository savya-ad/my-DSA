Problem link:- https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length=0;
        unordered_map<char, int> umap;
        int prev=-1;
        int temp=0;
        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end() and umap[s[i]]>prev ){
                length=max(temp, length);
                prev=umap[s[i]];
                umap.erase(s[i]);
                temp=i-prev;
            }
            else
                temp++;
            
            umap[s[i]]=i;
        }
        length=max(temp,length);
        return length;
    }
};



// "dvdf"
// "abcabcbb"
// "bbbbb"
// "pwwkew"
