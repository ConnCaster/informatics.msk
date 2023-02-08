import queue

n, s, f = map(int, input().split())

s -= 1
f -= 1
g = [[] for i in range(n)]
for i in range(n):
    arr = list(map(int, input().split()))
    for j in range(len(arr)):
        if arr[j] > 0:
            g[i].append((j, arr[j]))
inf = 10001
r = [inf for i in range(n)]
q = queue.PriorityQueue()
r[s] = 0
q.put((0, s))
while not(q.empty()):
    _, cur = q.get()
    for to, leng in g[cur]:
        if r[cur] + leng < r[to]:
            r[to] = r[cur] + leng
            q.put((r[to], to))
if r[f] == inf:
    print(-1)
else:
    print(r[f])