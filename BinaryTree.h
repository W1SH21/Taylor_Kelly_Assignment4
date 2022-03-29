#ifndef BINARYTREE_H
#define BINARYTREE_H

template<Class T>
struct NodeType {

  T key;
  Node<T> *left;
  Node<T> *right;
  
  
}; //NodeType


template<Class T>
class BinaryTree {

private:
  Node *root;
public:
  BinaryTree(); //BinaryTree default constructor
  ~BinaryTree(); //BinaryTree default destructor
  void putItem(T*& tree, T &key); //recursive helper method called once in "insert" function
  void insert(T &key); //calls putItem
  void getPredecessor(TreeNode*& predNode); //helper method called in deleteItem to retrieve a predecessor node
  void deleteItem(T &key); // deletes an item from the BST
  void retrieve(T &item, bool &found) const; 
  void preOrder() const; //prints the tree in pre-order
  void inOrder() const; //prints the tree in in-order
  void postOrder() const; //prints the tree in post-order
  int getLength() cosnt; // returns the value "length" of the BST
  
}; //BinaryTree

#endif
