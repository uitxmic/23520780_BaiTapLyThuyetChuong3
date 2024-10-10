#pragma once
#include "SinhVien.h"

typedef struct Node
{
	SinhVien info;
	Node* pNext;

	static Node* CreateNode(SinhVien x);
}Node;

