#include <stdio.h>
#include <stdlib.h>

struct _listNode
{
    int item;
    struct _listNode *next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList
{
    ListNode *head;
    int size;
} LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList *llptr);

LinkedList rearrange(LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode *temp;

    int i = 0;

    while (scanf("%d", &i))
    {
        if (ll.head == NULL)
        {
            ll.head = (ListNode *)malloc(sizeof(ListNode));
            temp = ll.head;
        }
        else
        {
            temp->next = (ListNode *)malloc(sizeof(ListNode));
            temp = temp->next;
        }
        temp->item = i;
        ll.size++;
    }
    temp->next = NULL;

    ll = rearrange(ll);

    printList(ll);
    deleteList(&ll);
    return 0;
}

void printList(LinkedList ll)
{
    ListNode *temp = ll.head;

    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList *llptr)
{
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur != NULL)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }
    llptr->head = NULL;
    llptr->size = 0;
}

LinkedList rearrange(LinkedList ll)
{
    // Write your code here
    ListNode *ptr = ll.head;
    ListNode *list_2 = NULL;
    ListNode *list_1 = NULL;
    ListNode *new_list = NULL;
    ListNode *new_head = NULL;
    // counter
    int counter = 0;
    int number_of_nodes = 0;
    int list_2_index = 0;
    int index = 0;

    // taking the middle node
    while (ptr != NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    ptr = ll.head;
    //   printf("This is the head value %d\n", ptr->item);
    //   printf("This is the counter value %d\n", counter);
    if (counter == 1 || ptr == NULL)
    {
        return ll;
    }
    number_of_nodes = counter;
    list_1 = ll.head;
    list_2_index = number_of_nodes / 2;
    list_2 = list_1;
    while (index != list_2_index)
    {
        list_2 = list_2->next;
        index++;
    }
    // printf("This is where list_2 is %d\n", list_2->item);
    // iterate the lists here

    counter = 0;
    new_list = list_2;
    new_head = list_2;
    list_2 = list_2->next;
    // printf("%d nodes\n", number_of_nodes);
    for (int i = 0; i < number_of_nodes - 1; i++)
    {
        // printf("This is I %d\n", i);
        if (i % 2 == 0)
        {
            new_list->next = list_1;
            list_1 = list_1->next;
        }
        else
        {
            new_list->next = list_2;
            list_2 = list_2->next;
        }
        new_list = new_list->next;
    }
    new_list->next = NULL;

    // below is the test for rearrangement of the first group

    // while (new_head != NULL)
    // {
    //   printf("This is new_head list %d\n", new_head->item);
    //   new_head = new_head->next;
    // }

    // below is the start of REARRANGMENT 2;

    index = 0;
    list_2 = new_head;
    list_1 = new_head;
    ptr = new_head;
    while (index != list_2_index)
    {

        list_2 = list_2->next;
        index++;
    }

    // TRIAL 1 this is for odd numbered nodes

    list_1 = list_1->next;
    // for (int j = 0 ; j<number_of_nodes-2; j++)
    // {
    //   printf("This is item %d\n", ptr->item);
    //   if (j % 2 ==0 )
    //   {
    //     ptr->next = list_2;
    //     list_2 = list_2->next;
    //   }
    //   else
    //   {
    //     ptr->next = list_1;
    //     list_1=list_1->next;
    //   }
    //   ptr = ptr->next;
    // }
    if (number_of_nodes % 2 != 0)
    {
        for (int j = 0; j < number_of_nodes - 2; j++)
        {

            if (j % 2 == 0)
            {
                ptr->next = list_2;
                list_2 = list_2->next;
            }
            else
            {
                ptr->next = list_1;
                list_1 = list_1->next;
            }
            ptr = ptr->next;
        }
        ptr->next->next = NULL;
        ll.head = new_head;

        return ll;
    }
    else
    {
        for (int j = 0; j < number_of_nodes - 1; j++)
        {
            if (j % 2 == 0)
            {
                ptr->next = list_2;
                list_2 = list_2->next;
            }
            else
            {
                ptr->next = list_1;
                list_1 = list_1->next;
            }
            ptr = ptr->next;
        }
        ptr->next = NULL;
        ll.head = new_head;

        return ll;
    }

    // ptr->next->next = NULL;

    // THIS IS THE TEST FOR ARRANGEMENT #2
    // while (new_head != NULL)
    // {
    //   printf("This is new_head list %d\n", new_head->item);
    //   new_head = new_head->next;
    // }
}