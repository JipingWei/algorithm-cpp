// Created by Freelf at 2024/02/19 19:44
// leetgo: 1.4.1
// https://leetcode.cn/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 用hash表来记录边界
        unordered_map<int, int> map;
        int result = 0;
        for (int num : nums) {
            if (map.find(num) == map.end()) {
                auto leftIt = map.find(num - 1);
                auto rightIt = map.find(num + 1);
                int left = leftIt == map.end() ? 0 : leftIt->second;
                int right = rightIt == map.end() ? 0 : rightIt->second;

                map[num] = 1;
                int length = left + right + 1;
                map[num - left] = length;
                map[num + right] = length;
                result = max(result, length);
            }
        }
        return result;
        // 用hash表去重，然后挨个寻找边界
//        unordered_set<int> num_set(nums.begin(),nums.end());
//        int result = 0;
//        for (int num : num_set) {
//            if (!num_set.count(num - 1)) {
//                int current_num = num;
//                int current_consecutive = 1;
//                while (num_set.count(current_num + 1)) {
//                    current_num++;
//                    current_consecutive++;
//                }
//                result = max(result, current_consecutive);
//            }
//        }
//        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->longestConsecutive(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
