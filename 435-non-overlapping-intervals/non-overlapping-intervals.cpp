class Solution {
public:

   static bool comp(vector<int> &val1, vector<int> &val2){
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);

        int cnt=1;
        int lastendtime=arr[0][1];

        for(int i=1;i<n;i++){
            if(arr[i][0]>=lastendtime){
                cnt++;
                lastendtime=arr[i][1];
            }
        }

        return n-cnt;
        
    }
};