#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> t(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int i = n;
        int j = m;

        string scs = "";

        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                cout<<str1[i-1]<<endl;
                scs.push_back(str1[i-1]);
                i--;
                j--;
            } else {
                if (t[i-1][j] > t[i][j-1]) {
                    scs.push_back(str1[i-1]);
                    i--;
                } else {
                    scs.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while (i > 0) {
            scs.push_back(str1[i-1]);
            i--;
        }
        while (j > 0) {
            scs.push_back(str2[j-1]);
            j--;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
};
