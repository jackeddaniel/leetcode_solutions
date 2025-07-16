
class Solution {
    public: 
        int orangesRotting(vector<vector<int>>& grid) {
            int n = 0;
            queue<pair<int,int>> q;

            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == 2) {
                        q.push({i,j});
                    }
                    else if(grid [i][j] == 1) {
                        n++;
                    }
                    else {
                        continue;
                    }
                }
            }
            if(n == 0) return 0;
            cout<<"initial n: "<<n<<"\n";
            int mins = 0;
            int rotted = 0;

            while(!q.empty()) {

                int size = q.size();
                rotted = 0;

                for(int i = 0; i < size; i++) {
                    int a = q.front().first;
                    int b = q.front().second;

                    q.pop();
                    
                    if(a > 0 && grid[a-1][b] == 1) {
                        q.push({a-1,b});
                        grid[a-1][b] = 2;
                        n--;
                        cout<<n<<" ";
                        rotted = 1;
                    }
                    if(a < grid.size() - 1 && grid[a+1][b] == 1) {
                        q.push({a+1,b});
                        grid[a+1][b] = 2;
                        n--;
                        cout<<n<<" ";
                        rotted = 1;
                    }

                    if(b > 0 && grid[a][b-1] == 1) {
                        q.push({a, b-1});
                        grid[a][b-1] = 2;
                        n--;
                        cout<<n<<" ";
                        rotted = 1;
                    }
                    if(b  < grid[0].size() - 1 && grid[a][b+1] == 1) {
                        q.push({a, b+1});
                        grid[a][b+1] = 2;
                        n--;
                        cout<<n<<" ";
                        rotted = 1;
                    }
                    
                }
                cout<<"\n";
                if(rotted == 1) mins++;
                cout<<"mins: "<<mins<<"\n";
            }
            cout<<"final n: "<<n<<"\n";
            if(n>0) return -1;
            return mins;
        }
};
