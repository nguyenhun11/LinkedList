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
void CreateEmptyList(NODE*& L) {
    L = nullptr;
}
void CreateList(NODE*& L) {
    int n;
    NODE* ptr = L;
    while (1) {
        cin >> n;
        if (n == -1) break;
        NODE* newNODE = new NODE(n);
        if (L == nullptr) {
            L = newNODE;
            ptr = newNODE;
        }
        else {
            ptr->next = newNODE;
            ptr = newNODE;
        }
    }
}
void PrintList(NODE* L) {
    if (L == nullptr) {
        cout << "Empty List.";
        return;
    }
    NODE* ptr = L;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}

int main() {
    NODE* pHead;
    CreateEmptyList(pHead);

    CreateList(pHead);
    PrintList(pHead);

    return 0;
}
