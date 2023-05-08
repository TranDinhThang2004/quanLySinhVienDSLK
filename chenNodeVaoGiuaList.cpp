#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

node* makeNode(int x)
{
	node *newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void duyet(node *head)
{
	while(head != NULL)
	{
		cout << head->data << ' ' << endl;
		head = head->next;
	}
}

int count(node *head)
{
	int dem = 0;
	while(head != NULL)
	{
		++dem;
		head = head->next;
	}
	return dem;
}
void pushFront(node **head, int x)
{
	node* newNode = makeNode(x);
	newNode->next = *head;
	*head = newNode;	
}
void pushBack(node **head, int x)
{
	node* newNode = makeNode(x);
	if(*head == NULL)
	{
		*head = newNode;
	}
	node* temp = *head;
	while(temp->next != NULL)
	{
		temp = temp->next; 
	}
	temp->next = newNode;
}
void insert(node **head,int k, int x)
{
	int n = count(*head);
	if(k < 1 || k > n + 1) return;
	if(k == 1)
	{
		pushFront(head, x);
		return;
	}
	node *temp = *head;
	for(int i = 1; i <= k-2; i++)
	{
		temp = temp->next;
	}
	// temp la node thu k-1
	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}
void popFront(node **head)
{
	if(*head == NULL) return;
	node *temp = *head;
	*head = (*head)->next;
	delete temp;
}
void popBack(node **head)
{
	if(*head == NULL) return;
	node *temp = *head;
	//Xu ly truong hop chi co 1 node
	if(temp->next == NULL)
	{
		*head = NULL; delete temp;
		return;	
	} 
	while(temp->next->next != NULL)
	{
		temp = temp->next; 
	}
	node *last = temp->next; // node cuoi
	temp->next = NULL;
	delete last;
}
void erase(node **head, int k)
{
	int n = count(*head);
	if(k < 1 || n > n) return;
	if(k == 1) popFront(head);
	else
	{
		node *temp = *head;
		for(int i = 1; i <= k-2; i++)
		{
			temp = temp->next; 
		}
		//temp : k - 1
		node *kth = temp->next; // node thu k
		// cho k-1 => ket noi voi node thu k+1
		temp->next = kth->next;
		delete kth;
	}
	
}

int main() {
	node *head = NULL;
	while(1)
	{
	cout << "--------------------------\n";
	cout << "1. Them vao dau\n"	;
	cout << "2. Them vao cuoi\n";
	cout << "3. Them vao giua\n";
	cout << "5. Xoa node khoi dau DS\n";
	cout << "6. Xoa node o cuoi DS\n";
	cout << "7. Xoa node o giua DS\n";
	cout << "4. Duyet\n";
	cout << "0. Thoat\n";
	cout << "--------------------------\n";
	cout << "Nhap lua chon: ";
	int lc; cin >> lc;
	if(lc == 1 )
	{
		int x; cout << "Nhap x: "; cin >> x;
		pushFront(&head, x);
	}
	else
	if(lc == 2)
	{
		int x; cout << "Nhap x: "; cin >> x;
		pushBack(&head, x);
	}
	else
	if(lc == 3)
	{
		int x, k; 
		cout << "Nhap x: " ; cin >> x;
		cout << "Nhap k: " ; cin >> k;
		insert(&head, k, x);
	}
	else
	if(lc == 4)
	{
		duyet(head);
	}
	else
	if(lc == 5)
	{
	popFront(&head);	
	}
	else
	if(lc == 6)
	{
		popBack(&head);
	}
	else
	if(lc == 7)
	{
		int k; cout << "Nhap vi tri can xoa"; cin >> k;
		erase(&head,k);
	}
	else
	if(lc == 0)
	{
		break;
	}
}
	
	return 0;
}
