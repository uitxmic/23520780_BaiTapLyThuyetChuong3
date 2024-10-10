#pragma once
#include "Node.h"

typedef struct LIST
{
	Node* pHead;
	Node* pTail;

	void CreateList(LIST& l);
	void AddHead(LIST &l, Node* p);
	Node* Search(SinhVien x);
	void DisplayList();
	int RemoveAfterQ(Node* q, SinhVien& x);
	int RemoveHead(SinhVien& x);
	int RemoveX(SinhVien x);
	void LietKe();
	void XepLoai();
	void SelectionSort();
	void Insert(SinhVien x);
}LIST;
