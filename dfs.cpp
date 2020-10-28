#include <bits/stdc++.h>
#define DIMEN 10

using namespace std;
vector<vector<int>> adj(DIMEN, vector<int>(0, 0));
vector<bool> visited(DIMEN, false);

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfsRecur(int curr) {
    visited[curr] = true;
    for(int i : adj[curr]) {
        if(visited[i] == false) {
            cout << "Node "<<i<< " being visited."<<endl;
            dfsRecur(i);
        }
    }
}

void dfsIteration(int curr) {
    stack<int> st;
    st.push(curr);
    visited[curr] = true;
    while(st.size()) {
        int currnode = st.top();
        st.pop();
        cout << "Node "<<currnode<< " being visited."<<endl;
        for(int i : adj[currnode]) {
            if(visited[i] == false) {
                st.push(i);
                visited[i] = true;
            }
        }
    }
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
    dfsRecur(0);
    printf("##### Iterative method #####\n");
    fill(visited.begin(), visited.end(), 0);
    dfsIteration(0);
    return 0;
}
