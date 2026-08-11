class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        // Prefix sum 0 occurs before the array starts
        firstIndex[0] = -1;
        int sum = 0;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1 and 1 as +1
            if (nums[i] == 0)
                sum--;
            else
                sum++;
            // If we've seen this sum before
            if (firstIndex.find(sum) != firstIndex.end()) {
                maxLength = max(maxLength, i - firstIndex[sum]);
            }
            else {
                // Store only the first occurrence
                firstIndex[sum] = i;
            }
        }
        return maxLength;
    }
};