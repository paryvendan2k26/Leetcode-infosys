class Solution {
public:
    int fun(string& s1, string& s2, vector<vector<int>>& dp, int ind1, int ind2){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + fun(s1, s2, dp, ind1-1, ind2-1);
        }

        return dp[ind1][ind2] = max(
            fun(s1, s2, dp, ind1-1, ind2),
            fun(s1, s2, dp, ind1, ind2-1)
        );
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return (m+n-(2*fun(word1, word2, dp,n-1,m-1)));
        
    }
};