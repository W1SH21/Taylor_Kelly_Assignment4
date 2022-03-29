#include "BinaryTree.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
void BinaryTree::putItem(T*& tree, T &key) {
  
  if (root == NULL) {
    Node<T>* newNode = new Node<T>;
    tree = newNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->key = key;
  } else if (key < tree->key) {
    putItem(tree->right, itme);
  } else {
    putItem(tree->left, key);
  } //if
} //putItem

template<class T>
void BinaryTree::insert(T &key) {
  putItem(root, key);
} //insert

template<class T>
void BinaryTree::getPredecessor(T*& predNode) {
  while (predNode->right != NULL) {
    predNode = predNode->right;
  } //while
} //getPredecessor

template<class T>
void BinaryTree::deleteNode(Node*& tree) {

  Node<T>* tempNode = tree;
  if (tempNode->left == NULL) {
    tree = tree->right;
    delete tempNode;
  } else if (tempNode->right == NULL) {
    tree = tree->left;
    delete tempNode;
  } else {
    Node<T>* predNode = tree->left;
    getPredecessor(predNode);
    tree->key = predNode->key;
    deleteNode(predNode);
  } //if
} //deleteNode

template<class T>
void BinaryTree::getNode(Node<T>*& tree, T &key, bool &found) {
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
void BinaryTree::deleteItem(T &key) {

  Node<T>* tempNode = root;
  bool exists = false;
  getNode(tempNode, key, exists);
  if 
  deleteNode(tempNode);
  
} //deleteItem


template<class T>
void BinaryTree::retrieve(T &item, bool &found) const {

  Node<T>* tempNode = root;
  getNode(tempNode, item, found);

} //retrieve

template<class T>
void BinaryTree::preOrderRecurse(Node<T>* tree) {
  if (tree != NULL) {
    cout << tree->key;
    preOrderRecurse(tree->left, ofs);
    preOrderRecurse(tree->right, ofs);
  } //if
} //preOrderRecurse

template<class T>
void BinaryTree::inOrderRecurse(Node<T>* tree) {
  if (tree != NULL) {
    inOrderRecurse(tree->left, ofs);
    cout << tree->key;
    inOrderRecurse(tree->right, ofs);
  } //if
} //inOrderRecurse

template<class T>
void BinaryTree::postOrderRecurse(Node<T>* tree) {
  if (tree != NULL) {
    postOrderRecurse(tree->left, ofs);
    postOrderRecurse(tree->right, ofs);
    cout << tree->key;
  } //if
} //postOrderRecurse


template<class T>
void BinaryTree::preOrder() const {

  Node<T>* tempNode = root;
  preOrderRecurse(root, outFile);

} //preOrder

template<class T>
void BinaryTree::inOrder() const {

  Node<T>* tempNode = root;
  inOrderRecurse(tempNode, outFile);

} //inOrder

template<class T>
void Binarytree::postOrder() const {

  Node<T>* tempNode = root;
  postOrderRecurse(tempNode, outFile);
  
} //postOrder

template<class T>
int BinaryTree::countNodes(Node<T>* tree) {

  if (tree == NULL) {
    return 0;
  } else {
    return countNodes(tree->left) + countNodes(tree->right) + 1;
  } //if
  
} //countNodes

template<class T>
void BinaryTree::getLength() const {

  return countNodes(root);

} //getLength

template<class T>
int BinaryTree::singleParentCounter(Node<T>* tree) {
  if (tree == NULL) {
    return 0;
  } else if ((tree->left == NULL) ^ (tree->right == NULL)) {
      return singleParentCounter(tree->left) + singleParentCounter(tree->right) + 1;
  } else {
    return singleParentCounter(tree->left) + singleParentCounter(tree->right);
  } //if
} //singleParentCounter

template<class T>
int BinaryTree::getNumSingleParent() {

  return singleParentCounter(root);

} //getNumSingleParent


template<class T>
int BinaryTree::leafCounter(Node<T>* tree) {

  if (tree == NULL) {
    return 0;
  } else if ((tree->left == NULL) && (tree->right == NULL)) {
    return leafCounter(tree->left) + leafCounter(tree->right) + 1;
  } else {
    return leafCounter(tree->left) + leafCounter(tree->right);
  } //if

} //leafCounter

template<class T>
int BinaryTree::getNumLeafNodes() {

  return leafCounter(root);
  
} //getNumLeafNodes


