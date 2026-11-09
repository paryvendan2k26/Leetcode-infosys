class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int c) {
        vector<int> v(1001, 0);

        for(int i = 0; i < trips.size(); i++) {
            int pas = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];

            v[start] += pas;
            v[end] -= pas;
        }

        int cnt = 0;

        for(int i = 0; i <= 1000; i++) {
            cnt += v[i];

            if(cnt > c) {
                return false;
            }
        }

        return true;
    }
};