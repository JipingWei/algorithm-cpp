// Created by Freelf at 2024/02/20 16:57
// leetgo: 1.4.1
// https://leetcode.cn/problems/container-with-most-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left != right) {
            int leftHeight = height[left];
            int rightHeight = height[right];
            maxArea = max(maxArea, (right - left) * min(leftHeight, rightHeight));
            if (leftHeight > rightHeight) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> height;
	LeetCodeIO::scan(cin, height);

	Solution *obj = new Solution();
	auto res = obj->maxArea(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
