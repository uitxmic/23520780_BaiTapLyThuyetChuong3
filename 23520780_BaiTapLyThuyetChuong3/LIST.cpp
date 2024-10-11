#include "LIST.h"

void LIST::CreateList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void LIST::AddHead(LIST& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

Node* LIST::Search(SinhVien x)
{
	Node* p;
	p = pHead;
	while ((p != NULL) && !((p->info).Compare(x)))
	{
		p = p->pNext;
	}
	return p;
}

void LIST::DisplayList()
{
	Node* current = pHead;
	if (current == NULL)
	{
		cout << "The list is empty.\n";
		return;
	}
	while (current != NULL)
	{
		current->info.XuatSV();
		current = current->pNext;
	}
}

int LIST::RemoveAfterQ(Node* q, SinhVien& x)
{
	Node* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == pTail)
			{
				pTail = q;
			}
			q->pNext = p->pNext;
			x = p->info;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}

int LIST::RemoveHead(SinhVien& x)
{
	Node* p;
	if (pHead != NULL)
	{
		p = pHead;
		x = p->info;
		pHead = pHead->pNext;
		delete p;
		if (pHead == NULL)
			pTail = NULL;
		return 1;
	}
	return 0;
}

int LIST::RemoveX(SinhVien x)
{
	Node* p, * q = NULL;
	p = pHead;
	while ((p != NULL) && !(p->info.Compare(x)))
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		RemoveAfterQ(q, x);
	else
		RemoveHead(x);
	return 1;
}

void LIST::LietKe()
{
	Node* p =pHead;
	while ((p != NULL) && (p->info.DiemTB >= 5))
	{
		p->info.XuatSV();
		p = p->pNext;
	}
}

void LIST::XepLoai()
{
	Node* p = pHead;
	while (p != NULL)
	{
		if (p->info.DiemTB >= 9.0)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai xuat sac.\n";
			p = p->pNext;
		}
		else if (p->info.DiemTB >= 8.0 && p->info.DiemTB < 9.0)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai gioi.\n";
			p = p->pNext;
		}
		else if (p->info.DiemTB >= 7.0 && p->info.DiemTB < 8.0)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai kha.\n";
			p = p->pNext;
		}
		else if (p->info.DiemTB >= 6.5 && p->info.DiemTB < 7.0)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai trung binh kha.\n";
			p = p->pNext;
		}
		else if (p->info.DiemTB >= 5.0 && p->info.DiemTB < 6.5)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai trung binh.\n";
			p = p->pNext;
		}
		else if (p->info.DiemTB >= 3.6 && p->info.DiemTB < 5.0)
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai yeu.\n";
			p = p->pNext;
		}
		else
		{
			p->info.XuatSV();
			cout << "Sinh vien thuoc loai kem.\n";
			p = p->pNext;
		}
	}
	
}

void LIST::SelectionSort()
{
	Node* p, * q, * min;
	p = pHead;
	while (p != pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.DiemTB <= p->info.DiemTB)
				min = q;
			q = q->pNext;
		}
		p->info.Swap(min->info, p->info);
		p = p->pNext;
	}
}

void LIST::Insert(SinhVien x)
{
	Node* newNode = new Node;
	newNode->info = x;
	newNode->pNext = NULL;
	// neu rong, hoac diem moi là min
	if (pHead == NULL || x.DiemTB <= pHead->info.DiemTB)
	{
		newNode->pNext = pHead;
		pHead = newNode;
		if (pTail == NULL)
			pTail = newNode;
		return;
	}
	// Duyet qua list de tim vi tri
	Node* current = pHead;
	while ((current->pNext != NULL) && (current->pNext->info.DiemTB <= x.DiemTB))
	{
		current = current->pNext;
	}
	newNode->pNext = current->pNext;
	current->pNext = newNode;
	// chen vao cuoi danh sach cap nhat pTail
	if (newNode->pNext == NULL)
		pTail = newNode;
}

