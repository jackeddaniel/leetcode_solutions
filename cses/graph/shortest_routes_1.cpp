#include <queue>
#include<vector>
#include<iostream>
#include<limits.h>

using namespace std;

void djikstra(vector<vector<pair<long long, long long>>>& g, vector<long long>& dist) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [w, v] : g[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    long long n;
    long long m;
    cin>>n>>m;
    vector<vector<pair<long long, long long>>> g(n+1);
    
    // we build the graph
    for(long long i = 0; i < m; i++) {
        long long u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({w, v});
    }

    vector<long long> dist(n+1, LLONG_MAX);
    djikstra(g, dist);

    for(long long i = 1; i < n+1; i++) {
        cout<<dist[i]<<" ";
    }
}
