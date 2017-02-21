import sys
import queue as Q
sys.stdin = open('input.txt')


def prim(N):
    global adj
    pq = Q.PriorityQueue()
    MSTEdges = 0
    total_weight = 0
    visited = [False for i in range(N+1)]
    visited[1] = True
    for edge in adj[1]:
        pq.put((edge[1], 1, edge[0])) # weight, start node, end node
    while MSTEdges < N and not pq.empty():
        state = pq.get()
        weight = state[0]
        start_node = state[1]
        end_node = state[2]
        if visited[start_node] and not visited[end_node]:
            visited[end_node] = True
            MSTEdges += 1
            total_weight += weight
            for edge in adj[end_node]:
                pq.put((edge[1], end_node, edge[0]))  # weight, start node, end node
    #print(MSTEdges, total_weight)
    if MSTEdges == N-1:
        return total_weight
    else:
        return -1


if __name__ == '__main__':
    T = int(input())
    adj = {}
    for t in range(T):
        N, C = map(int, input().split())
        for i in range(N+1):
            adj[i] = []
        for i in range(C):
            u, v, w = map(int, input().split())
            adj[u].append((v, w))
            adj[v].append((u, w))
        #print(adj)
        ans = prim(N)
        if ans == -1:
            print('Requires more conduits')
        else:
            print(ans)
        adj.clear()
