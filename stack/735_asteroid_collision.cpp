class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool destroyed = false;

            while (!s.empty() && curr < 0 && s.top() > 0) {
                if (abs(curr) > s.top()) {
                    s.pop(); 
                } else if (abs(curr) == s.top()) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                s.push(curr);
            }
        }

        vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};

