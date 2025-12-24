from collections import deque

class Solution:
    def findRedundantConnection(self, edges):
        parent = {}
        rank = {}

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])

            return parent[x]
            

        def union(x, y):
            rootx = find(x)
            rooty = find(y)

            if rootx == rooty:
                return False

            if rank[rootx] > rank[rooty]:
                parent[rooty] = rootx

            elif rank[rootx] < rank[rooty]:
                parent[rootx] = rooty

            else: 
                parent[rooty] = rootx
                rank[rootx] += 1

            return True

        for u, v in edges:
            if u not in parent:
                parent[u] = u
                rank[u] = 0

            if v not in parent:
                parent[v] = v
                rank[v] = 0

            if not union(u, v):
                return [u, v]
        

