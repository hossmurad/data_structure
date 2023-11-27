#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;


vector<bool> visited;

void dfs(int node) {
   
    visited[node] = true;

    
    cout << node << " ";

   
    for (int adjacentNode : adj[node]) {
    
        if (!visited[adjacentNode]) {
            dfs(adjacentNode);
        }
    }
}

int main() {

    int n;
    cin >> n;

  
    adj.assign(n, vector<int>());
    visited.assign(n, false);

    int x, y;

   
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << "Adjacency list of elements:" << endl;

    
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

   
    int startNode;
    cin >> startNode;

    cout << "DFS traversal starting from node " << startNode << ":" << endl;

    
    dfs(startNode);

    return 0;
}
