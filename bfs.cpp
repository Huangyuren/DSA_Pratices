#include <vector>
#include <queue>
#include <iostream>
#define MAX_SIZE 5

using namespace std;

vector<vector<int> >adj(MAX_SIZE, vector<int>(MAX_SIZE, 0));
vector<bool> visited(MAX_SIZE, false);

void bfs(int currnode) {
	visited[currnode] = true;
	queue<int> quu;
	quu.push(currnode);
	while(quu.size()){
		int tmp = quu.front();
		quu.pop();
        cout << "Node "<<tmp<< " being visited."<<endl;
		for(auto i : adj[tmp]) {
			if(!visited[tmp]) {
				visited[i] = true;
				quu.push(i);
			}
		}
	}
}
void addEdge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int main() {
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    // addEdge(3, 4);
    addEdge(3, 5);
    addEdge(2, 8);
    addEdge(8, 9);
    addEdge(6, 9);
    // addEdge(6, 5);
    addEdge(5, 7);
    bfs(0);
    return 0;
}
