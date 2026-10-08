#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() {
    int h, w, k;
    cin>>h>>w>>k;

    vector<string> grid;

    for(int i = 0; i < h; i++) {
        string s;
        cin>>s;
        grid.push_back(s);
    }

    for(int j = 0; i < 

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == 'i') {
                cout<<grid[i][j];
            }
        }
        cout<<endl;
    }
}
