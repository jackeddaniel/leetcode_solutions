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

void bfs(vector<vector<char>>& house, int x, int y) {
    queue<pair<int, int>> q;

    house[x][y] = 'v';
    q.push({x, y});

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for(auto [di, dj] : mv) {
            int ni = di + i;
            int nj = dj + j;

            if(ni < house.size() && nj < house[0].size() && ni > -1 && nj > -1 && house[ni][nj] == '.') {
                house[ni][nj] = 'v';
                q.push({ni, nj});
            }
        }
    }
}

int countRooms(vector<vector<char>>& house) {

    int room = 0;
    
    for(int i = 0; i < house.size(); i++) {
        for(int j = 0; j < house[0].size(); j++) {
            if(house[i][j] == '.') {
                room++;
                bfs(house, i, j);
            }
        }
    }
    return room;
}

int main() {
    int m, n;
    vector<vector<char>> house;


    cin>>m>>n;

    for(int i = 0; i < m; i++) {
        vector<char> tmp;

        for(int j = 0; j < n; j++) {
            char c;
            cin>>c;
            tmp.push_back(c);
        }

        house.push_back(tmp);
    }

    cout<<countRooms(house);
    //debug(house);
}
