#include <stdio.h>
#include <string.h>

#define MAXN 2005
#define MAXM 4005

struct Edge {
    int u, v;
} edges[MAXM];

int N, M;
int A[MAXN];
int graph[MAXN][MAXN];
int visited[MAXN];
int reachable[MAXN];

void dfs(int vertex) {
    visited[vertex] = 1;
    
    for(int i = 1; i <= N; i++) {
        if(graph[vertex][i] && !visited[i]) {
            reachable[vertex]++;
            dfs(i);
        }
    }
}

int checkValid() {
    for(int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        reachable[i] = 0;
        dfs(i);
        if(reachable[i] != A[i]-1) return 0;
    }
    return 1;
}

int result[MAXM][2];
int found = 0;

void tryDirections(int idx) {
    if(found) return;
    
    if(idx == M) {
        if(checkValid()) {
            found = 1;
            for(int i = 0; i < M; i++) {
                printf("%d %d\n", result[i][0], result[i][1]);
            }
        }
        return;
    }
    
    graph[edges[idx].u][edges[idx].v] = 1;
    graph[edges[idx].v][edges[idx].u] = 0;
    result[idx][0] = edges[idx].u;
    result[idx][1] = edges[idx].v;
    tryDirections(idx + 1);
    
    if(found) return;
    
    graph[edges[idx].u][edges[idx].v] = 0;
    graph[edges[idx].v][edges[idx].u] = 1;
    result[idx][0] = edges[idx].v;
    result[idx][1] = edges[idx].u;
    tryDirections(idx + 1);
    
    if(!found && idx == M-1) {
        graph[edges[idx].u][edges[idx].v] = 0;
        graph[edges[idx].v][edges[idx].u] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }
    
    for(int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    
    memset(graph, 0, sizeof(graph));
    
    tryDirections(0);
    
    if(!found) {
        printf("-1\n");
    }
    
    return 0;
}