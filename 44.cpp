#include <iostream>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to perform a postorder traversal of a binary tree
void postOrderTraversal(TreeNode *root)
{
    if (root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Postorder Traversal of the Binary Tree: ";
    postOrderTraversal(root);
    cout << endl;

    // Clean up the binary tree (free memory)
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}