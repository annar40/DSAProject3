#include <iostream>>
using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

class AVLTree
{
private:
    struct TreeNode
    {
        string ID;
        string name;
        int height;
        TreeNode *left;
        TreeNode *right;
        // constructor
        TreeNode(string name, string id, int height) : ID(id), name(name), height(height), left(nullptr), right(nullptr) {}
    };

    // Tree Attributes
    bool nameFound = false;
    TreeNode *root = nullptr;

    // Tree functions
    TreeNode *insert(TreeNode *root, string name, string gatorID);

    TreeNode *searchByIDHelper(TreeNode *root, string gatorID);

    TreeNode *rotateLeft(TreeNode *node);
    TreeNode *rotateRight(TreeNode *node);
    TreeNode *rotateLeftRight(TreeNode *node);
    TreeNode *rotateRightLeft(TreeNode *node);

    void helperInorder(TreeNode *helpRoot, vector<string> &inorder);
    void helperBackwards(TreeNode *helpRoot, vector<string> &inorder);

    int maxHeightOfChildren(TreeNode *node);
    int getBalanceFactor(TreeNode *root);

public:
    ~AVLTree() { delete root; }
    void printInorder();
    void printBackwards();
    void insertStudent(string name, string gatorID);
    void searchStudentID(string gatorID);
};

AVLTree::TreeNode *AVLTree::insert(TreeNode *root, string name, string gatorID)
{
    long IDNumber = stol(gatorID);
    if (root == nullptr)
    {
        cout << "successful\n";
        return new TreeNode(name, gatorID, 0);
    }
    if (IDNumber == stol(root->ID))
    {
        cout << "unsuccessful\n";
        return root;
    }
    else if (IDNumber < stol(root->ID))
    {
        root->left = insert(root->left, name, gatorID);
    }
    else
    {
        root->right = insert(root->right, name, gatorID);
    }

    root->height = 1 + maxHeightOfChildren(root);

    /***rotations :) *********************************************************************************************/
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1) // Left-something-alignment
    {
        int leftChildBalanceFactor = getBalanceFactor(root->left);
        if (leftChildBalanceFactor >= 0) // LEFT_LEFT Alignment
        {
            // rotate RIGHT
            root = rotateRight(root);
        }
        else
        {
            // rotate LEFT RIGHT
            root = rotateLeftRight(root);
        }
    }
    else if (balanceFactor < -1) // Right-something-alignment
    {
        int rightChildBalanceFactor = getBalanceFactor(root->right);

        if (rightChildBalanceFactor <= 0) // RIGHT-RIGHT Alignment
        {
            // rotate LEFT
            root = rotateLeft(root);
        }
        else
        {
            // rotate RIGHT LEFT
            root = rotateRightLeft(root);
        }
    }
    return root;
}

int AVLTree::maxHeightOfChildren(TreeNode *node)
{
    int maxHeight = 0;
    int rightHeight = 0;
    int leftHeight = 0;
    TreeNode *rightChild = node->right;
    TreeNode *leftChild = node->left;

    if (rightChild != nullptr)
    {
        rightHeight = rightChild->height;
    }
    if (leftChild != nullptr)
    {
        leftHeight = leftChild->height;
    }

    if (rightHeight > leftHeight)
    {
        maxHeight = rightHeight;
    }
    else
    {
        maxHeight = leftHeight;
    }

    return maxHeight;
}

AVLTree::TreeNode *AVLTree::rotateLeft(TreeNode *node)
{
    TreeNode *rightChild = node->right;
    node->right = rightChild->left;
    rightChild->left = node;

    if (node->left == nullptr && node->right == nullptr)
    {
        node->height = 0;
    }
    else
    {
        node->height = 1 + maxHeightOfChildren(node);
    }

    rightChild->height = 1 + maxHeightOfChildren(rightChild);
    return rightChild;
}

AVLTree::TreeNode *AVLTree::rotateRight(TreeNode *node)
{
    TreeNode *leftChild = node->left;
    node->left = leftChild->right;
    leftChild->right = node;

    if (node->left == nullptr && node->right == nullptr)
    {
        node->height = 0;
    }
    else
    {
        node->height = 1 + maxHeightOfChildren(node);
    }
    leftChild->height = 1 + maxHeightOfChildren(leftChild);
    return leftChild;
}

AVLTree::TreeNode *AVLTree::rotateLeftRight(TreeNode *node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

AVLTree::TreeNode *AVLTree::rotateRightLeft(TreeNode *node)
{
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}
void print(vector<string> names)
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i];
        if (i != names.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << endl;
        }
    }
}

void AVLTree::insertStudent(string name, string gatorID)
{
    this->root = insert(this->root, name, gatorID);
}
void AVLTree::helperInorder(AVLTree::TreeNode *helpRoot, vector<string> &inorder)
{
    if (helpRoot == NULL)
        std::cout << "";
    else
    {
        helperInorder(helpRoot->left, inorder);
        inorder.push_back(helpRoot->name);
        helperInorder(helpRoot->right, inorder);
    }
}
void AVLTree::helperBackwards(AVLTree::TreeNode *helpRoot, vector<string> &backwards)
{
    if (helpRoot == NULL)
        std::cout << "";
    else
    {
        helperBackwards(helpRoot->right, backwards);
        backwards.push_back(helpRoot->name);
        helperBackwards(helpRoot->left, backwards);
    }
}
void AVLTree::printInorder()
{
    vector<string> namesInorder;
    helperInorder(this->root, namesInorder);
    print(namesInorder);
}
void AVLTree ::printBackwards()
{
    vector<string> namesBackwards;
    helperInorder(this->root, namesBackwards);
    print(namesBackwards);
}
int orderedMap()
{

    return -1;
}