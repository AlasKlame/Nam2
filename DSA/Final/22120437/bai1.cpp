#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Customer {
    string id, name;
    int grape, banana, cherry;
    double totalCost;
    Customer *left, *right;
};

int getHeight(Customer *node) {
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

int getBF(Customer *node) {
    if (node == nullptr) {
        return 0;
    } else {
        return getHeight(node->left) - getHeight(node->right);
    }
}

void rotateLeft(Customer *&root) {
    Customer *y = root->right;
    root->right = y->left;
    y->left = root;
    root = y;
}

void rotateRight(Customer *&root) {
    Customer *x = root->left;
    root->left = x->right;
    x->right = root;
    root = x;
}

void balance(Customer *&root) {
    int bf = getBF(root);

    if (bf > 1 && getBF(root->left) < 0) {
        rotateLeft(root->left);
        rotateRight(root);
    }

    if (bf < -1 && getBF(root->right) > 0) {
        rotateRight(root->right);
        rotateLeft(root);
    }

    if (bf > 1) {
        rotateRight(root);
    }

    if (bf < -1) {
        rotateLeft(root);
    }
}

Customer* insertNode(Customer *root, Customer *newNode) {
    if (root == nullptr) {
        return newNode;
    }

    if (newNode->totalCost < root->totalCost) {
        root->left = insertNode(root->left, newNode);
    } else {
        root->right = insertNode(root->right, newNode);
    }

    balance(root); 
    return root;
}

void LRN(Customer *node, Customer *root) {
    if (node != nullptr) {
        LRN(node->right, root);
        LRN(node->left, root);
        if (node->totalCost <= root->totalCost) {
            cout << node->id << " ";
        }
    }
}

int main() {
    ifstream infile("bai1.in");
    
    string line;
    getline(infile, line);

    Customer *root = nullptr;

    while (getline(infile, line)) {
        stringstream ss(line);
        string id, name;
        int grape, banana, cherry;
        ss >> id >> name >> grape >> banana >> cherry;

        Customer *newNode = new Customer;
        newNode->id = id;
        newNode->name = name;
        newNode->grape = grape;
        newNode->banana = banana;
        newNode->cherry = cherry;
        newNode->totalCost = grape * 2 + banana * 4 + cherry * 5;
        newNode->left = nullptr;
        newNode->right = nullptr;

        root = insertNode(root, newNode);
    }

    if (root != nullptr) {
        LRN(root,  root);
    } else {
        cout << "-1";
    }

    infile.close();
 
    return 0;
}