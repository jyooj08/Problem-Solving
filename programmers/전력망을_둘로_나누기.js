function makeGraph(deleteIdx, n, wires){
    let graph = {};
    for(let i=1;i<=n;i++) graph[i] = [];
    for(let i in wires){
        if(i == deleteIdx) continue;
        let w = wires[i];
        graph[w[0]].push(w[1]);
        graph[w[1]].push(w[0]);
    }
    return graph;
}

function dfs(start, graph, visited){
    visited[start] = true;
    for(let next of graph[start]){
        if(visited[next] == false) dfs(next, graph, visited);
    }
}

function solution(n, wires) {
    let answer = n;
    
    for(let i in wires){
        let visited = new Array(n+1);
        visited.fill(false);
        let graph = makeGraph(i, n, wires);
        dfs(1, graph, visited);
        
        let cnt = 0;
        for(v of visited)
            if(v == true) cnt++;
        let result = Math.abs(cnt - n + cnt);
        if(result < answer) answer = result;
    }
    
    return answer;
}