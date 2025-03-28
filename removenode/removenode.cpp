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

void CreateEmptyList(NODE*& head) {
    head = nullptr;
}

void CreateList(NODE*& head) {
    int n;
    NODE* ptr = head;
    cin >> n;
    while (n != -1) {
        NODE* newNode = new NODE(n);
        if (head == nullptr) {
            head = newNode;
            ptr = newNode;
        }
        else {
            ptr->next = newNode;
            ptr = newNode;
        }
        cin >> n;
    }
}

void PrintList(NODE* head) {
    if (head == nullptr) {
        cout << "Empty List.";
        return;
    }
    NODE* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}
void RemoveX(NODE*& head, int X) {
    if (head == nullptr) return;
    if (head->val == X) {
        head = head->next;
        return;
    }
    NODE* ptr = head;
    while (ptr->next != nullptr && ptr->next->val != X) {
        ptr = ptr->next;
    }
    if (ptr->next == nullptr && ptr->val == X) {
        delete ptr;
    }
    else if (ptr->next == nullptr && ptr->val != X) {
        return;
    }
    else {
        ptr->next = ptr->next->next;
    }
}

int main() {
	NODE* pHead;
	int X;
	CreateEmptyList(pHead);

	CreateList(pHead);
	std::cin >> X;
	RemoveX(pHead, X);
	PrintList(pHead);

	return 0;
}
