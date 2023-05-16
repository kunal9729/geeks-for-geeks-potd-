class Solution{
    public:
    int cuts(string s){
        
    vector<char> c(s.begin(), s.end());
    int length = c.size();
    vector<int> dp(length + 1, 0);

    for (int i = 1; i <= length; i++)
    {
        int index = i - 1;
        if (c[index] == '0')
        {
            dp[i] = -1;
        }
        else
        {
            dp[i] = -1;
            int minCuts = 1000;
            long long count = 0;

            for (int j = 0; j < i; j++)
            {
                if (c[index - j] == '1')
                {
                    count += calculateNum(j);

                    if (check(count) && dp[index - j] != -1)
                    {
                        int currentCuts = 1 + dp[index - j];
                        minCuts = (currentCuts < minCuts) ? currentCuts : minCuts;
                    }
                }
            }

            if (minCuts != 1000)
            {
                dp[i] = minCuts;
            }
        }
    }

    return dp[length];
}

long long calculateNum(int y)
{
    if (y == 0)
    {
        return 1;
    }

    long long x = 2;
    for (int i = 1; i < y; i++)
    {
        x = x << 1;
    }

    return x;
}

bool check(long long n)
{
    if (n == 0)
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }

    if (n % 5 != 0)
    {
        return false;
    }
    else
    {
        return check(n / 5);
    }
}
        
};
