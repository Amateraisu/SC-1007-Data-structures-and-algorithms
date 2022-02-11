#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
// Write your code here

    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;
    ListNode* p1 = NULL;
    ListNode* p2 = NULL;
    ListNode* ptr = head;
    
    //counter 
    int counter = 0;
	int number = 0;

	while (ptr != NULL)
	{
		number++;
		ptr = ptr->next;
	}
	
    //reverse right - left times 
    
    if (head == NULL || start==end || start>end || end>number-1)
    {
        return head;
    }
    
    while (counter<start)
    {
        prev = current;
        current = current->next;
        counter++;
    }
    
    p1 = prev;
    prev = NULL;
    
    p2 = current;

    for (int i = 0 ; i <= (end - start);i++)
    {
        next = current -> next;
        current->next = prev;
        prev = current;
        current = next;      

    }


    if (counter == 0)
    {
        head = prev;
    }
    else 
    {
        p1->next = prev;
    }
    p2->next = current;
    
    
    return head;
	
}