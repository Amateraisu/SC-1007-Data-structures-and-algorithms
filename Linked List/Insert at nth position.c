#include <stdio.h>
#include <stdlib.h>

typedef struct noder 
{
  int key;
  struct noder* next;

} node;

node* createnode(int n);
void traversel(node* head);
node* insertnode(node* head, int n);



int main()
{
  int n;

  node* head = NULL;
  printf("How many nodes?:\n");
  scanf("%d", &n);
  head = createnode(n);

  traversel(head);

  head = insertnode(head, n);
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


node* insertnode(node* head, int n)
{
  node* p= head;
  node* store;

  int CurrentPosition=0;
  int position;

  printf("Which position do u wish to insert?:\n");
  scanf("%d", &position);

  //create a node
  node* temp = (node*)malloc(sizeof(node));
  printf("Please enter the value of the node:\n");
  scanf("%d", &(temp->key));
  temp->next = NULL;

  while (CurrentPosition < position)
  {
    p = p->next;

    CurrentPosition++;
  }

  

  if (position == 0)
  {
    temp->next = head;
    head = temp;

    return head;
  }

  if (position == n)
  {
    p->next= temp;
    
    return head;
  }

  store = p->next;
  p->next = temp;
  temp->next = store;

  return head;  
}
