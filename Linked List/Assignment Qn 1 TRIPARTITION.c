#include <stdio.h>
#include <stdlib.h>

struct _listNode
{
    int item;
    struct _listNode *next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode **head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
    int i = 0;
    int pivot = 0;

    scanf("%d", &pivot);

    while (scanf("%d", &i))
    {
        if (head == NULL)
        {
            head = (ListNode *)malloc(sizeof(ListNode));
            temp = head;
        }
        else
        {
            temp->next = (ListNode *)malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
    }
    temp->next = NULL;

    triPartition(&head, pivot);
    printList(head);
    deleteList(&head);

    return 0;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead)
{
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    *ptrHead = NULL;
}

void triPartition(ListNode **head, int pivot)
{

    // Write your code here
    ListNode *smallerHead = NULL, *smallerLast = NULL;
    ListNode *greaterLast = NULL, *greaterHead = NULL;
    ListNode *equalHead = NULL, *equalLast = NULL;

    ListNode *curr = *head;

    while (curr != NULL)
    {
        if (curr->item == pivot)
        {
            if (equalHead == NULL)
                equalHead = equalLast = curr;
            else
            {
                equalLast->next = curr;
                equalLast = equalLast->next;
            }
        }
        else if (curr->item < pivot)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = curr;
            else
            {
                smallerLast->next = curr;
                smallerLast = curr;
            }
        }
        else
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = curr;
            else
            {
                greaterLast->next = curr;
                greaterLast = curr;
            }
        }
        curr = curr->next;
    }

    if (greaterLast != NULL)
        greaterLast->next = NULL;

    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
        {
            *head = greaterHead;
            return;
        }
        equalLast->next = greaterHead;
        *head = equalHead;
        return;
    }

    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        *head = smallerHead;
        return;
    }

    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    *head = smallerHead;
}