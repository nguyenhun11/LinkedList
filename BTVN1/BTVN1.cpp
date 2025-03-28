
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int a) {
        val = a;
        next = nullptr;
    }
};
struct LIST {
    ListNode* pHead;
    ListNode* pTail;
};

void CreateEmptyList(LIST& L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}
void CreateList(LIST& L) {
    while (1) {
        int n;
        cin >> n;
        if (n == -1) break;
        ListNode* newNode = new ListNode(n);
        if (L.pHead == nullptr) {
            L.pHead = newNode;
            L.pTail = newNode;
        }
        else {
            newNode->next = L.pHead;
            L.pHead = newNode;
        }
    }

}
void PrintList(LIST A) {
    ListNode* L = A.pHead;
    if (L == nullptr) {
        cout << "Empty List.";
        return;
    }

    ListNode* ptr = L;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L);

    return 0;
}
