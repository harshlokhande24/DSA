//Assignment 2 DSA
//Harshwardhan Lokhande


#include <iostream>
#include <map>
#include <list>
#include <stack>
using namespace std;

class graph {
    
    int V;
    map<int, list<int>> adj;
    map<int, bool> visited;
    stack<int> box;
    public:
        void addEdge(int v, int w);
        void dfs(int v);
        void display();
    
};

void graph :: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void graph :: dfs(int s) {
    int x;
    
    visited[s] = true;
    box.push(s);
    
    while(!adj[s].empty()) {
        x = adj[s].front();
        if(!visited[x]) {
            dfs(x);
        }
        adj[s].pop_front();
    }
    
}

void graph :: display() {
    
    stack<int> stack;
    
    while (!box.empty()) {
        stack.push(box.top());
        box.pop();
    }
    
    while(!stack.empty()) {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    
}

int main()
{
    graph g;
    int oper, x, y;
    
    while(true) {
        
        cout<<"1. Add Edge\n2. Show DFS Traversal\n3. Exit\nYour Choice: ";
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
            cout<<endl<<"Depth First Traversal of the graph from "<<x<<" is: ";
            g.dfs(x);
            g.display();
            cout<<endl<<endl;
            break;
            
            case 3:
            exit(0);
            break;
        }
        
    }

    return 0;
}
