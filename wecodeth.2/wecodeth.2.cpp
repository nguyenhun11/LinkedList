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

void PrintList_Odd(NODE* ptr) {
    if (ptr == nullptr) {
        cout << "Empty List.";
        return;
    }
    bool hasOddNumber = 0;
    while (ptr != nullptr) {
        if (ptr->val % 2) {
            hasOddNumber = 1;
            cout << ptr->val << " ";
        }
        ptr = ptr->next;
    }
    if (!hasOddNumber) cout << "Khong co so le trong mang.";
}


int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
