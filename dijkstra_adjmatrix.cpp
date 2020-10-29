#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#define MAX_SIZE 10

using namespace std;

struct node {
    int send=0, rec=0, weights=0;
    node(int a, int b, int c) : send(a), rec(b), weights(c) {}
};
vector<vector<int>> graph(MAX_SIZE, vector<int>(MAX_SIZE, -1)); //adjacency matrix, not list.
vector<int> dist(MAX_SIZE, INT_MAX);

void printresult() {
    printf("Printing result...\n");
    for(int i=0; i<graph.size(); ++i) printf("dist[%d]: %d\n", i, dist[i]);
}
void dijkstra(int startnode) {
    queue<int> qu;
    qu.push(startnode);
    dist[0] = 0;
	while(qu.size()) {
        int tmp = qu.front();
        qu.pop();
        for(int i=0; i<MAX_SIZE; ++i) {
            if(graph[tmp][i] != -1) {
                if(dist[i] > dist[tmp] + graph[tmp][i]) {
                    dist[i] = dist[tmp] + graph[tmp][i];
                    qu.push(i);
                }
            }
        }
	}
}
void addEdge(int a, int b, int dist) {
	graph[a][b] = dist;
	graph[b][a] = dist;
}

int main() {
    addEdge(0, 1, 10);
    addEdge(0, 4, 3);
    addEdge(1, 2, 7);
    addEdge(1, 3, 5);
    addEdge(1, 4, 2);
    addEdge(2, 3, 2);
    addEdge(3, 5, 5);
    addEdge(2, 8, 9);
    addEdge(8, 9, 6);
    addEdge(6, 9, 4);
    addEdge(5, 7, 2);
    dijkstra(0);
    printresult();
    return 0;
}
