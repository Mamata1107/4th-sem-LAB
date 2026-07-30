graph = {
    "Canary": ["Bird"],
    "Bird": ["Animal"],
    "Animal": []
}

visited = set()

def traverse(node):

    if node not in visited:

        print(node)

        visited.add(node)

        for neighbour in graph[node]:
            traverse(neighbour)


print("Semantic Network Traversal")
traverse("Canary")

