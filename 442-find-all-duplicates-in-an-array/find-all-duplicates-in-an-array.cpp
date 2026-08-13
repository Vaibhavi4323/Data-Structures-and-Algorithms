class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            int index = abs(nums[i]) - 1;

            if (nums[index] < 0) {

                // We have seen this number before

                ans.push_back(abs(nums[i]));

            } else {

                // Mark this number as visited

                nums[index] = -nums[index];

            }

        }

        return ans;
    }
};