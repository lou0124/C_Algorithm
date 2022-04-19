#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* merge(Node* L1, Node* L2);
void mg_partition(Node* temp, Node** L1, Node** L2);
void mergeSort(Node** L);

void mergeSort(Node** L)
{
	Node* temp = *L;
	Node* L1, * L2;
	if (temp == NULL || temp->next == NULL)  return;
	mg_partition(temp, &L1, &L2);
	mergeSort(&L1);
	mergeSort(&L2);
	*L = merge(L1, L2);
}

Node* merge(Node* L1, Node* L2)
{
	Node* result = NULL;
	if (L1 == NULL)	return L2;
	else if (L2 == NULL) return L1;
	if (L1->data < L2->data)
	{
		result = L1;
		result->next = merge(L1->next, L2);
	}
	else
	{
		result = L2;
		result->next = merge(L1, L2->next);
	}
	return result;
}

void mg_partition(Node* temp, Node** L1, Node** L2)
{
	Node* fast, * slow;
	slow = temp;
	fast = temp->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*L1 = temp;
	*L2 = slow->next;
	slow->next = NULL;
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void addNode(Node** head, int elem)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	Node* temp;
	newnode->data = elem;
	newnode->next = NULL;
	if (*head == NULL)* head = newnode;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

int main()
{
	Node* L = NULL;
	int n, i, elem;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &elem);
		addNode(&L, elem);
	}
	mergeSort(&L);
	printList(L);
	return 0;
}
