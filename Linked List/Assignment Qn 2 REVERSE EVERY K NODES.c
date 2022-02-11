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

void reverseKNodes(ListNode **head, int K);

int main()
{
    ListNode *head = NULL, *temp;
    int i = 0;
    int K = 0;

    scanf("%d", &K);

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

    reverseKNodes(&head, K);
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

void reverseKNodes(ListNode **head, int K)
{
    // Write your code here

    int n = 0; // count
    ListNode *count = *head;
    while (count)
    {
        n++;
        count = count->next;
    }
    if (n < K || K == 1 || head == NULL || K == 0)
        return;

    ListNode *prev = NULL, *next = NULL, *newHead = NULL;
    ListNode *t1 = NULL, *t2 = *head;
    ListNode *curr = *head;

    while (n >= K)
    {
        for (int i = 0; i < K; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (!newHead)
            newHead = prev;
        if (t1)
            t1->next = prev;
        t2->next = curr; // n is not multiple of k
        t1 = t2;
        t2 = curr;
        prev = NULL;
        n -= K;
    }
    *head = newHead;
}
