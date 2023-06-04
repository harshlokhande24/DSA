//Assignment 1 DSA
//Harshwardhan Lokhande

#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode{
    char value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(char value) {
    TreeNode* node = new TreeNode();
    node->value = value;
    node->left = node->right = nullptr;
    return node;
}

TreeNode* constructPostfixTree(string postfix) {
    stack<TreeNode*> stk;
    for (int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            TreeNode* node = newNode(c);
            stk.push(node);
        }
        else {
            TreeNode* right = stk.top();
            stk.pop();
            TreeNode* left = stk.top();
            stk.pop();
            TreeNode* node = newNode(c);
            node->left = left;
            node->right = right;
            stk.push(node);
        }
    }
    return stk.top();
}

TreeNode* constructPrefixTree(string prefix) {
    stack<TreeNode*> stk;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) {
            TreeNode* node = newNode(c);
            stk.push(node);
        }
        else {
            TreeNode* left = stk.top();
            stk.pop();
            TreeNode* right = stk.top();
            stk.pop();
            TreeNode* node = newNode(c);
            node->left = left;
            node->right = right;
            stk.push(node);
        }
    }
    return stk.top();
}

void recursiveInorder(TreeNode* root) {
    if (root == nullptr) return;
        recursiveInorder(root->left);
        cout << root->value << " ";
        recursiveInorder(root->right);
    }
    
void iterativeInorder(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        cout << curr->value << " ";
        curr = curr->right;
    }
}

void recursivePreorder(TreeNode* root) {
    if (root == nullptr) return;
        cout << root->value << " ";
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
    
void iterativePreorder(TreeNode* root) {
    if (root == nullptr) return;
        stack<TreeNode*> stk;
        stk.push(root);
    while (!stk.empty()) {
        TreeNode* curr = stk.top();
        stk.pop();
        cout << curr->value << " ";
        if (curr->right != nullptr) stk.push(curr->right);
        if (curr->left != nullptr) stk.push(curr->left);
    }
}

void recursivePostorder(TreeNode* root) {
    if (root == nullptr) return;
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        cout << root->value << " ";
}

void iterativePostorder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> stk1, stk2;
    stk1.push(root);
    while (!stk1.empty()) {
        TreeNode* curr = stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left != nullptr)
            stk1.push(curr->left);
        if (curr->right != nullptr)
            stk1.push(curr->right);
    }
    while (!stk2.empty()) {
        TreeNode* curr = stk2.top();
        stk2.pop();
        cout << curr->value << " ";
    }
}

int main() {
    int choice;
    TreeNode* root;
    while(choice!=3){
        cout<<endl;
        cout << "1. Construct expression tree from postfix expression\n";
        cout << "2. Construct expression tree from prefix expression\n";
        cout << "Enter your choice: ";
        cin >> choice;
        string expression;
        cout << "Enter the expression: ";
        cin >> expression;
        if (choice == 1) {
            root = constructPostfixTree(expression);
        }
        else{
            root = constructPrefixTree(expression);
        }
        cout << "Recursive In-order traversal: ";
        recursiveInorder(root);
        cout << endl;
        
        cout << "Non-recursive In-order traversal: ";
        iterativeInorder(root);
        cout << endl;
        
        cout << "Recursive Pre-order traversal: ";
        recursivePreorder(root);
        cout << endl;
        
        cout << "Non-recursive Pre-order traversal: ";
        iterativePreorder(root);
        cout << endl;
        
        cout << "Recursive Post-order traversal: ";
        recursivePostorder(root);
        cout << endl;

        cout << "Non-recursive Post-order traversal: ";
        iterativePostorder(root);
        cout << endl;
    }
    return 0;
}
