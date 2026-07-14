#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, int> mapper;

        for(auto& str : strs) {
            string curr_str = str;
            sort(str.begin(), str.end());

            if(mapper.find(str) != mapper.end()) {
                res[mapper[str]].push_back(curr_str);
            } else {
                res.push_back({curr_str});
                mapper[str] = res.size()-1;
            }
        }
        return res;
    }
};
