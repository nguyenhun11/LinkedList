
#include <iostream>
#include <cstdlib>
#include <ctime>
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

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	//if (p == NULL)
	//		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail = p;
	}
}

void CreateEmptyList(LIST& L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST& L) {
	NODE* p;
	int x, n;
	cin >> n; // Số lượng phần tử của danh sách
	while (n-- > 0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}
//////

void Merge_Partition(LIST& L, LIST& L1, LIST& L2) {
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	bool OneOrTwo = 0;
	while (L.pHead != nullptr) {
		NODE* temp = L.pHead;
		L.pHead = L.pHead->pNext;
		temp->pNext = nullptr;
		if (!OneOrTwo) {
			AddTail(L1, temp);
		}
		else {
			AddTail(L2, temp);
		}
		OneOrTwo = !OneOrTwo;
	}
}
void Merge_2_Sorted_LL(LIST& L, LIST& L1, LIST& L2) {
	CreateEmptyList(L);
	NODE* temp;
	while (L1.pHead != nullptr && L2.pHead != nullptr) {
		if (L1.pHead->info < L2.pHead->info) {
			temp = L1.pHead;
			L1.pHead = L1.pHead->pNext;
			temp->pNext = nullptr;
			AddTail(L, temp);
		}
		else {
			temp = L2.pHead;
			L2.pHead = L2.pHead->pNext;
			temp->pNext = nullptr;
			AddTail(L, temp);
		}
	}
	while (L1.pHead != nullptr) {
		temp = L1.pHead;
		L1.pHead = L1.pHead->pNext;
		temp->pNext = nullptr;
		AddTail(L, temp);
	}
	while (L2.pHead != nullptr) {
		temp = L2.pHead;
		L2.pHead = L2.pHead->pNext;
		temp->pNext = nullptr;
		AddTail(L, temp);
	}
}
void mergesort_ascending(LIST& L) {
	if (L.pHead == nullptr || L.pHead->pNext == nullptr) return;
	LIST L1, L2;
	Merge_Partition(L, L1, L2);
	mergesort_ascending(L1);
	mergesort_ascending(L2);
	Merge_2_Sorted_LL(L, L1, L2);
}



//////

int length(NODE* p) {
	int i = 0;
	while (p) {
		i++;
		p = p->pNext;
	}
	return i;
}

void PrintList(NODE* p) {
	if (p == NULL)
		cout << "Empty List.";
	else {
		cout << length(p) << endl;
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
	mergesort_ascending(L);
	PrintList(L.pHead);

	return 0;
}

