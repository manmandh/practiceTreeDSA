#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

typedef struct Node *node;

node createNode(int data) {
    node newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

int getSize(node root) {
    int count = 0;
    while(root) {
        ++count;
    }
    return count;
}

void insertFirst(node &head, int data) {
    if(!head) {
        return;
    }
    node temp = createNode(data);
    temp->next = head;
    head = temp;
}

void insertLast(node &head, int data) {
    node newNode = createNode(data);
    if(!head) {
        head = newNode;
    }
    node temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMiddle(node &head) {
    
}

int main() {
  
    return 0;
}