#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct Node {
    T key;
    Node<T> *left;
    Node<T> *right;    
}; //NodeType


template<class T>
class BinaryTree {
    
private:
    Node<T> *root;
    void preOrderRecurse(Node<T>* tree) const;
    void inOrderRecurse(Node<T>* tree) const;
    void postOrderRecurse(Node<T>* tree) const;
    void deleteNode(Node<T>*& tree);
    int countNodes(Node<T>* tree) const;
    void getNode(Node<T>*& tree, T &key, bool &found) const;
    int singleParentCounter(Node<T>* tree) const;
    int leafCounter(Node<T>* tree) const;
    T recursiveSum(Node<T>* tree) const;
    //various recursive helper functions for the functions described below
public:
    BinaryTree(); //BinaryTree default constructor
    ~BinaryTree(); //BinaryTree default destructor
    void putItem(Node<T>*& tree, T &key); //recursive helper method called once in "insert" function
    void insert(T &key); //calls putItem
    void getPredecessor(Node<T>*& predNode) const;
    //helper method called in deleteItem to retrieve a predecessor node
    void deleteItem(T &key); // deletes an item from the BST
    void retrieve(T &item, bool &found) const; 
    void preOrder() const; //prints the tree in pre-order
    void inOrder() const; //prints the tree in in-order
    void postOrder() const; //prints the tree in post-order
    int getLength() const; // returns the value "length" of the BST
    int getNumSingleParent() const; //prints the amount of single parents in the BST
    int getNumLeafNodes() const; //returns the amount of leaf nodes in the SBT
    T getSumOfSubtrees(T &key) const; //returns the sum of both subtrees of a given node
    
}; //BinaryTree

#endif
