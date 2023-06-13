//Assignment 1 DSA
//Harshwardhan Lokhande

#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

class node {
    
    char data;
    node *left, *right;
    
    public:
        void operand(char );
        void operators(char );
        void push(node *);
        node *pop();
        void inorder(node *);
    
};

node *stack[20];
int top = -1;
node r;

void node :: push(node *root) {
    top++;
    stack[top] = root;
}

node * node :: pop() {
    return stack[top--];
}

void node :: operand(char s) {
    
    node *root;
    root = new node;
    root->data = s;
    root->left = NULL;
    root->right = NULL;
    push(root);
}

void node :: operators(char s) {
    node *root;
    root = new node;
    root->data = s;
    root->right = pop();
    root->left = pop();
    push(root);
}

void  node :: inorder(node *root) {
    if(root) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    node r;
    int i=0;
    char s[20];
    cout<<"Enter postfix expression: ";
    cin>>s;
    
    while(s[i] != '\0') {
        
        if(isalnum(s[i])) {
            cout<<"Operand: "<<s[i]<<endl;
            r.operand(s[i]);
        }
        else {
            
            cout<<"Operator: "<<s[i]<<endl;
            r.operators(s[i]);
            
        }
        i++;
    }
    cout<<"Inorder expression: ";
    r.inorder(stack[top]);

    return 0;
}
