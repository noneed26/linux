#include <iostream>
#include <queue>
using namespace std;
// Node structure for BST
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// Insert a node into BST
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
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
// Inorder traversal (Left, Root, Right)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Level Order Traversal (BFS)
void levelOrder(Node *root)
{
    if (root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
        
    }
}
// Search for a node in BST
bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}
// Find height of BST
int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
// Convert BST to its Mirror image
Node *mirror(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *mirrored = new Node(root->data);
    mirrored->left = mirror(root->right);
    mirrored->right = mirror(root->left);
    return mirrored;
}
// Get inorder successor (smallest node in right subtree)
Node *getInorderSuccessor(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// Delete a node from BST
Node *delNode(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (val < root->data)
    {
        root->left = delNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delNode(root->right, val);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left == NULL || root->right == NULL)
        {
            return (root->left != NULL) ? root->left : root->right;
        }
        Node *temp = getInorderSuccessor(root->right);
        root->data = temp->data;
        root->right = delNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    int choice, value;
    cout << "Enter elements to insert (-1 to stop): ";
    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        root = insert(root, value);
    }
    while (true)
    {
        cout << "\nOperations:\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Display\n";
        cout << "3. Search\n";
        cout << "4. Find Height\n";
        cout << "5. Level Order Display\n";
        cout << "6. Delete\n";
        cout << "7. Mirror\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (search(root, value) ? "Found" : "Not Found") << endl;
            break;
        case 4:
            cout << "Height: " << height(root) << endl;
            break;
        case 5:
            levelOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            root = delNode(root, value);
            break;
        case 7:
            root = mirror(root);
            cout << "BST Mirrored.\n";
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}