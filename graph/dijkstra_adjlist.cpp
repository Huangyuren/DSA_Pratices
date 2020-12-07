#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#define MAX_SIZE 10

using namespace std;

struct node {
    int rec=0, weights=0;
    node(int a, int b) : rec(a), weights(b) {}
};
vector<vector<node>> graph(MAX_SIZE, vector<node>()); //adjacency list, not matrix.
vector<int> dist(MAX_SIZE, INT_MAX);

void printresult() {
    printf("Printing result...\n");
    for(int i=0; i<graph.size(); ++i) printf("dist[%d]: %d\n", i, dist[i]);
}
void dijkstra(int startnode) {
    queue<int> qu;
    qu.push(startnode);
    dist[startnode] = 0;
	while(qu.size()) {
        int currnode = qu.front();
        qu.pop();
        cout << "Node "<<currnode<< " being visited."<<endl;
		for(node j : graph[currnode]) {
			if(dist[j.rec] > dist[currnode] + j.weights) {
				dist[j.rec] = dist[currnode]+j.weights;
				qu.push(j.rec);
			}
		}
	}
}
void addEdge(int a, int b, int dist) {
	graph[a].push_back(node(b, dist));
	graph[b].push_back(node(a, dist));
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
