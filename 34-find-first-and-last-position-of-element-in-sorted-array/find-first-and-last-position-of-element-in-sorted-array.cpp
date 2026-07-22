class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int start = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target){
                start = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return start;
    }
    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int end = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]== target){
                end = mid;
                low = mid +1;
            }else if (target< nums[mid]){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return end;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        if(lb == n || nums[lb] != target) return {-1, -1};
        return {lb,upperBound(nums,target)};
    }
};