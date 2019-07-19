def find_lowest_cost_node(costs):
    lowest_cost=float("inf")
    lowest_cost_node=None
    for node in costs:
        cost=costs[node]
        if cost<lowest_cost and node not in processed:
            lowest_cost=cost
            lowest_cost_node=node
    return lowest_cost_node

infinity=float("inf")
costs={}
parents={}
neighbors={}
processed=[]
graph={}
graph["start"]={}
graph["start"]["a"]=5
graph["start"]["b"]=2
graph["a"]={}
graph["a"]["c"]=2
graph["a"]["d"]=4
graph["b"]={}
graph["b"]["a"]=8
graph["b"]["c"]=7
graph["c"]={}
graph["c"]["fin"]=1
graph["d"]={}
graph["d"]["c"]=6
graph["d"]["fin"]=3
graph["fin"]=None
costs["a"]=5
costs["b"]=2
costs["c"]=infinity
costs["d"]=infinity
costs["fin"]=infinity

node=find_lowest_cost_node(costs)
#print (node)
while node is not None:
    cost=costs[node]
    neighbors=graph[node]
    #print(neighbors.keys())
    for neighbor in list(neighbors.keys()):
        new_cost=cost+neighbors[neighbor]
        if costs[neighbor]>new_cost:
            costs[neighbor]=new_cost
            parents[neighbor]=node
    processed.append(node)
    node=find_lowest_cost_node(costs)
print(costs)
print(parents)