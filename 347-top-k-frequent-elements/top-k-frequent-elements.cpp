class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number

        for (int num : nums) {

            freq[num]++;

        }

        // bucket[i] contains numbers that appear i times

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {

            bucket[count].push_back(num);

        }

        vector<int> ans;

        // Start from highest frequency

        for (int i = bucket.size() - 1; i >= 0; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k) {

                    return ans;

                }

            }

        }

        return ans;
    }
};