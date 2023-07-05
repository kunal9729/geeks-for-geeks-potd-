class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeros = 0;
        int maxSubarrayLength = 0;

        for (int right = 0; right < n; right++) {
            // Count the number of zeros encountered
            if (nums[right] == 0) {
                zeros++;
            }

            // Adjust the window size to satisfy the condition (at most 1 zero)
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }

            // Update the maximum subarray length
            int currentSubarrayLength = right - left + 1 - zeros;
            maxSubarrayLength = max(maxSubarrayLength, currentSubarrayLength);
        }

        // If the entire array is filled with ones, return n - 1
        if (maxSubarrayLength == n) {
            return maxSubarrayLength - 1;
        }

        return maxSubarrayLength;
    }
};
