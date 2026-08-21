class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n <= 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, k = 0, l = 0;
        for (i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            } else {
                for (j = i + 1; j < n; j++) {
                    if (j > i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    } else {
                        int k = j + 1, l = n - 1;
                        while (k < l) {
                            long long sum = (long long)nums[i] + nums[j] +
                                            nums[k] + nums[l];
                            if (sum == target) {
                                vector<int> temp(
                                    {nums[i], nums[j], nums[k], nums[l]});
                                result.push_back(temp);
                                while (k < l && nums[k] == nums[k + 1]) {
                                    k++;
                                }
                                while (k < l && nums[l] == nums[l - 1]) {
                                    l--;
                                }
                                k++;
                                l--;
                            } else if (sum < target) {
                                k++;
                            } else {
                                l--;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};