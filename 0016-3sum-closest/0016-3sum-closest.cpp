class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Initialize variables to track the minimum difference and the closest sum
        int minDiff = INT_MAX;
        int closestSum = 0;

        // Sort the input array in ascending order
        sort(nums.begin(), nums.end());

        // Loop through the array, considering each element as the first element in a potential triplet
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1; // Index of the second element
            int right = nums.size() - 1; // Index of the third element

            // Continue the loop until left and right pointers meet
            while (left < right) {
                // Calculate the sum of the current triplet
                int currSum = nums[i] + nums[left] + nums[right];
                // Calculate the difference between the current sum and the target
                int curDiff = target - currSum;

                // If the difference is zero, then the sum is equal to the target, return it
                if (curDiff == 0) {
                    return target;
                }

                // Update the closest sum and minimum difference if necessary
                if (abs(curDiff) < abs(minDiff)) {
                    minDiff = curDiff;
                    closestSum = currSum;
                }

                // Adjust the pointers based on the comparison with the target
                if (currSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closestSum;
    }
};
