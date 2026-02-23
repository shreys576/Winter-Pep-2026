#include<bits/stdc++.h>
using namespace std;


int main(){

    int n; // number of vertices
    int m; // number of edges

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the number of edges: ";
    cin >> m;

    unordered_map<int, list<int>> adjList;
    cout << "Enter edges(u, v): " << endl;
    cout << "\nAdjacency List: " << endl;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // kyuki graph undirected hai yeh waala isliye dono ek dusre ke neighbours honge nahi toh agar directed hota toh yeh 2nd waala push_back nahi likhte

    }
    cout << "Adjacency List: " << endl;

    for(auto i : adjList){
        cout << i.first << " -> ";
        for(auto j : i.second){
            cout << j << " ";
        }
        cout << endl;
    }


}