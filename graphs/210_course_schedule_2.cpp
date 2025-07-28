//We have to do the same as course schedule 1 and find if there is a cycle, but we should also return a correct order to take all the courses
class Solution {
    public:

        bool dfs(int i, vector<int>& visited, vector<vector<int>>& graph, vector<int>& order) {
            if (visited[i] == 1) return false;
            if (visited[i] == 2) return true;
            visited[i] =1;
            for (int j : graph[i]) {
                if(!dfs(j, visited, graph, order)) return false;
            }

            visited[i] == 2;
            order.push_back(i);
            return true;
        }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            // make the graph using an adjacency list
            vector<vector<int>> graph(numCourses);

            for (auto pre : prerequisites) {
                graph[pre[0]].push_back(pre[1]);
            }

            vector<int> visited(numCourses, 0);

            vector<int> order;

            for (int i = 0; i < numCourses; i++) {
                if (!dfs(i, visited, graph, order)) {
                    return {};
                }
            }

            return order;
            
        }
};

