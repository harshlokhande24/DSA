//Assignment 2 DSA
//Harshwardhan Lokhande


#include <iostream>
#include <map>
#include <list>
using namespace std;

class graph {
    
    int V;
    map<int, list<int>> adj;
    
    public:
        void addEdge(int v, int w);
        void bfs(int v);
    
};

void graph :: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void graph :: bfs(int s) {
    int x;
    map<int, bool> visited;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    
    while(!queue.empty()) {
        
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        
        while(!adj[s].empty()) {
            x = adj[s].front();
            if(!visited[x]) {
                visited[x] = true;
                queue.push_back(x);
            }
            adj[s].pop_front();
        }
        
    }
    
}

int main()
{
    graph g;
    int oper, x, y;
    
    while(true) {
        
        cout<<"1. Add Edge\n2. Show BFS Traversal\n3. Exit\nYour Choice: ";
        cin>>oper;
        
        switch(oper) {
            case 1:
            cout<<"From: ";
            cin>>x;
            cout<<"To:   ";
            cin>>y;
            g.addEdge(x, y);
            break;
            
            case 2:
            cout<<"Start traversal from: ";
            cin>>x;
            cout<<endl<<"Breadth First Traversal of the graph from "<<x<<" is: ";
            g.bfs(x);
            cout<<endl<<endl;
            break;
            
            case 3:
            exit(0);
            break;
        }
        
    }

    return 0;
}
