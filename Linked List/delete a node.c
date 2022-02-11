#include <stdio.h>
#include <stdlib.h>

typedef struct noder 
{
  int key;
  struct noder* next;

} node;

node* createnode(int n);
void traversel(node* head);
node* deleteanode(node*head);





int main()
{
  int n;

  node* head = NULL;
  printf("How many nodes?:\n");
  scanf("%d", &n);
  head = createnode(n);

  traversel(head);


  head = deleteanode(head);

  traversel(head);



  return 0;
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

node* deleteanode(node* head)
{
  int x;
  node* p;
  node* next;
  node* prev;
  int i=1;

  if (head == NULL)
  {
    return head;
  }
  prev = NULL;
  next = head->next;
  p=head;
  printf("delete at which position?:\n");
  scanf("%d", &x);

  while (i < x)
  {
    prev = p;
    p = next;
    next = next->next;
    i++;
  }
  free(p);
  prev->next = next;

  return head;