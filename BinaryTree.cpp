#include "BinaryTree.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree() {

}

template<class T>
void BinaryTree<T>::putItem(Node<T>*& tree, T &key) {  
    if (tree == NULL) {
        Node<T>* newNode = new Node<T>;
        tree = newNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->key = key;
    } else if (key > tree->key) {
        putItem(tree->right, key);
    } else {
        putItem(tree->left, key);
    } //if
} //putItem

template<class T>
void BinaryTree<T>::insert(T &key) {
    bool found = false;
    Node<T>* tempNode = root;
    getNode(tempNode, key, found);
    if (found == false) {
        putItem(root, key);
    } else {
        cout << "Item already in tree." << endl;
    } // if
} //insert

template<class T>
void BinaryTree<T>::getPredecessor(Node<T>*& predNode) const {
  while (predNode->right != NULL) {
    predNode = predNode->right;
  } //while
} //getPredecessor

template<class T>
void BinaryTree<T>::deleteNode(Node<T>*& tree) {
    Node<T>* tempNode = tree;
    Node<T>* temp2;
    if (tempNode->left == NULL) {
        temp2 = tree->right;
        delete tempNode;
        tree = temp2;
    } else if (tempNode->right == NULL) {
        temp2 = tree->left;
        delete tempNode;
        tree = temp2;
    } else {
        Node<T>* predNode = tree->left;
        getPredecessor(predNode);
        tree->key = predNode->key;
        deleteNode(predNode);
    } //if
} //deleteNode

template<class T>
void BinaryTree<T>::getNode(Node<T>*& tree, T &key, bool &found) const {
    if (tree == NULL) {
      found = false;
    } else if (key < tree->key) {
        getNode(tree->left, key, found);
    } else if (key > tree->key) {
        getNode(tree->right, key, found);
    } else {
        key = tree->key;
        found = true;
    } //if
} //findNode

template<class T>
void BinaryTree<T>::deleteItem(T &key) {
    Node<T>* tempNode = root;
    bool exists = false;
    getNode(tempNode, key, exists);
    if (exists == true) {
        deleteNode(tempNode);
    } else {
        cout << "Item not in tree." << endl;
    } // if
} //deleteItem


template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {
    Node<T>* tempNode = root;
    getNode(tempNode, item, found);
} //retrieve

template<class T>
void BinaryTree<T>::preOrderRecurse(Node<T>* tree) const {
  if (tree != NULL) {
    cout << tree->key;
    cout << " ";
    preOrderRecurse(tree->left);
    preOrderRecurse(tree->right);
  } //if
} //preOrderRecurse

template<class T>
void BinaryTree<T>::inOrderRecurse(Node<T>* tree) const {
  if (tree != NULL) {
    inOrderRecurse(tree->left);
    cout << tree->key;
    cout << " ";
    inOrderRecurse(tree->right);
  } //if
} //inOrderRecurse

template<class T>
void BinaryTree<T>::postOrderRecurse(Node<T>* tree) const {
  if (tree != NULL) {
    postOrderRecurse(tree->left);
    postOrderRecurse(tree->right);
    cout << tree->key;
    cout << " ";
  } //if
} //postOrderRecurse


template<class T>
void BinaryTree<T>::preOrder() const {
    cout << "Pre-Order: ";
    Node<T>* tempNode = root;
    preOrderRecurse(tempNode);
    cout << endl;
} //preOrder

template<class T>
void BinaryTree<T>::inOrder() const {
    cout<< "In-Order: ";
    Node<T>* tempNode = root;
    inOrderRecurse(tempNode);
    cout << endl;
} //inOrder

template<class T>
void BinaryTree<T>::postOrder() const {
    cout << "Post-Order: ";
    Node<T>* tempNode = root;
    postOrderRecurse(tempNode);
    cout << endl;
} //postOrder

template<class T>
int BinaryTree<T>::countNodes(Node<T>* tree) const {

  if (tree == NULL) {
    return 0;
  } else {
    return countNodes(tree->left) + countNodes(tree->right) + 1;
  } //if
  
} //countNodes

template<class T>
int BinaryTree<T>::getLength() const {

  return countNodes(root);

} //getLength

template<class T>
int BinaryTree<T>::singleParentCounter(Node<T>* tree) const {
  if (tree == NULL) {
    return 0;
  } else if ((tree->left == NULL) ^ (tree->right == NULL)) {
      return singleParentCounter(tree->left) + singleParentCounter(tree->right) + 1;
  } else {
    return singleParentCounter(tree->left) + singleParentCounter(tree->right);
  } //if
} //singleParentCounter

template<class T>
int BinaryTree<T>::getNumSingleParent() const {

  return singleParentCounter(root);

} //getNumSingleParent


template<class T>
int BinaryTree<T>::leafCounter(Node<T>* tree) const {

  if (tree == NULL) {
    return 0;
  } else if ((tree->left == NULL) && (tree->right == NULL)) {
    return leafCounter(tree->left) + leafCounter(tree->right) + 1;
  } else {
    return leafCounter(tree->left) + leafCounter(tree->right);
  } //if

} //leafCounter

template<class T>
int BinaryTree<T>::getNumLeafNodes() const {

  return leafCounter(root);
  
} //getNumLeafNodes

template<class T>
T BinaryTree<T>::recursiveSum(Node<T>* tree) const {
    T output = tree->key;
    if (tree->left != NULL) {
        output += recursiveSum(tree->left);
    }
    if (tree->right != NULL) {
        output += recursiveSum(tree->right);
    }
    return output;
} //recursiveSum

template<class T>
T BinaryTree<T>::getSumOfSubtrees(T &key) const {
    Node<T>* tempNode = root;
    bool found = false;
    getNode(tempNode, key, found);
    T output = tempNode->key; // HELP
    if (tempNode->left != NULL) {
        output = recursiveSum(tempNode->left);
        if (tempNode->right != NULL) {
            output += recursiveSum(tempNode->right);
        }
    } else if (tempNode->right != NULL) {
        output = recursiveSum(tempNode->right);
    }
    return output;
} //getSumOfSubtrees

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
