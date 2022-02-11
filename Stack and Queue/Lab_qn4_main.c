#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // The limit of expression length

typedef struct _stackNode
{
    char item;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    int size;
    StackNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

void in2Post(char *, char *);

int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c", infix);
    in2Post(infix, postfix);
    printf("The postfix expression is \n");
    printf("%s\n", postfix);
    return 0;
}

void push(Stack *sPtr, char item)
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

char peek(Stack s)
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

int precedence(char item)
{
    if (item == '*' || item == '/')
    {
        return 2;
    }
    else if (item == '+' || item == '-')
    {
        return 1;
    }

    else
    {
        return 0; // if it is brackets return 0
    }
}

int isOperand(char ch)
{
    if (ch == '%' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int is_operator(char item)
{
    if (item == '+' || item == '-' || item == '*' || item == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void in2Post(char *infix, char *postfix)
{
    // Write your code here

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;

    if (!stack)
        return;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {

        printf("This is infix %c \n", infix[i]);
        if (isOperand(infix[i]) && (infix[i] != '(' && infix[i] != ')'))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            printf("This is here\n");
            push(stack, infix[i]);
            printf("This is peek %c\n", peek(*stack));
        }
        else if (infix[i] == ')')
        {
            printf("This is here2\n");
            while (!isEmptyStack(*stack) && peek(*stack) != '(')
            {
                postfix[j] = peek(*stack);
                j++;
                pop(stack);
            }
            if (!isEmptyStack(*stack) && peek(*stack) != '(')
            {
                return; // POPPING TILL REACH '(' IF IT IS NOT '(', RETURN
            }
            else
            {
                printf("This is peek %c\n", peek(*stack));
                pop(stack); // removing the ()
            }
        }
        else // an OPERATOR IS ENCOUNTERED
        {
            while (!isEmptyStack(*stack) && precedence(infix[i]) <= precedence(peek(*stack)))
            {
                postfix[j] = peek(*stack);
                pop(stack);
                j++;
            }
            push(stack, infix[i]);
        }
        i++;
    }

    while (!isEmptyStack(*stack))
    {
        postfix[j] = peek(*stack);
        pop(stack);
        j++;
    }

    postfix[j] = '\0';
    printf("THIS IS POSTFIX %s\n", postfix);
}