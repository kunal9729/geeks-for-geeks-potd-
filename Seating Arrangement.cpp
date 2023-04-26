//User function Template for C++

class Solution {
public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (seats[i] == 0 && (i == 0 || seats[i-1] == 0) && (i == m-1 || seats[i+1] == 0)) {
                cnt++;
                i++;
            }
        }
        return cnt >= n;

    }
};
