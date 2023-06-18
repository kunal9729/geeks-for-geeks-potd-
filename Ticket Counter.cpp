
class Solution {
public:
  int distributeTicket(int N, int K) {
    int cut = N / (2 * K);
    int left = 1 + (cut * K);
    int right = N - (cut * K);

    return (right < left) ? left : (right - left + 1 <= K) ? right : (left + K);
  }
};
