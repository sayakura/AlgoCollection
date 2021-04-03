def dijkstra(self, n: int, edges: List[List[int]]) -> int:
    if n == 1:
        return 0
    adj = defaultdict(list)
    for u, v, w in edges: 
        adj[u].append((w, v))
        adj[v].append((w, u))
    minHeap = [(0, n)]
    dist = [float('inf') for _ in range(n + 1)]
    dist[n] = 0
    while minHeap:
        d, u = heappop(minHeap)
        if d != dist[u]:
            continue 
        for w, v in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heappush(minHeap, (dist[v], v))