/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // Step 1: Find the peak index
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int peak = low;
        // Step 2: Search in the increasing half
        low = 0;
        high = peak;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);
            if (value == target) {
                return mid;
            } else if (value < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // Step 3: Search in the decreasing half
        low = peak + 1;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = mountainArr.get(mid);
            if (value == target) {
                return mid;
            } else if (value < target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};