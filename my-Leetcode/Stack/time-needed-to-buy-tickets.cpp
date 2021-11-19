// Problem link:- https://leetcode.com/problems/time-needed-to-buy-tickets/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0;
        int n=tickets.size();
        int sum=0;
        while(i<n){
            if(i<=k)
                sum+=min(tickets[i],tickets[k]);
            else
                sum+=min(tickets[i],tickets[k]-1);
            i++;
        }
        return sum;
    }
};
