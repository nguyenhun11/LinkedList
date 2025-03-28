
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

//

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
void Merge_Partition(LIST& L, LIST& L1, LIST& L2) {
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	bool OneOrTwo = 0;
	while (L.pHead != nullptr) {
		NODE* temp = new NODE;
		temp->info = L.pHead->info;
		temp->pNext = nullptr;
		if (!OneOrTwo) {
			PushBach(L1, temp);
			OneOrTwo = 1;
		}
		else {
			PushBach(L2, temp);
			OneOrTwo = 0;
		}
		L.pHead = L.pHead->pNext;

	}
}


//

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
}

int main() {
	LIST L, L1, L2;

	CreateEmptyList(L);
	CreateList(L);

	Merge_Partition(L, L1, L2);

	PrintList(L1);
	PrintList(L2);
	PrintList(L);

	return 0;
}
