import queue
import threading


class Graph:
    def __init__(self, V):
        self.V = V
        self.adjListArray = [[] for _ in range(V)]

    def addEdge(self, src, dest):
        self.adjListArray[src].append(dest)
        self.adjListArray[dest].append(src)

    def BFS(self, s):
        visited = [False] * self.V
        q = queue.Queue()
        visited[s] = True
        q.put(s)

        while not q.empty():
            s = q.get()
            print(s, end=' ')

            for u in self.adjListArray[s]:
                if not visited[u]:
                    visited[u] = True
                    q.put(u)

    def DFSUtil(self, v, visited):
        visited[v] = True
        print(v, end=' ')

        for u in self.adjListArray[v]:
            if not visited[u]:
                self.DFSUtil(u, visited)

    def DFS(self, v):
        visited = [False] * self.V
        threads = []
        lock = threading.Lock()

        def dfs_threaded(vertex):
            self.DFSUtil(vertex, visited)
            with lock:
                threads.remove(threading.current_thread())

        for vertex in range(self.V):
            if not visited[vertex]:
                thread = threading.Thread(target=dfs_threaded, args=(vertex,))
                thread.start()
                threads.append(thread)

        for thread in threads:
            thread.join()


if __name__ == "__main__":
    V = 5
    graph = Graph(V)
    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 3)
    graph.addEdge(1, 4)

    print("BFS:")
    graph.BFS(0)

    print("\nDFS:")
    graph.DFS(0)
