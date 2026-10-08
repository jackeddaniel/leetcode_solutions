#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void debug(vector<vector<char>>& house) {
    int m = house.size();
    int n = house[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<house[i][j];
        }
        cout<<endl;
    }

}

vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bfs(vector<vector<char>>& house, int x, int y) {
    queue<pair<int, int>> q;

    house[x][y] = 'v';
    q.push({x, y});

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for(auto [di, dj] : mv) {
            int ni = di + i;
            int nj = dj + j;
            if(ni < house.size() && nj < house[0].size() && ni > -1 && nj > -1 && house[ni][nj] == 'B') {

                return true;
            }
            if(ni < house.size() && nj < house[0].size() && ni > -1 && nj > -1 && house[ni][nj] == '.') {
                house[ni][nj] = 'v';
                q.push({ni, nj});
            }
        }
    }

    return false;
}

int main() {
    int m, n;
    vector<vector<char>> house;


    cin>>m>>n;
    pair<int, int> start, finish;


    for(int i = 0; i < m; i++) {
        vector<char> tmp;

        for(int j = 0; j < n; j++) {
            char c;
            cin>>c;
            if(c == 'A') start = {i, j};
            if(c == 'B') finish = {i, j};
            tmp.push_back(c);
        }

        house.push_back(tmp);
    }

    vector<char> path;

    bool val;
    val = bfs(house, start.first, start.second);

    if(val) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
}
