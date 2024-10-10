#include "Node.h"

Node* Node::CreateNode(SinhVien x)
{
	Node* p;
	p = new Node;
	if (p == NULL) exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}
