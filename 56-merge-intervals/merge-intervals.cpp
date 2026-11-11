class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        res.push_back(arr[0]);
        for(int i=1;i<n;i++){
                    int last=res.size()-1;
            if(res[last][1]>= arr[i][0]){
                if(arr[i][1]>=res[last][1])
                res[last][1]=arr[i][1];
                else{
                    continue;
                }
            }else{
                res.push_back(arr[i]);
            }

        }

        return res;
    }
};