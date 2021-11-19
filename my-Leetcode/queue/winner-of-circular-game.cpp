// Problem link:- https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>  q;
        for(int i=0;i<n;i++){
            q.push(i+1);
        }
        int count=1;
        while(q.size()!=1){
            if(count!=k){
                int temp=q.front();
                q.pop();
                q.push(temp);
                count+=1;
            }
            else{
                q.pop();
                count=1;
            }
        }
        return q.front();
    }
};
