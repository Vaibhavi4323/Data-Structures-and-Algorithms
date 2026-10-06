class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity){
        int usedDays = 1;
        int load = 0;
        for(int weight: weights){
            if(load+weight > capacity){
                usedDays++;
                load = weight;
            }else{
                load+=weight;
            }
        }
        return usedDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(canShip(weights,days,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};