class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;

        int i = 0;

        int patches = 0;

        int size = nums.size();

        while (miss <= n) {

            if (i < size && nums[i] <= miss) {

                // Extend the representable range

                miss += nums[i];

                i++;

            } else {

                // Patch the missing number

                miss += miss;

                patches++;

            }

        }

        return patches;
    }
};