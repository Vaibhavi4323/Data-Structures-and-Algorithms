class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long currentSum = 0;
        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            }
            else {
                parts++;
                currentSum = num;
            }
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;
        for (int num : nums) {
            high += num;
        }
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                // mid is possible
                high = mid;
            }
            else {
                // mid is too small
                low = mid + 1;
            }
        }
        return low;
    }
};