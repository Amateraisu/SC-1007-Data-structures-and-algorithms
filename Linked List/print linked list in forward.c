#include <stdio.h>
#include <stdlib.h>

typedef struct noder 
{
  int key;
  struct noder* next;

} node;

node* createnode(int n);
void traversel(node* head);



int main()
{
  int n;

  node* head = NULL;
  printf("How many nodes?:\n");
  scanf("%d", &n);
  head = createnode(n);

  traversel(head);
}



node* createnode(int n)
{
  node* p;
  node* head;
  node* temp;

  head = NULL;

  for (int i = 0 ; i < n ; i++)
  {
    temp = (node*)malloc(sizeof(node));
    printf("What is the value of the data in the node?\n");
    scanf("%d", &(temp->key));
    temp-> next = NULL;

    if (head == NULL)
    {
      head = temp;
    }
    else 
    {
      p = head;
      while (p->next != NULL)
      {
        p = p->next;

      }
      p-> next = temp;
    }

  }


  return head;
}


void traversel(node* head)
{
  node* p = head;
  while (p!= NULL)
  {
    printf("The value of the node is : %d\n", p->key);
    p = p->next;
    
  }
}