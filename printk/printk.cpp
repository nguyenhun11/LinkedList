
#include <iostream>
#include <string.h>

using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

//

void CreateEmptyList(LIST& L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void CreateList(LIST& L) {
    int n;
    cin >> n;
    while (n != -1) {
        NODE* newNode = new NODE;
        newNode->info = n;
        newNode->pNext = nullptr;
        if (L.pHead == nullptr) {
            L.pHead = newNode;
            L.pTail = newNode;
        }
        else {
            L.pTail->pNext = newNode;
            L.pTail = newNode;
        }
        cin >> n;
    }
}
int get_nth_node_from_head(NODE* head, int k) {
    if (head == nullptr) return -1;
    NODE* ptr = head;
    int i = 1;
    while (ptr->pNext != nullptr && i < k) {
        ptr = ptr->pNext;
        i++;
    }
    if (i == k) return ptr->info;
    else return -1;
}

//

int main() {
	LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	std::cin >> k;
	cout << get_nth_node_from_head(L.pHead, k);

	return 0;
}
