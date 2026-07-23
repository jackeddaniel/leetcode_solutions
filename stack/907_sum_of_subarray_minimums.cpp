#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        
        
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

      
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
           
            long long count = (long long)left[i] * right[i];
            
            totalSum = (totalSum + count * arr[i]) % MOD;
        }

        return totalSum;
    }
};
