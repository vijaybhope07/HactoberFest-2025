function hasCycle(graph) {
    const visited = new Set();
    const stack = new Set();

    function dfs(node) {
        if (stack.has(node)) return true;
        if (visited.has(node)) return false;

        visited.add(node);
        stack.add(node);

        for (const neighbor of graph[node] || []) {
            if (dfs(neighbor)) return true;
        }

        stack.delete(node);
        return false;
    }

    for (const node in graph) {
        if (dfs(node)) return true;
    }
    return false;
}

const graphWithCycle = { 0: [1], 1: [2], 2: [0] };
console.log(hasCycle(graphWithCycle)); // Output: true
