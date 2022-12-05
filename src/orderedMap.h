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
       string carData;
       string name;
       int height;
       TreeNode *left;
       TreeNode *right;
       // constructor
       TreeNode(string name, string id, int height) : carData(id), name(name), height(height), left(nullptr), right(nullptr) {}
   };

   // Tree Attributes
   TreeNode *root = nullptr;

   // Tree functions
   TreeNode *insert(TreeNode *root, string vehicleName, string carData);

   TreeNode *rotateLeft(TreeNode *node);
   TreeNode *rotateRight(TreeNode *node);
   TreeNode *rotateLeftRight(TreeNode *node);
   TreeNode *rotateRightLeft(TreeNode *node);

   void helperInorder(TreeNode *helpRoot, vector<string> &inorder, int &counter, int userInput);
   void helperBackwards(TreeNode *helpRoot, vector<string> &inorder, int &counter, int userInput);

   int maxHeightOfChildren(TreeNode *node);
   int getBalanceFactor(TreeNode *root);

public:
   // ~AVLTree() { delete root; }
   void printInorder(int userInput);
   void printBackwards(int userInput);
   void insertCar(string name, string carData);
   void printVehicleComparison(int userInput);
};

AVLTree::TreeNode *AVLTree::insert(TreeNode *root, string vehicleName, string carData)
{
   long userCarData = stol(carData);
   if (root == nullptr)
   {
       return new TreeNode(vehicleName, carData, 0);
   }
   if (userCarData == stol(root->carData))
   {
       return root;
   }
   else if (userCarData < stol(root->carData))
   {
       root->left = insert(root->left, vehicleName, carData);
   }
   else
   {
       root->right = insert(root->right, vehicleName, carData);
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
   if (names.size() == 0)
   {
       cout << "No vehicles with greater values found! \n";
       cout << "------------------------------------" << endl;
   }
   else
   {
       cout << "Vehicles with greater values than your car: ";
       for (int i = 0; i < names.size(); i++)
       {
           cout << names[i];
           if (i != names.size() - 1)
           {
               cout << " ||| ";
           }
           else
           {
               cout << " ";
           }
       }
       cout << "\n------------------------------------" << endl;
   }
}
void printLessThanVals(vector<string> names)
{
   if (names.size() == 0)
   {
       cout << "------------------------------------" << endl;
       cout << "No vehicles with lower values found! \n";
       cout << "------------------------------------" << endl;
   }
   else
   {
       cout << "------------------------------------" << endl;
       cout << "Vehicles with lower values than your car: ";
       for (int i = names.size()-1; i >= 0; i--)
       {
           cout << names[i];
           if (i != 0)
           {
               cout << " ||| ";
           }
           else
           {
               cout << " ";
           }
       }
       cout << endl;
       cout << "------------------------------------" << endl;
   }
}

void AVLTree::insertCar(string vehicleName, string carData)
{
   this->root = insert(this->root, vehicleName, carData);
}
void AVLTree::helperInorder(AVLTree::TreeNode *helpRoot, vector<string> &inorder, int &counter, int userInput)
{

   if (helpRoot == NULL)
       std::cout << "";
   else
   {
       helperInorder(helpRoot->left, inorder, counter, userInput);
       if (stoi(helpRoot->carData) > userInput && counter < 4)
       {
           counter++;
           string temp = helpRoot->name;
           temp.append(" with a value of: ");
           temp.append(helpRoot->carData);
           inorder.push_back(temp);
       }
       helperInorder(helpRoot->right, inorder, counter, userInput);
   }
}
void AVLTree::helperBackwards(AVLTree::TreeNode *helpRoot, vector<string> &backwards, int &counter, int userInput)
{
   if (helpRoot == NULL)
       std::cout << "";
   else
   {
       helperBackwards(helpRoot->right, backwards, counter, userInput);
       if (stoi(helpRoot->carData) < userInput && counter < 4)
       {
           counter++;
           string temp = helpRoot->name;
           temp.append(" with a value of: ");
           temp.append(helpRoot->carData);
           backwards.push_back(temp);
       }
       helperBackwards(helpRoot->left, backwards, counter, userInput);
   }
}
void AVLTree::printInorder(int userInput)
{
   vector<string> namesInorder;
   int counter = 0;
   helperInorder(this->root, namesInorder, counter, userInput);
   print(namesInorder);
}
void AVLTree ::printBackwards(int userInput)
{
   vector<string> namesBackwards;
   int counter = 0;
   helperBackwards(this->root, namesBackwards, counter, userInput);
   printLessThanVals(namesBackwards);
}
void AVLTree::printVehicleComparison(int userInput)
{
   cout << "Check out how your car stacks up to similar vehicles!\n\n";
   printBackwards(userInput);
   cout << "    ----------      " << endl;
   cout << "  /            \\      " << endl;
   cout << " /              \\      " << endl;
   cout << "|  Your car: " << userInput << "  |" << endl;
   cout << " \\              /      " << endl;
   cout << "  \\            /      " << endl;
   cout << "    ----------      " << endl;
   cout << "------------------------------------" << endl;
   printInorder(userInput);
}

int AVLTree::getBalanceFactor(TreeNode *root)
{
   int LH = 0;
   int RH = 0;
   if (root->left != nullptr)
   {
       LH = root->left->height + 1;
   }
   if (root->right != nullptr)
   {
       RH = root->right->height + 1;
   }
   return LH - RH;
}

