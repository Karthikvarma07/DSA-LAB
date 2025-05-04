#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Node structure for the Expression Tree
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Construct Expression Tree from postfix expression
Node* constructExpressionTree(string postfix) {
    stack<Node*> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(new Node(ch)); // Operand
        } else {
            Node* op2 = st.top(); st.pop();
            Node* op1 = st.top(); st.pop();
            Node* newNode = new Node(ch);
            newNode->left = op1;
            newNode->right = op2;
            st.push(newNode); // Push subtree back to stack
        }
    }
    return st.top();
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    string postfix;
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\n1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                root = constructExpressionTree(postfix);
                cout << "Expression Tree Constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
