#include<iostream>
#include "Queue.h"
#include "binarytreenode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    Queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.enqueue(root);

    while(!pendingNodes.is_empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.dequeue();
        cout<<"Enter left child for "<<currentNode->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int>* child =
                new BinaryTreeNode<int>(leftChildData);
            currentNode->left = child;
            pendingNodes.enqueue(child);
        }
        cout<<"Enter right child for "<<currentNode->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int>* child =
                new BinaryTreeNode<int>(rightChildData);
            currentNode->right = child;
            pendingNodes.enqueue(child);
        }        
    }
    return root;
}

void preorder(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    cout<<"--"<<root->data;
    preorder(root->left);
    preorder(root->right);    
}

int numberOfNodes(BinaryTreeNode<int>* root) {
    if(!root)
        return 0;
    return (1 + numberOfNodes(root->left) + numberOfNodes(root->right));
}

bool findNode(BinaryTreeNode<int>* root, int item) {
    if(!root)
        return false;
    if(root->data = item)
        return true;
    bool temp = findNode(root->left, item);
    if(temp)
        return temp;
    else
        return findNode(root->right, item);
}

void mirrorTree(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorder(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    inorder(root->left);
    cout<<"--"<<root->data;
    inorder(root->right);
}

void postorder(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<"--"<<root->data;
}

int sumOfNodes(BinaryTreeNode<int>* root) {
    if(!root)
        return 0;
    return (root->data + sumOfNodes(root->left)
            + sumOfNodes(root->right));
}

bool structurallyIdentical(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->data != root2->data)
        return false;
    bool temp = structurallyIdentical(root1->left, root2->left);
    if(!temp)
        return temp;
    return structurallyIdentical(root1->right, root2->right);
}

void printNodesWithoutSibling(BinaryTreeNode<int>* root, bool flag) {
    if(!root)
        return;

    if(flag)
        cout<<root->data<<endl;

    if((!root->left && root->right) || (root->left && !root->right)) {
        printNodesWithoutSibling(root->left, true);
        printNodesWithoutSibling(root->right, true);
        return;
    }
    printNodesWithoutSibling(root->left, false);
    printNodesWithoutSibling(root->right, false);
}

BinaryTreeNode<int>* removeLeaves(BinaryTreeNode<int>* root) {
    if(!root)
        return root;
    if(!root->left && !root->right) {
        delete root;
        return NULL;
    }
    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);
    return root;
}

void LevelOrderTraversal(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    Queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.enqueue(root);
    pendingNodes.enqueue(NULL);

    while(!pendingNodes.is_empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.dequeue();
        if(!currentNode) {
            cout<<endl;
            if(pendingNodes.is_empty()) {
                return;
            }
            else {
                pendingNodes.enqueue(NULL);
            }
        }
        else {
            cout<<"--"<<currentNode->data;
            if(currentNode->left)
                pendingNodes.enqueue(currentNode->left);
            if(currentNode->right)
                pendingNodes.enqueue(currentNode->right);
        }
    }
    cout<<endl;
}


void zigzagTraversal(BinaryTreeNode<int>* root) {
    if(!root)
        return;
    Queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.enqueue(root);
    pendingNodes.enqueue(NULL);
    bool flag = true;
    stack_using_node<BinaryTreeNode<int>*> s;
    while(!pendingNodes.is_empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.dequeue();
        if(!currentNode) {
            if(pendingNodes.is_empty()) {
                return;
            }
            else {
                if(!flag) {
                    while(!s.isEmpty()) {
                        BinaryTreeNode<int>* temp = s.pop();
                        cout<<"--"<<temp->data;
                    }
                    pendingNodes.enqueue(NULL);
                    flag = true;
                }
                else {
                    cout<<endl;
                    flag = false;
                }
            }
        }
        else {
            if()
        }
    }


}

int main() {

    BinaryTreeNode<int>* root = takeInputLevelWise();
    //preorder(root);
    //cout<<endl;
    //cout<<"Number of nodes in tree: "<<numberOfNodes(root)<<endl;
    //cout<<findNode(root, 3)<<endl;
    //mirrorTree(root);
    //preorder(root);
    //cout<<endl;
    /*inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;*/
    //printNodesWithoutSibling(root, true);
    //cout<<endl;
    //removeLeaves(root);
    //preorder(root);
    cout<<"Level Order Traversal: "<<endl;
    LevelOrderTraversal(root);
    delete(root);

return 0;
}
