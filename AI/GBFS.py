
graph = {
    's': ['a', 'b'],
    'a': ['c', 'd'],
    'b': ['e', 'f'],
    'c': [],
    'd': [],
    'e': ['h'],
    'f': ['i', 'g'],
    'g': [],
    'h': [],
    'i': []
}


heuristic = {
    's': 13,
    'a': 12,
    'b': 4,
    'c': 7,
    'd': 3,
    'e': 8,
    'f': 2,
    'g': 0,  
    'h': 4,
    'i': 9
}


def gbfs(graph, heuristic, start, goal):
    visited = set()  
    queue = [(heuristic[start], [start])] # Priority queue (heuristic, path)  

    while queue:
        
        queue.sort(key=lambda x: x[0])
        
        (h, path) = queue.pop(0)
        current_node = path[-1]  
       
        if current_node == goal:
            return path

       
        visited.add(current_node)

      
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                new_path = path + [neighbor]
                queue.append((heuristic[neighbor], new_path))

    return None  


start_node = input("Enter the start node: ")
goal_node = input("Enter the goal node: ")


traversed_path = gbfs(graph, heuristic, start_node, goal_node)

# Output the result
if traversed_path:
    print("Path found and traversed path is:", traversed_path)
else:
    print("Path not found.")
=
