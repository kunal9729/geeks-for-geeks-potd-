
class Solution {
public:
  long long maxDiamonds(int A[], int N, int K) {
    std::priority_queue<int> pq(A, A + N);

    long long ans = 0;

    while (K-- and !pq.empty()) {
      int cur = pq.top();
      pq.pop();

      ans += cur;

      if (cur > 1)
        pq.push(cur / 2);
    }

    return ans;
  }
};
