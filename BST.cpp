//Harshwardhan Lokhande

#include <iostream>
#include <queue>

using namespace std;

struct Node {
   int key;
   Node * left;
   Node * right;
};

Node*newNode(int key) {
   Node * node = new Node;
   node -> key = key;
   node -> left = NULL;
   node -> right = NULL;
   return node;
}

Node*insert(Node * root, int key) {
   if (root == NULL)
      return newNode(key);
   if (key < root -> key)
      root -> left = insert(root -> left, key);
   else if (key > root -> key)
      root -> right = insert(root -> right, key);
   return root;
}

Node*minValueNode(Node * node) {
   Node * current = node;
   while (current -> left != NULL)
      current = current -> left;
   return current;
}

Node*deleteNode(Node * root, int key) {
   if (root == NULL)
      return root;
   if (key < root -> key)
      root -> left = deleteNode(root -> left, key);
   else if (key > root -> key)
      root -> right = deleteNode(root -> right, key);
   else {
      if (root -> left == NULL) {
         Node * temp = root -> right;
         delete root;
         return temp;
      } else if (root -> right == NULL) {
         Node * temp = root -> left;
         delete root;
         return temp;
      }
      Node * temp = minValueNode(root -> right);
      root -> key = temp -> key;
      root -> right = deleteNode(root -> right, temp -> key);
   }
   return root;
}

bool search(Node * root, int key) {
   if (root == NULL)
      return false;
   if (root -> key == key)
      return true;
   else if (root -> key > key)
      return search(root -> left, key);
   else
      return search(root -> right, key);
}

void levelOrder(Node * root) {
   if (root == NULL)
      return;
   queue < Node * > q;
   q.push(root);
   while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {

         Node * node = q.front();
         q.pop();
         cout << node -> key << " ";
         if (node -> left != NULL)
            q.push(node -> left);
         if (node -> right != NULL)
            q.push(node -> right);
      }
      cout << endl;
   }
}

void mirror(Node * node) {
   if (node == NULL)
      return;
   else {
      Node * temp;
      mirror(node -> left);
      mirror(node -> right);
      temp = node -> left;
      node -> left = node -> right;
      node -> right = temp;
   }
   levelOrder(node);
}

void inorder(Node * root) {
   if (root == NULL)
      return;
   inorder(root -> left);
   cout << root -> key << " ";
   inorder(root -> right);
}

int main() {
   Node * root = NULL;
   int choice, key;
   do {
      cout << "1. Insert" << endl;
      cout << "2. Delete" << endl;
      cout << "3. Search" << endl;
      cout << "4. Mirror Image" << endl;
      cout << "5. Display" << endl;
      cout << "6. Display level wise" << endl;
      cout << "0. Exit" << endl;

      cout << "Enter your choice: ";

      cin >> choice;
      switch (choice) {
      case 1:
         cout << "Enter key to insert: ";
         cin >> key;
         root = insert(root, key);
         cout << "Key " << key << " inserted successfully." << endl;
         break;
      case 2:
         cout << "Enter key to delete: ";
         cin >> key;
         if (deleteNode(root, key) == NULL)
            cout << "Key " << key << " not found." << endl;
         else
            cout << "Key " << key << " deleted successfully." << endl;
         break;
      case 3:
         cout << "Enter key to search: ";
         cin >> key;
         if (search(root, key))
            cout << "Key " << key << " found." << endl;
         else
            cout << "Key " << key << " not found." << endl;
         break;
      case 4:
         mirror(root);
         cout << "Mirror image of tree generated successfully." << endl;
         break;
      case 5:

         cout << "Tree: ";
         inorder(root);
         cout << endl;
         break;
      case 6:
         cout << "Level order traversal:" << endl;
         levelOrder(root);
         break;
      case 0:
         cout << "Exiting program..." << endl;
         break;
      default:
         cout << "Invalid choice." << endl;
      }
   }
   while (choice != 0);
   return 0;
}
