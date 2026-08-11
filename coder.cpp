#include <queue>
#include<vector>
#include<iostream>
#include<limits.h>

using namespace std;

void djikstra(vector<vector<pair<long long, long long>>>& g, vector<pair<long long,long long>>& dist) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push({0, 1});
    dist[1].first = 0;
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u].first) continue;
        for(auto [w, v] : g[u]) {
            if(dist[u].first + w < dist[v].first) {
                dist[v].first = dist[u].first + w;
                dist[v].second = u;
                pq.push({dist[v].first, v});
            }
        }
    }
}

int main() {
    long long n;
    long long m;
    cin>>n>>m;
    vector<vector<pair<long long, long long>>> g(n+1);

    if(n == 1) {
        cout<<1;
        return 0;
    }
    
    // we build the graph
    for(long long i = 0; i < m; i++) {
        long long u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    vector<pair<long long, long long>> dist(n+1, {LLONG_MAX, -1});
    djikstra(g, dist);

    int curr = n;
    if(dist[n].second == -1) {
        cout<<-1;
        return 0;
    }
    vector<long long> res;
    while(curr != -1) {
        res.push_back(curr);
        curr = dist[curr].second;
    }
    reverse(res.begin(), res.end());
    for(auto x : res){
        cout<<x<<" ";
    }
}
