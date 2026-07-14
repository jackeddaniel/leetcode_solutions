#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> check;
        
        int size = s.size();
        if(size == 0) return 0;
        int l = 0;
        check.insert(s[l]);

        int r = 1;

        int max_str = int(check.size());

        while(r < size) {
            if (check.find(s[r]) != check.end()) {
                while(s[l] != s[r]) {
                    check.erase(s[l]);
                    l++;
                }
                check.erase(s[l]);
                l++;
            } else {
                check.insert(s[r]);
                max_str = max(max_str, int(check.size()));
                r++;
            }
        }
       return max_str; 
    }
};
