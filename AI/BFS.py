adj_list = {
    "a": ["b", "c"],
    "b": ["d", "e"],
    "c": ["f", "g"],
    "d": ["h", "i"],
    "e": [],
    "f": ["j", "k"],
    "g": [],
    "h": [],
    "i": [],
    "j": [],
    "k": []
}

visited = []
queue = []
BFS_Output = []

def BFS(visited, graph, node):
    visited.append(node)
    queue.append(node)

    while queue:
        m = queue.pop(0)
        BFS_Output.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

print("___BFS___")
startnode = input("Enter the start node: ").lower()

if startnode in adj_list:
    BFS(visited, adj_list, startnode)
    print("BFS Traversal:", BFS_Output)
else:
    print("Invalid start node")

