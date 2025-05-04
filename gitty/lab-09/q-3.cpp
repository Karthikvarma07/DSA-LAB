#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Search for a value in the BST
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (search(root, value) ? "Value found!" : "Value not found!") << endl;
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
