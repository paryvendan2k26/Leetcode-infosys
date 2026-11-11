class Solution {
public:

    static bool comp(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        for(int i=0;i<n;i++){
            res.push_back(to_string(nums[i]));
        }

        sort(res.begin(), res.end(), comp);

        if(res[0]=="0") return "0";
        string ans="";
        for(int i=0;i<n;i++){
            ans+=res[i];
        }

        return ans;
    }
};