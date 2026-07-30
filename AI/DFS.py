import queue

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

closedlist = {}
dfs_output = []

for node in adj_list.keys():
    closedlist[node] = "not visited"


def dfs(u):
    closedlist[u] = "visited"
    dfs_output.append(u)

    for v in adj_list[u]:
        if closedlist[v]!= "visited":
            dfs(v)


print("---- DFS ----")

startnode = input("Enter the starting node: ")

dfs(startnode)


print("DFS output =", dfs_output)
