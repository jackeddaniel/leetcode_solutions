#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();

        //we build the counter array to keep track of char count in the window
        vector<int> count(26, 0);
        
        int longest = 0;
        int l = 0;
        char max_char = s[l];
        

        for(int r = 0; r < size; r++) {
            if (k == 0) {

            } else {
                char curr_char = s[r];

                if (curr_char == max_char) {
                    count[curr_char - 'A']++;
                } else {
                    k--;
                    longest = max(longest, r - l + 1);
                }
            }

        }
        return longest;
        
    }
};
