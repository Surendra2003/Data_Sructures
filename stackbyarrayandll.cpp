//  STACK BY ARRAY…



#include <stdio.h>
#include <stdlib.h>
// creating a stack datatype as user define
// implementation of stack with the help of array
struct ArrayStack
{
    int top;
    int capacity;
    int *array; // this pointer will point first element of array
};
struct ArrayStack *stack;

// function for creation of stack

int menu()
{
    int choice;
    printf("\n1. Create a new stack.");
    printf("\n2.Push new element in stack.");
    printf("\n3.Pop element from stack.");
    printf("\n4. Show the status of stack.");
    printf("\n5. EXIT\n");
    printf("\n Enter your choice :");
    scanf("%d", &choice);
    printf("\n");
    return (choice);
}

struct ArrayStack *createStack()
{

    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    printf("Enter the capacity of stack : ");
    scanf("%d", &stack->capacity); // ask user the size of stack or no.of element in stack
    stack->top = -1;
    stack->array = malloc(sizeof(int) * stack->capacity); // capacity * int , itni memory allocate ker do
    return (stack);
}

// function to check stack is full or not

int isFull()
{
    if (stack->top == (stack->capacity - 1))
    {
        printf("Stack is full .\n");
        return 1;
    }
    else if(stack->top !=(stack->capacity - 1))
        return 0;

    //      else{
    //     printf("There is no stack available.\n First create a new stack.\n");
    // }
        
}

// function to check stack is empty or not

int isempty()
{
    if (stack->top == -1)
    {
        printf("Stack is totaly empty.");
        return 1;
    }
    else if(stack->top != -1)
        {return 0;
        }
    //      else{
    //     printf("There is no stack available.\n First create a new stack.\n");
    // }
        
}
void stackStatus()
{
    if (isempty())
    {
        printf(" There is nothing to show in status.\n");
    }
    else if(!isempty())
    {
        int count = stack->top;
        printf("Element in the stack from  top to bottom are in order :\n");
        while (stack->array[0] != stack->array[count])
        {
            printf("%d\n", stack->array[count]);
            count--;
        }
        printf("%d\n", stack->array[count]); // for printing of last element;
        printf("Total element in the stack is : %d\n", stack->top + 1);

        printf("Most recent filled element  in the stack is : %d\n", stack->array[stack->top]);

        printf("Total capacity of the stack is the stack is : %d\n", stack->capacity);
        if (stack->capacity - (stack->top + 1) == 0)
        {
            printf("Stack is full , Now you can not push any element in the stack.\n");
        }
        else
        {
            printf("Still youn can put %d  element in the stack \n", stack->capacity - (stack->top + 1));
        }
    }
    // else{
    //     printf("There is no stack available.\n First create a new stack.\n");
    // }
}
void push()
{
    // printf("%d\n",stack->top);
    // printf("%d\n",stack->capacity-1);
    if (isFull())
    {
        printf("Sorry! You can not push any data now .\n");
    }
    else if(!isFull())
    {
        int n;
        printf("Enter the data you want to push in stack :");
        scanf("%d", &n);
        stack->top++;
        stack->array[stack->top] = n;
        printf("\n %d  is successfully pushed into stack.\n", n);
    }
    //  else{
    //     printf("There is no stack available.\n First create a new stack.\n");
    // }
}

void pop()
{
    if (isempty())
    {
        printf("\n There is nothing to pop.\n");
    }
    else if(!isempty())
    {
        printf("%d is successfully poped from stack.\n", stack->array[stack->top]);
        stack->top--;
    }
    //  else{
    //     printf("There is no stack available.\n First create a new stack.\n");
    // }
}
int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            createStack();
            break;

        case 2:
            push();
            break;

        case 3:
            pop();
            break;

        case 4:
            stackStatus();
            break;
        case 5:
            exit(0);
        default:
            printf("\nOOPs! Enter a valid choice.");
        }
    }

    return 0;
}



















/*




//  STACK BY LINKED LIST….

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *stack = NULL; // global declaration of stack
// function for creating node;
struct node *create_node()
{
    struct node *m = (struct node *)malloc(sizeof(struct node));
    return m; // returning address of newly created node
}

// function to show menu
int menu()
{
    int choice;
    printf("\n1.Push data into stack.");
    printf("\n2.Pop data from the stack.");
    printf("\n3.Peak element of the stack.");
    printf("\n4.Complete status of your stack.");
    printf("\n5.EXIT");

    printf("\nEnter your choice :");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}
// function to push data in stack
void push()
{ //  if there is no node exist;
    if (stack == NULL)
    {
        struct node *m = create_node();
        printf("Enter value : ");
        scanf("%d", &m->data);
        m->next = NULL;
        stack = m; // now stack is pointing this first node;
    }
    // ager pahle se node present ho and hme new node insert krni ho....
    else
    {
        struct node *n = create_node();
        printf("Enter value : ");
        scanf("%d", &n->data);
        n->next = stack;
        stack = n; // now stack is pointing this node
    }
}

// function to pop
void pop()
{
    if (stack == NULL)
    {
        printf("There is no data to pop.\n");
    }
    else
    {
        int item = stack->data;
        struct node *temp = stack;
        stack = stack->next; // stack jisko point kr rha hai uske next node ka adddress stack me daal diya
        printf("\n%d is succesfully poped from stack.\n",item);
        free(temp);
    }
}
// function to show status of stack
void status()
{
    if (stack == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        int count = 1;
        struct node *temp = stack;
        printf("Element of the stack : \n");
        while (temp->next != NULL)
        {
            printf("%d\n", temp->data);
            count++;
            temp = temp->next;
        }
        printf("%d", temp->data);
        printf("\n At this moment, total element in the stack is : %d\n", count);
        printf("At this moment Top is pointing element :%d\n", stack->data);
    }
}
// creating a function to show the peak element
void peak()
{
    if (stack == NULL)
    {

        printf("There is no element in the stack now.\n");
    }
    else
    {
        printf("Your peak element is : %d\n", stack->data);
    }
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            status();
            break;
        case 5:
            exit(0);
        default:
        {
            printf("Ops ! Please enter a valid choice .\n");
        }
        }
    }
    return 0;
}

*/

