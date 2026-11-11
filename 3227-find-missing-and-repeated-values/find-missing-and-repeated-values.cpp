class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        int s=n*n;
        vector<int> freq(s+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                freq[grid[i][j]]++;
            }
        }
        int repeated = -1, missing = -1;
        for(int i=0;i<=s;i++){
            if(freq[i]==2){
                 repeated=i;

            }
            if(freq[i]==0){
                 missing =i;
            }
        }
        return {repeated, missing};
    }
};