#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isanagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        if(s_size != t_size) return false;

        unordered_map<char, int> comp;

        for(char c : s) {
            comp[c]++;
        }

        for(char c : t) {
            comp[c]--;
            if(comp[c] == 0) comp.erase(c);
        }
       
        if(comp.empty()) return true;
        return false;
    }
};
        
