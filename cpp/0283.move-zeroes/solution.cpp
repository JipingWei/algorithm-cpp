// Created by Freelf at 2024/02/20 16:55
// leetgo: 1.4.1
// https://leetcode.cn/problems/move-zeroes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = 0;
                nums[j++] = temp;
            }
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->moveZeroes(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
