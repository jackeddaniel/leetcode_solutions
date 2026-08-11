#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
// We have to basically build a mountain 
// every element should have heights[i] <= maxHeights[i]
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<int> heights(n, 0);

        vector<int> next_small(n, -1);
        vector<int> next_big(n, -1);

        vector<int> prev_small(n, -1);
        vector<int> prev_big(n, -1);

        stack<int> big_st;
        stack<int> small_st;

        //we compute next smaller and bigger
        for(int i = 0; i < n; i++) {
            //next smaller
            while(maxHeights[small_st.top()] > maxHeights[i]) {
                next_small[small_st.top()] = i;
                small_st.pop();
            }

            small_st.push(i);

            //next larger
            while(maxHeights[big_st.top()] < maxHeights[i]) {
                next_big[big_st.top()] = i;
                big_st.pop();
            }

            big_st.push(i);
        }

        while(!big_st.empty()) big_st.pop();
        while(!small_st.empty()) small_st.pop();
        
        //we compute prev smaller and bigger
        for(int i = n-1; i > -1; i--) {
            //next smaller
            while(maxHeights[small_st.top()] > maxHeights[i]) {
                prev_small[small_st.top()] = i;
                small_st.pop();
            }

            small_st.push(i);

            //next larger
            while(maxHeights[big_st.top()] < maxHeights[i]) {
                prev_big[big_st.top()] = i;
                big_st.pop();
            }

            big_st.push(i);
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            //if both prev_big and next_big are -1
            if(prev_big[i] == -1 && next_big[i] == -1) {
                //this is the peak
                heights[i] = maxHeights[i];
                res += heights[i];
                continue;
            }
            //if both prev_small are next_small are -1
            if(prev_small[i] == -1 && next_small[i] == -1) {
                heights[i] = maxHeights[i];
                res+= heights[i];
                continue;
            }
        }
        
    }
};


/*
 * [1, 4, 4, 4, -1, -1]
 * [-1, -1, 1, 1, 1, 4]
 *
 * [2, 2, -1, -1, 5, -1]
 * [-1, 0, -1, -1, 3, 3]
 */
