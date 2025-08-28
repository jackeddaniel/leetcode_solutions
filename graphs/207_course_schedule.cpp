// what we have to do is find cycles in a graph i.e, interdependency.
//
//

class Solution {
    public:
        bool dfs(int i, vector<int>& visited, vector<vector<int>>& graph) {
            if (visit[i] == 1) return false;
            if (visit[i] == 2) return true;

            visit[i] = 1;

            for(int next : graph[i]) {
                if (!dfs(next)) return false;
            }

            visit[i] = 2;
            return true;
        }
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            // we build the graph using an adjacency list
            vector<vector<int>> graph(numCurses);
            for(auto& pre : prerequisites) {
                graph[pre[0]].push_back(pre[1]);
            }

            // initialize a vector for tracking the state of each node
            vector<int> visit(numCourses, 0);

            for(int i = 0; i < numCourses; i++) {
                
                if(!dfs(i,visit,graph)) return false;
            }
            return true;
        }
};
