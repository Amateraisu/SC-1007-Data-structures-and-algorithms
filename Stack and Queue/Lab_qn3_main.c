#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // The limit of expression length

typedef struct _stackNode
{
    double item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char *);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c", postfix);

    printf("The answer is %.2lf.\n", exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item)
{
    StackNode *newNode;
    newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr)
{
    if (sPtr == NULL || sPtr->head == NULL)
    {
        return 0;
    }
    else
    {
        StackNode *temp = sPtr->head;
        sPtr->head = sPtr->head->next;
        free(temp);
        sPtr->size--;
        return 1;
    }
}

double peek(Stack s)
{
    return s.head->item;
}

int isEmptyStack(Stack s)
{
    if (s.size == 0)
        return 1;
    else
        return 0;
}

double exePostfix(char *postfix)
{
    // Write your code here
    Stack s;
    char *current = postfix;
    int i = 0;
    double new_item_1 = 0;
    double new_item_2 = 0;
    double new_item_3 = 0;

    while (current[i] != '\0')
    {
        switch (current[i])
        {

        case '+':
            new_item_1 = peek(s);
            pop(&s);
            new_item_2 = peek(s);
            pop(&s);
            new_item_1 += new_item_2;
            push(&s, new_item_1);
            break;

        case '-':
            new_item_1 = peek(s);
            pop(&s);
            new_item_2 = peek(s);
            pop(&s);
            new_item_2 -= new_item_1;
            push(&s, new_item_2);
            break;

        case '*':
            new_item_1 = peek(s);
            pop(&s);
            new_item_2 = peek(s);
            pop(&s);
            new_item_1 *= new_item_2;
            push(&s, new_item_1);
            break;

        case '/':
            new_item_1 = peek(s);
            pop(&s);
            new_item_2 = peek(s);
            pop(&s);
            new_item_2 /= new_item_1;
            push(&s, new_item_2);
            break;
        default:

            push(&s, current[i] - '0');
        }

        i++;
    }
    return peek(s);
}