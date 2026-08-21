class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int sum = 0;
        int n = numbers.size();
        int x = 0, y = n - 1;
        while (x < y) {
            sum = numbers[x] + numbers[y];
            if (sum == target) {
                ans.push_back(x + 1);
                ans.push_back(y + 1);
                break;
            } else if (sum > target) {
                y--;
            } else {
                x++;
            }
        }
        return ans;
    }
};