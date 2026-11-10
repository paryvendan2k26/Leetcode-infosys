class Solution {
public:

    int sum(vector<int> &coins, int ind, int amt,vector<vector<int>> &dp){
        if(ind ==0){
            return (amt%coins[0]==0);
        }
        if(dp[ind][amt]!=-1){
            return dp[ind][amt];
        }

        int notpick=sum(coins, ind-1, amt, dp);
        int pick=0;
        if(coins[ind]<=amt) pick= sum(coins, ind, amt-coins[ind], dp);

        return dp[ind][amt]= pick+notpick;
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        return sum(coins, n-1,amt, dp);
    }
};