class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            int n = nums2.size();
            vector<int> x(n, -1);
            stack<int> s;

            unordered_map<int,int> track;

            for(int i = n-1; i >=0; i--) {
                track[nums2[i]] = i;
                while(!s.empty() && s.top() <= nums[i]) {
                    st.pop();
                }

                if(!st.empty()) {
                    x[i] = st.top();
                }

                st.push(nums[i]);
            }

            

            vector<int> res(nums1.size(), -1);
            for(int i = 0; i < nums1.size(); i++) {
                res[i] = x[track[nums1[i]]];
            }

            return res;
        }
};
