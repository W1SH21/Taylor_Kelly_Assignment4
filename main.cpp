#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char* argv[]) {
    string fix;
    while (true) {
        cout << "Enter tree type (i - int, f - float, s - std::string) : ";
        string type;
        cin >> type;
        ifstream fin;
        fin.open(argv[1]); // read input file
        if (type == "i") {
            BinaryTree<int> tree = BinaryTree<int>();
            int num;
            while (fin >> num) {
                tree.insert(num);
            }   
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "retrieve (r), ";
                cout << "length (l), ";
                cout << "in-order (n), ";
                cout << "pre-order (p), ";
                cout << "post-order (o), ";
                cout << "getNumSingleParent (s), ";
                cout << "getNumLeafNodes (f), ";
                cout << "getSumOfSubtrees (t), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    int input;
                    cout << "Item to insert: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    tree.insert(input);
                    tree.inOrder();
                } else if (uinput == "d") {
                    int input;
                    cout << "Item to delete: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    tree.deleteItem(input);
                    tree.inOrder();
                } else if (uinput == "r") {
                    int input;
                    cout << "Item to be retrieved: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    bool found = false;
                    tree.retrieve(input, found);
                    if (found == false) {
                        cout << "Item not in tree." << endl;
                    } else {
                        cout << "Item found in tree." << endl;
                    } // if
                } else if (uinput == "l") {
                    cout << "Tree Length: " << tree.getLength() << endl;
                } else if (uinput == "n") {
                    tree.inOrder();
                } else if (uinput == "p") {
                    tree.preOrder();
                } else if (uinput == "o") {
                    tree.postOrder();
                } else if (uinput == "s") {
                    cout << "Number of Single Parents: " << tree.getNumSingleParent();
                    cout << endl;
                } else if (uinput == "f") {
                    cout << "Number of leaf nodes: " << tree.getNumLeafNodes();
                    cout << endl;
                } else if (uinput == "t") {
                    int input;
                    cout << "Item to get sum of subtrees: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Sum of Subtrees: " << tree.getSumOfSubtrees(input);
                    cout << endl;
                } else if (uinput == "q") {
                    cout << "Quitting program..." << endl;
                    return 0;
                } else {
                    cout << "Command not recognized. Try again" << endl;
                }
            } // command line user input loop
        } else if (type == "f") {
            BinaryTree<float> tree = BinaryTree<float>();
            float num;
            while (fin >> num) {
                tree.insert(num);
            }   
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "retrieve (r), ";
                cout << "length (l), ";
                cout << "in-order (n), ";
                cout << "pre-order (p), ";
                cout << "post-order (o), ";
                cout << "getNumSingleParent (s), ";
                cout << "getNumLeafNodes (f), ";
                cout << "getSumOfSubtrees (t), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    float input;
                    cout << "Item to insert: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    tree.insert(input);
                    tree.inOrder();
                } else if (uinput == "d") {
                    float input;
                    cout << "Item to delete: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    tree.deleteItem(input);
                    tree.inOrder();
                } else if (uinput == "r") {
                    float input;
                    cout << "Item to be retrieved: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    bool found = false;
                    tree.retrieve(input, found);
                    if (found == false) {
                        cout << "Item not in tree." << endl;
                    } else {
                        cout << "Item found in tree." << endl;
                    } // if
                } else if (uinput == "l") {
                    cout << "Tree Length: " << tree.getLength() << endl;
                } else if (uinput == "n") {
                    tree.inOrder();
                } else if (uinput == "p") {
                    tree.preOrder();
                } else if (uinput == "o") {
                    tree.postOrder();
                } else if (uinput == "s") {
                    cout << "Number of Single Parents: " << tree.getNumSingleParent();
                    cout << endl;
                } else if (uinput == "f") {
                    cout << "Number of leaf nodes: " << tree.getNumLeafNodes();
                    cout << endl;
                } else if (uinput == "t") {
                    float input;
                    cout << "Item to get sum of subtrees: ";
                    cin >> input;
                    getline(cin, fix);
                    cout << endl;
                    cout << "Sum of Subtrees: " << tree.getSumOfSubtrees(input);
                    cout << endl;
                } else if (uinput == "q") {
                    cout << "Quitting program..." << endl;
                    return 0;
                } else {
                    cout << "Command not recognized. Try again" << endl;
                }
            } // command line user input loop
        } else if (type == "s") {
            BinaryTree<string> tree = BinaryTree<string>();
            string word;
            while (fin >> word) {
                tree.insert(word);
            }   
            getline(cin, fix);
            fin.close();
            while (true) {
                string uinput;
                cout << "insert (i), ";
                cout << "delete (d), ";
                cout << "retrieve (r), ";
                cout << "length (l), ";
                cout << "in-order (n), ";
                cout << "pre-order (p), ";
                cout << "post-order (o), ";
                cout << "getNumSingleParent (s), ";
                cout << "getNumLeafNodes (f), ";
                cout << "getSumOfSubtrees (t), ";
                cout << "quit (q)" << endl;
                cout << "Enter a command: ";
                getline(cin, uinput);
                cout << endl;
                if (uinput == "i") {
                    string input;
                    cout << "Item to insert: ";
                    getline(cin, input);
                    cout << endl;
                    tree.insert(input);
                    tree.inOrder();
                } else if (uinput == "d") {
                    string input;
                    cout << "Item to delete: ";
                    getline(cin, input);
                    cout << endl;
                    tree.deleteItem(input);
                    tree.inOrder();
                } else if (uinput == "r") {
                    string input;
                    cout << "Item to be retrieved: ";
                    getline(cin, input);
                    cout << endl;
                    bool found = false;
                    tree.retrieve(input, found);
                    if (found == false) {
                        cout << "Item not in tree." << endl;
                    } else {
                        cout << "Item found in tree." << endl;
                    } // if
                } else if (uinput == "l") {
                    cout << "Tree Length: " << tree.getLength() << endl;
                } else if (uinput == "n") {
                    tree.inOrder();
                } else if (uinput == "p") {
                    tree.preOrder();
                } else if (uinput == "o") {
                    tree.postOrder();
                } else if (uinput == "s") {
                    cout << "Number of Single Parents: " << tree.getNumSingleParent();
                    cout << endl;
                } else if (uinput == "f") {
                    cout << "Number of leaf nodes: " << tree.getNumLeafNodes();
                    cout << endl;
                } else if (uinput == "t") {
                    string input;
                    cout << "Item to get sum of subtrees: ";
                    getline(cin, input);
                    cout << endl;
                    cout << "Sum of Subtrees: " << tree.getSumOfSubtrees(input);
                    cout << endl;
                } else if (uinput == "q") {
                    cout << "Quitting program..." << endl;
                    return 0;
                } else {
                    cout << "Command not recognized. Try again" << endl;
                }
            } // command line user input loop
        } else {
            cout << "Invalid type. Please enter a valid type." << endl;
        } // if*/
    } // while
} // main
