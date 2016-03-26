#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data): left(NULL), right(NULL){
        this->data = data;
    }

    ~BinaryTreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
#endif
