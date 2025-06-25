#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* deleteNode(Node* root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp && temp->left != nullptr)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(Node* root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int findMin(Node* root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root)
{
    while (root && root->right != nullptr)
    {
        root = root->right;
    }
    return root->data;
}

void postorderTraversal(Node* root)
{
    if (root != nullptr)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

void levelOrderTraversal(Node* root)
{
    if (root == nullptr) return;

    vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty())
    {
        Node* current = queue.front();
        queue.erase(queue.begin());

        cout << current->data << " ";

        if (current->left != nullptr)
        {
            queue.push_back(current->left);
        }
        
        if (current->right != nullptr)
        {
            queue.push_back(current->right);
        }
    }
}

bool search(Node* root, int val)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
}

int main()
{
    Node* root = nullptr;
    vector<int> values = {5, 3, 8, 11, 4, 7, 19};

    for (int val : values)
    {
        root = insert(root, val);
    }

    cout << "Minimum value in the BST: " << findMin(root) << endl;

    cout << "Maximum value in the BST: " << findMax(root) << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    int searchValue = 4;
    if (search(root, searchValue))
    {
        cout << "Value " << searchValue << " found in the BST." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the BST." << endl;
    }

    searchValue = 10;
    if (search(root, searchValue))
    {
        cout << "Value " << searchValue << " found in the BST." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the BST." << endl;
    }

    int deleteValue = 3;
    root = deleteNode(root, deleteValue);

    cout << "Inorder Traversal after deleting " << deleteValue << ": ";
    inorderTraversal(root);
    cout << endl;
    deleteValue = 5;
    root = deleteNode(root, deleteValue);

    cout << "Inorder Traversal after deleting " << deleteValue << ": ";
    inorderTraversal(root);
    cout << endl;


    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
