
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
void Merge_2_Sorted_LL(LIST& L, LIST& L1, LIST& L2) {
	CreateEmptyList(L);
	while (L1.pHead != nullptr && L2.pHead != nullptr) {
		NODE* temp = new NODE;
		if (L1.pHead->info < L2.pHead->info) {
			temp->info = L1.pHead->info;
			temp->pNext = nullptr;
			PushBach(L, temp);
			L1.pHead = L1.pHead->pNext;
		}
		else {
			temp->info = L2.pHead->info;
			temp->pNext = nullptr;
			PushBach(L, temp);
			L2.pHead = L2.pHead->pNext;
		}
	}
	while (L1.pHead != nullptr) {
		NODE* temp = new NODE;
		temp->info = L1.pHead->info;
		temp->pNext = nullptr;
		PushBach(L, temp);
		L1.pHead = L1.pHead->pNext;
	}
	while (L2.pHead != nullptr) {
		NODE* temp = new NODE;
		temp->info = L2.pHead->info;
		temp->pNext = nullptr;
		PushBach(L, temp);
		L2.pHead = L2.pHead->pNext;
	}
}




//////

void PrintList(LIST L) {
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
	cout << endl;
}int main() {
	LIST L, L1, L2;

	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	CreateList(L2);


	Merge_2_Sorted_LL(L, L1, L2);

	PrintList(L);
	PrintList(L1);
	PrintList(L2);

	return 0;
}
