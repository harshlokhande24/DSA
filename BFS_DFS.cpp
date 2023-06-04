//Assignment 2 DSA
//Harshwardhan Lokhande

#include <iostream>
#include <stack>
#include <queue>
#define MAX_NODES 100

using namespace std;

int adj[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void dfs(int start, int n) {
   stack < int > s;
   s.push(start);
   while (!s.empty()) {
      int current = s.top();
      s.pop();
      if (!visited[current]) {
         visited[current] = 1;
         cout << current << " ";
         for (int i = n - 1; i >= 0; i--) {
            if (adj[current][i] && !visited[i]) {
               s.push(i);
            }
         }
      }
   }
}

void bfs(int start, int n) {
   queue < int > q;
   q.push(start);
   while (!q.empty()) {
      int current = q.front();
      q.pop();
      if (!visited[current]) {
         visited[current] = 1;
         cout << current << " ";
         for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
               q.push(i);
            }
         }
      }
   }
}

int main() {
   int n, e;
   cout << "Enter number of nodes and edges: ";
   cin >> n >> e;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         adj[i][j] = 0;
      }
   }
   cout << "Enter edges (from to): " << endl;
   for (int i = 0; i < e; i++) {

      int from, to;
      cin >> from >> to;
      adj[from][to] = 1;
      adj[to][from] = 1;
   }
   int choice, start;
   do {
      for (int i = 0; i < n; i++) {
         visited[i] = 0;
      }
      cout << endl << "Choose an option:" << endl;
      cout << "1. DFS" << endl;
      cout << "2. BFS" << endl;
      cout << "3. Exit" << endl;
      cin >> choice;
      if (choice == 1) {
         cout << "Enter starting node: ";
         cin >> start;
         cout << "DFS traversal: ";
         dfs(start, n);
         cout << endl;
      } else if (choice == 2) {
         cout << "Enter starting node: ";
         cin >> start;
         cout << "BFS traversal: ";
         bfs(start, n);
         cout << endl;
      }
   } while (choice != 3);
   return 0;
}
