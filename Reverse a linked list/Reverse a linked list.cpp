
#include <iostream>
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

//////
void CreateEmptyList(LIST& L) {
	L.pHead = nullptr;
	L.pTail = nullptr;
}
void PushBach(LIST& L, NODE* x) {
	if (L.pHead == nullptr) {
		L.pHead = x;
		L.pTail = x;
	}
	else {
		L.pTail->pNext = x;
		L.pTail = x;
	}
}
void CreateList(LIST& L) {
	int n;
	cin >> n;
	while (n != -1) {
		NODE* newNode = new NODE;;
		newNode->info = n;
		newNode->pNext = nullptr;
		PushBach(L, newNode);
		cin >> n;
	}
}
void Reverse_LinkedList(LIST& L) {
	L.pTail = L.pHead;
	NODE* curr = L.pHead;
	NODE* prev = nullptr;
	NODE* next;
	while (curr != nullptr) {
		next = curr->pNext;
		curr->pNext = prev;
		prev = curr;
		curr = next;
	}
	L.pHead = prev;
}


//////


void PrintList(const LIST& L) {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else {
		p = L.pHead;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main() {
	LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Reverse_LinkedList(L);

	PrintList(L);

	return 0;
}
