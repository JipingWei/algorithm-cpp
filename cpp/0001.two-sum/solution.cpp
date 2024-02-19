// Created by Freelf at 2024/02/04 14:36
// leetgo: 1.4.1
// https://leetcode.cn/problems/two-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int wantFind = target - num;
            if (dict.find(wantFind) != dict.end()) {
                return {i, dict[wantFind]};
            } else {
                dict[num] = i;
            }
        }
        return {};
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->twoSum(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
