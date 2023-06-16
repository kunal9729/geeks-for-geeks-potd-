
class Solution {
public:
    long long minTime(int numLocations, vector<int> &locations, vector<int> &types) {
        map<int, vector<int>> typeMap;

        for (int i = 0; i < numLocations; i++) {
            int currentType = types[i];
            if (typeMap.find(currentType) != typeMap.end()) {
                typeMap[currentType][0] = min(typeMap[currentType][0], locations[i]);
                typeMap[currentType][1] = max(typeMap[currentType][1], locations[i]);
            }
            else {
                typeMap[currentType].push_back(locations[i]);
                typeMap[currentType].push_back(locations[i]);
            }
        }

        vector<vector<int>> typeRanges;
        vector<int> zeroRange = {0, 0};
        typeRanges.emplace_back(zeroRange);

        for (auto entry : typeMap) {
            typeRanges.emplace_back(entry.second);
        }

        typeRanges.emplace_back(zeroRange);

        int numTypes = typeRanges.size();

        vector<vector<long long>> dp(numTypes, vector<long long>(2, 0));

        for (int i = 1; i < numTypes; i++) {
            // Taking the minimum of current type's minimum and last type's minimum
            dp[i][0] = dp[i - 1][0] + abs(typeRanges[i - 1][1] - typeRanges[i][0]) + abs(typeRanges[i][0] - typeRanges[i][1]);

            // Taking the minimum of current type's minimum and last type's maximum
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(typeRanges[i - 1][0] - typeRanges[i][0]) + abs(typeRanges[i][1] - typeRanges[i][0]));

            // Taking the minimum of current type's maximum and last type's minimum
            dp[i][1] = dp[i - 1][0] + abs(typeRanges[i][1] - typeRanges[i - 1][1]) + abs(typeRanges[i][0] - typeRanges[i][1]);

            // Taking the minimum of current type's maximum and last type's maximum
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(typeRanges[i - 1][0] - typeRanges[i][1]) + abs(typeRanges[i][0] - typeRanges[i][1]));
        }

        return dp[numTypes - 1][1];
    }
};
