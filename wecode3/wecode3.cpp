

#include <iostream>
#include <cmath>
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


void CreateEmptyList(LIST& L) {
	L.pHead = nullptr;
	L.pTail = nullptr;
}
void CreateList(LIST& L) {
    while (1) {
        int n;
        cin >> n;
        if (n == -1) break;
        NODE* newNode = new NODE();
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
    }

}
void PrintEvenNumbers(NODE* L) {
    if (L == nullptr) {
        cout << "Danh sach rong.";
        return;
    }
    NODE* ptr = L;
    bool hasEvenNumber = 0;
    while (ptr != nullptr) {
        if (ptr->info % 2 == 0) {
            hasEvenNumber = 1;
            cout << ptr->info << " ";
            
        }
        ptr = ptr->pNext;
    }
    if (!hasEvenNumber) cout << "Danh sach khong co so chan.";
}


int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	PrintEvenNumbers(L.pHead);

	return 0;
}
