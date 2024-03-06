// Created by Freelf at 2024/02/19 10:51
// leetgo: 1.4.1
// https://leetcode.cn/problems/group-anagrams/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector <vector<string>> groupAnagrams(vector <string> &strs) {
        vector <vector<string>> result;
        map <string, vector<string>> map;
        for (string str: strs) {
            vector<int> vec(26, 0);

            for (auto c: str) {
                vec[c - 'a'] += 1;
            }

            string key = string();
            for (int i = 0; i < vec.size(); ++i) {
                auto value = vec[i];
                if (value > 0) {
                    for (int j = 0; j < value; ++j) {
                        key += static_cast<char>('a' + i);
                    }
                }
            }

            vector <string> values;
            if (map.find(key) != map.end()) {
                values = map[key];
            }
            values.push_back(str);
            map[key] = values;
        }
        for (const auto &pair: map) {
            result.push_back(pair.second);
        }
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> strs;
	LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();
	auto res = obj->groupAnagrams(strs);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
