function depthFirstSearch(graph, start, visited = new Set()) {
    visited.add(start);
    console.log(start);

    for (const neighbor of graph[start]) {
        if (!visited.has(neighbor)) {
            depthFirstSearch(graph, neighbor, visited);
        }
    }
}

const graph = {
    0: [1, 3],
    1: [0, 2, 4],
    2: [1],
    3: [0, 4],
    4: [1, 3]
};
depthFirstSearch(graph, 3);
