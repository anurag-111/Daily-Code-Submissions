class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // If no rotations are done
        if(nums[low] <= nums[high]) {
            return nums[0];
        }
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            } else if(nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if(nums[low] <= nums[mid]) {
                low = mid + 1;
            } else if(nums[mid] <= nums[high]) {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};