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

void in2Pre(char *, char *);

int main()
{
    char infix[SIZE];
    char prefix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c", infix);

    in2Pre(infix, prefix);
    printf("The prefix expression is \n");
    printf("%s\n", prefix);

    return 0;
}

void push(Stack *sPtr, char item)
{
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
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

int isOperator(char item)
{
    if (item == '*' || item == '/' || item == '+' || item == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
        return 0;
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

void in2Pre(char *infix, char *prefix)
{
    // Write your code here
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    stack->head = NULL;
    char infix_reversed[SIZE];
    char final_list[SIZE];

    // for traversing the list
    int i = 0;
    int j = 0;
    int k = 0;
    char number;

    // first reverse the list using a stack
    while (infix[i] != '\0')
    {
        push(stack, infix[i]);
        i++;
    }
    i = 0;
    // this is the reversed list
    while (!isEmptyStack(*stack))
    {
        number = peek(*stack);
        pop(stack);
        infix_reversed[i] = number;
        i++;
    }
    infix_reversed[i] = '\0';
    i = 0;

    // THIS IS WHERE IT MATTERS

    while (infix_reversed[i] != '\0')
    {

        if ((isOperand(infix_reversed[i])) && (infix_reversed[i] != '(' && infix_reversed[i] != ')'))
        {

            // simply push into the new list
            prefix[k] = infix_reversed[i];
            k++;
        }
        else if (infix_reversed[i] == ')')
        {

            push(stack, infix_reversed[i]);
        }
        else if (infix_reversed[i] == '(')
        {

            while (!isEmptyStack(*stack) && peek(*stack) != ')')
            {

                prefix[k] = peek(*stack);

                k++;
                pop(stack);
            }

            if (!isEmptyStack(*stack) && peek(*stack) == ')')
            {
                pop(stack); // popping the ) out
            }
            else
            {
                return;
            }
        }
        else // THIS IS THE OPERATOR PART FOR PREFIX, IF INCOMING PRECEDENCE IS SMALLER THAN TOP, POP
        {
            // printf("Testing === %d %d", precedence(infix_reversed[i]), precedence(peek(*stack)));
            while (!isEmptyStack(*stack) && (peek(*stack) != '(' && peek(*stack) != ')') && precedence(infix_reversed[i]) < precedence(peek(*stack)))
            {

                prefix[k] = peek(*stack);
                pop(stack);
                k++;
            }
            push(stack, infix_reversed[i]);
        }
        i++;
    }

    while (!isEmptyStack(*stack))
    {

        prefix[k] = peek(*stack);
        pop(stack);
        k++;
    }
    prefix[k] = '\0';

    // FINALLY REVERSE BACK THE LIST
    i = 0;
    while (prefix[i] != '\0')
    {
        push(stack, prefix[i]);
        i++;
    }
    i = 0;

    while (!isEmptyStack(*stack))
    {
        prefix[i] = peek(*stack);
        pop(stack);
        i++;
    }

    prefix[i] = '\0';
}