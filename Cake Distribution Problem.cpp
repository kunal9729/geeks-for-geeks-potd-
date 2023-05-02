// User function Template for C++
class Solution{
    public:


bool canDistribute(const vector<int>& sweetness, int N, int K, int minSweetness) {
    int count = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += sweetness[i];
        if (sum >= minSweetness) {
            count++;
            sum = 0;
        }
    }
    return count >= K + 1;
}

int maxSweetness(vector<int>& sweetness, int N, int K) {
    int low = *min_element(sweetness.begin(), sweetness.end());
    int high = accumulate(sweetness.begin(), sweetness.end(), 0);
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canDistribute(sweetness, N, K, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}
};
