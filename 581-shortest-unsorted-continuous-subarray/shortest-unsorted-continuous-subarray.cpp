class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int start = -1, end = -1;
        int i = 0;
        long long max = INT_MIN, min = INT_MAX;

        for (i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                start = i;
                break;
            }
        }

        for (i = n - 1; i >= 1; i--) {
            if (nums[i] < nums[i - 1]) {
                end = i;
                break;
            }
        }

        if (start == -1) {
            return 0;
        }

        for (i = start; i <= end; i++) {
            if (nums[i] > max) {
                max = nums[i];
            } if (nums[i] < min) {
                min = nums[i];
            }
        }

        for (i = 0; i < n; i++) {
            if (nums[i] > min) {
                start = i;
                break;
            }
        }

        for (i = n - 1; i >= 0; i--) {
            if (nums[i] < max) {
                end = i;
                break;
            }
        }

        return (end - start) + 1;
    }
};