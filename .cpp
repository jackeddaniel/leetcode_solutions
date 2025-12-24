class Solution {
    public:
        long long minimumRemoval(vector<int>& beans) {
            int n = beans.size();

            sort(beans.begin(), beans.end());

            vector<int> p(n);
            vector<int> s(n);
            
            int ans = INT_MAX;
            for(int i : beans) cout<<i<<" ";
            cout<<"\n";
            p[0] = 0;
            for(int i = 1; i < n; i++) {
                int moreleft = 0;
                int left = beans[i-1];
                if(i > 1) moreleft = p[i-1];
                p[i] = left + moreleft;
            }
            for(int i : p) cout<<i<<" ";
            cout<<"\n";
            
            
            s[n-1] = 0;
            for(int i = n-2; i > -1; i--) {
                int moreright = 0;
                int right = beans[i+1];
                if(i < n-2) moreright = s[i+1];

                s[i] = right+moreright;
                
                int diff = s[i] - beans[i]*(n-1-i)
                int mid = diff+p[i];
                ans = min(ans, mid);
            }
            for(int i : s) cout<<i<<" ";
            ans = min(ans, (s[0]+p[0]));
            ans = min(ans, (s[n-1] + p[n-1]));

            long long res = ans;

            return res = ans;
        }
};
