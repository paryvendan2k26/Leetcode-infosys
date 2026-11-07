class Solution {
public:

    int rev(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=1+rev(s1, s2, ind1-1, ind2-1, dp);
        }
        return dp[ind1][ind2]= max(rev(s1, s2, ind1-1, ind2, dp), rev(s1, s2, ind1, ind2-1, dp));

    }

    int minInsertions(string s1) {
        int n=s1.size();
        string s2= s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int lcs= rev(s1, s2, n-1, n-1, dp);

        return n-lcs;
    }
};