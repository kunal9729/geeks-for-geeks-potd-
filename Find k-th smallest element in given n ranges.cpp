//User function Template for C++

class Solution
{
public:
    vector<int> kthSmallestNum(int n, vector<vector<int>> &range, int q, vector<int> queries)
    {
        sort(range.begin(), range.end());

        vector<int> skip(n, 0), count(n, 0);

        if (range[0][0] > 1)
            skip[0] = range[0][0] - 1;

        count[0] = range[0][1] - range[0][0] + 1;

        for (int i = 1; i < n; i++)
        {
            int gap = range[i][0] - range[i - 1][1] - 1;
            skip[i] = skip[i - 1] + max(0, gap);

            count[i] = count[i - 1] + ((range[i - 1][1] >= range[i][0]) ? (range[i][1] - range[i - 1][1]) : (range[i][1] - range[i][0])) + 1;
        }

        vector<int> ans(q, -1);

        for (int i = 0; i < q; i++)
        {
            int idx = -1;

            for (int j = 0; j < n; j++)
            {
                if (queries[i] <= count[j])
                {
                    idx = j;
                    break;
                }
            }

            if (idx != -1)
            {
                ans[i] = skip[idx] + queries[i];
            }
        }

        return ans;
    }
};
