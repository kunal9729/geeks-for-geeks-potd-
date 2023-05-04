//User function Template for C++
const int MAXN = 100005;
int dp[MAXN][3];
class Solution{
public:

int maxCoins(int n, vector<vector<int>> ranges) {
    sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    });
    memset(dp, -1, sizeof(dp));
    return fun(ranges, 0, 0);
}

int fun(vector<vector<int>>& ranges, int i, int taken) {
    if (i >= ranges.size() || taken > 1) {
        return 0;
    }
    if (dp[i][taken] != -1) {
        return dp[i][taken];
    }
    int ans = fun(ranges, i+1, taken);
    int new_idx = INT_MAX, l = i+1, r = ranges.size()-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (ranges[mid][0] >= ranges[i][1]) {
            new_idx = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ans = max(ans, fun(ranges, new_idx, taken+1) + ranges[i][2]);
    return dp[i][taken] = ans;
}

};

