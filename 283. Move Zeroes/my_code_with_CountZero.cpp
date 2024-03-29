class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		int CountZero = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				nums[i - CountZero] = nums[i];

			}
			else {
				++CountZero;
			}
		}

		for (int i = nums.size() - CountZero; i < nums.size(); ++i) {
			nums[i] = 0;
		}
	}
};
