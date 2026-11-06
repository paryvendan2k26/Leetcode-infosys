class Solution {
public:

    int rec(vector<vector<int>>& dp,
            vector<vector<bool>>& vis,
            int i, int j,
            vector<vector<int>>& matrix) {

        int n = matrix.size();

        if(j < 0 || j >= n) return 1e9;

        if(i == 0) return matrix[0][j];

        if(vis[i][j]) return dp[i][j];

        vis[i][j] = true;

        int up = matrix[i][j] + rec(dp, vis, i-1, j, matrix);

        int upleft = matrix[i][j] + rec(dp, vis, i-1, j-1, matrix);

        int upright = matrix[i][j] + rec(dp, vis, i-1, j+1, matrix);

        return dp[i][j] = min({up, upleft, upright});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, rec(dp, vis, n-1, j, matrix));
        }

        return ans;
    }
};