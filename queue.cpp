/* Menu Driven C Program to implement queue using array */

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue_arr[MAX];
int rear=-1;
int front=-1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display element at the front\n");
                printf("4.Display all elements of the queue\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                case 2:
                        item=del();
                        printf("\nDeleted element is  %d\n",item);
                        break;
                case 3:
                        printf("\nElement at the front is %d\n",peek());
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(1);
                default:
                        printf("\nWrong choice\n");
                }       //End of switch/
        }   //End of while/

        return 0;

}    //End of main()/

void insert(int item)
{
        if( isFull() )
        {
                printf("\nQueue Overflow\n");
                return;
        }
        if( front == -1 )
                front=0;
        rear=rear+1;
        queue_arr[rear]=item ;
}    //End of insert()/

int del()
{
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        item=queue_arr[front];
        front=front+1;
        return item;
}         //End of del()/

int peek()
{
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        return queue_arr[front];
}    //End of peek()/

int isEmpty()
{
        if( front==-1 || front==rear+1 )
                return 1;
        else
                return 0;
}    //End of isEmpty()/

int isFull()
{
        if( rear==MAX-1 )
                return 1;
        else
                return 0;
}    //End of isFull()/

void display()
{
        int i;
        if ( isEmpty() )
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n\n");
        for(i=front;i<=rear;i++)
                printf("%d  ",queue_arr[i]);
        printf("\n\n");
}      /*End of display() */



/*

/*  C Program to implement priority queue using linked list  

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int priority;
        int info;
        struct node *link;
}*front=NULL;

void insert(int item, int item_priority);
int del();
void display();
int isEmpty();

int main()
{
        int choice,item,item_priority;
        while(1)
        {
                printf("\n1.Insert\n");
                printf("2.Delete\n");
                printf("3.Display\n");
                printf("4.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d", &choice);

                switch(choice)
                {
                 case 1:
                        printf("\nInput the item to be added in the queue : ");
                        scanf("%d",&item);
                        printf("\nEnter its priority : ");
                        scanf("%d",&item_priority);
                        insert(item, item_priority);
                        break;
                 case 2:
                        printf("\nDeleted item is %d\n",del());
                        break;
                 case 3:
                        display();
                        break;
                 case 4:
                        exit(1);
                 default :
                        printf("\nWrong choice\n");
                }/End of switch/
        }/End of while/

        return 0;
}/End of main()/

void insert(int item,int item_priority)
{
        struct node *tmp,*p;

        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }
        tmp->info=item;
        tmp->priority=item_priority;
        /Queue is empty or item to be added has priority more than first element/
        if( isEmpty() || item_priority < front->priority )
        {
                tmp->link=front;
                front=tmp;
        }
        else
        {
                p = front;
                while( p->link!=NULL && p->link->priority<=item_priority )
                        p=p->link;
                tmp->link=p->link;
                p->link=tmp;
        }
}/End of insert()/

int del()
{
        struct node *tmp;
        int item;
        if( isEmpty() )
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }
        else
        {
                tmp=front;
                item=tmp->info;
                front=front->link;
                free(tmp);
        }
        return item;
}/End of del()/

int isEmpty()
{
        if( front == NULL )
                return 1;
        else
                return 0;

}/End of isEmpty()/


void display()
{
        struct node *ptr;
        ptr=front;
        if( isEmpty() )
                printf("\nQueue is empty\n");
        else
        {       printf("\nQueue is :\n");
                printf("\nPriority       Item\n");
                while(ptr!=NULL)
                {
                        printf("%5d        %5d\n",ptr->priority,ptr->info);
                        ptr=ptr->link;
                }
        }
}/*End of display() *






*/