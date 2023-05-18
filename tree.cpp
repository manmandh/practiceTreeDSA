#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

typedef struct Node *node;

node createNode(char c){
    node myNode = new Node();
    myNode->data = c;
    myNode->left = NULL;
    myNode->right = NULL;
    return myNode;
}

void addNodeLeft(node &root, node &nodeLeft){
    root->left = nodeLeft;
}

void addNodeRight(node &root, node &nodeRight){
    root->right = nodeRight;
}

void inorder(node &root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(node &root){
    if(root){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node &root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

//thêm, xóa, sửa, in chiều rộng, chiều sâu, tìm mức của giá trị bất kì, chuyển từ Tree sang Array
void insertNode(node &root, int x){
    if(root==NULL){
        node myNode = createNode(x);
        root = myNode;
    }else{
        if(x<root->data){
            insertNode(root->left,x);
        }else if(x>root->data){
            insertNode(root->right, x);
        }
    }
}

void deleteNode(node &root, int data){
    if(root==NULL){
        return;
    }else{
        if(data<root->data){
            deleteNode(root->left, data);
        }else if(data>root->data){
            deleteNode(root->right, data);
        }else{
            // data->root=data;
            node x = root;
            if(root->left==NULL){
                root = root->right;
            }else if(root->right==NULL){
                root = root->left;
            }
            delete x;
        }
    }
}

int main() {
    node rootA = createNode('A');
    node rootB = createNode('B');
    node rootC = createNode('C');
    node rootD = createNode('D');
    node rootE = createNode('E');
    node rootF = createNode('F');
    node rootG = createNode('G');

    addNodeLeft(rootA, rootB);
    addNodeRight(rootA, rootC);
    addNodeLeft(rootB, rootD);
    addNodeRight(rootB, rootE);
    addNodeLeft(rootC, rootF);
    addNodeRight(rootC, rootG);

    cout << "Inorder: " << endl;
    inorder(rootA);
    //trai giua phai

    cout << "\nPreorder: " << endl;
    preorder(rootA);
    //giua trai phai

    cout << "\nPostorder: " << endl;
    postorder(rootA);
    //trai phai giua

    cout << "\nInsert Node Inorder: " << endl;
    insertNode(rootA, 'Z');
    inorder(rootA);

    cout << "\nDelete Node Inorder: " << endl;
    deleteNode(rootA, 'G');
    inorder(rootA);
    return 0;
}