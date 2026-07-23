#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> check;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            if(check.empty() || temperatures[check.top()] >= temperatures[i]) {
                check.push(i);
            } else {
                while(!check.empty() && temperatures[check.top()] < temperatures[i]) {
                    int idx = check.top();
                    res[idx] = i - check.top();
                    check.pop();
                }
                check.push(i);
            }
        }

        return res;
    }
};
