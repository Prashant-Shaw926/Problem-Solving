class Solution {
	public:
	int maxSubarraySum(vector<int>& arr, int k) {
		// code here
		int n = arr.size();
		int i = 0, j = k;
		int sum = 0, max = INT_MIN;
		for (i = 0; i<k; i++) {
			sum += arr[i];
		}
		max = sum;
		i = 0;
		while (j<n) {
			sum = (sum + arr[j]) - arr[i];
			if (sum > max) {
				max = sum;
			}
			i++; j++;
		}
		
		return max;
	}
};
