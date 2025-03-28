#include <iostream>
using namespace std;

struct NODE {
    int val;
    NODE* next;
    NODE() {
        val = 0;
        next = nullptr;
    }
    NODE(int a) {
        val = a;
        next = nullptr;
    }
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST& L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void CreateList(LIST& L) {
    int n;
    cin >> n;
    while (n != -1) {
        NODE* newNode = new NODE(n);
        if (L.pHead == nullptr) {
            L.pHead = newNode;
            L.pTail = newNode;
        }
        else {
            L.pTail->next = newNode;
            L.pTail = newNode;
        }
        cin >> n;
    }
}

void Print_Middle(LIST L) {
    if (L.pHead == nullptr) {
        cout << "Empty List.";
        return;
    }
    NODE* i = L.pHead;
    NODE* j = L.pHead;
    while (j->next!=nullptr) {
        j = j->next;
        if (j->next != nullptr) {
            j = j->next;
            i = i->next;
        }
        else {
            break;
        }
    }
    cout << i->val;
    
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    Print_Middle(L);

    return 0;
}
