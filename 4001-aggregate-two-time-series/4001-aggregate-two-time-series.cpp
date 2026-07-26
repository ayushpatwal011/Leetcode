class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        int n1 = series1.size();
        int n2 = series2.size();
        int i1 = 0;
        int i2 = 0;
        vector<vector<int>> ans;
        while (i1 < n1 && i2 < n2) {
            if((series1[i1][0]) == (series2[i2][0])){
                int timestamp = series1[i1][0];
                int sum = series1[i1][1] + series2[i2][1];
                ans.push_back({timestamp,sum});
                i1++;
                i2++;
            }
            else if (series1[i1][0] < series2[i2][0]) {
                int timestamp = series1[i1][0];
                int sum = series1[i1][1] + series2[i2][1];
                ans.push_back({timestamp,sum});
                i1++;
            } else {
                int timestamp = series2[i2][0];
                int sum = series2[i2][1] + series1[i1][1];
                ans.push_back({timestamp,sum});
                i2++;
            }
        }
        while(i1 < n1){
            ans.push_back({series1[i1][0],series1[i1][1]});
            i1++;
        }
        while(i2 < n2){
             ans.push_back({series2[i2][0],series2[i2][1]});
            i2++;
        }
        return ans;
    }
};