/*
// stack wil follow the principle last in first out (LEFO) principle
//push mean add element
// pop mean delete a element.
//IsEmpty mean if the stack is empty.
//IsFull mean if the stack is full.
//peak mean get the value of top element with out removing it.
// the most common immplementation of stack by arrays.

#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 10  // defining MAX function  value is 10
int size = 0;

struct stack {  // creating stack.
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top=-1;
}
 
 // check if the stack is full

 int isfull(st *s){
    if(s->top == MAX-1)
    return 1;
    else
    return 0;
 }

 // CHECK IF THE STACK IS EMPTY

 int isempty(st *s)
 {
    if(s->top ==-1)
    return 1;
    else 
    return 0;
 }

 //add elements to the stack

 void push(st *s, int newitem)
 {
    if (isfull(s))
     {
        cout<<"stack is full";
     }
     else
     {
        s->top++;
        s->items[s->top] = newitem;
     }
     size++;
 }
    // remove element from stack.

     void pop(st *s)
     {
        if(isempty(s))
        {
            cout<<"\n stack is empty \n";
        }
        else
        {
            cout<<"item popped = "<< s->items[s->top];
            s->top--;
        }
        size--;
        cout<<endl;
     }

     // printing the elements of stack;

     void printstack(st *s)
     {
        cout<<"stack: ";
        for (int i=0;i<size;i++)
        {
            cout<<s->items[i]<<" ";

        }
        cout<<endl;
     }

     // drivers code

     int main()
     {
        int ch;
        st *s = (st *)malloc(sizeof(st));
        createEmptyStack(s);

        push( s,1);
        push( s,2);
        push( s,3);
        push( s,4);

        printstack(s);

        pop(s);
        cout<<"\n After poping out\n";
        printstack(s);

     }

     
     /* applications of stack data structure

       * to reverse a word
       *in compilers - compilers use the stack to calculate the value of expressions
      by converting the expreesionto prefix or postfix.
       * in browsers-the back button in browser saves all the URLS that you have visited
       priviously 


     */

 
    


  // stack implementing by  single linked list
  # include <bits/stdc++.h>
  using namespace std;

 // declare linked list node.


 struct Node {
    int data;
    Node* link;
 } ;
 Node* top;
  
  // add element at starting of stack.

  void push(int data)
  {
    // create new node temp and allocate memory in heap
    Node* temp =new Node();       // check if stack is full.
    if(!temp)                    //   then inserting element would lead to stack over flow
    {
        cout<<"\n stack overflow ";
         return 1;    //exist(1);
    }     
    
    temp-> data = data; //initialize data into temp data field
    temp->link = top;  //put top pointer reference into temp link;
    top = temp; //make temp as top of stack.  

  }

  // check if stack is empty or not.
  int isempty()
  {
    return top == NULL; //IF TOP IS NULL THEN THERE WILL BE NO ELEMENTS IN STACK
  }
  int peek()    //if stack is not empty return the top element.
  {
    if(!isempty())
    return top->data;
    else
    return 1;//exist(1);
  }

void pop()
{
    Node* temp;
    // check for stack underflow.
    if( top==NULL)
    {
        cout<<"\n stack underflow"<<endl;
       return 1;// exist(1);
    }
    else {
        //assign top to heap;
        temp=top;
        // assign second node to top
        top = top->link;
        //this will automatically destroy the link between between the 
        //first node and second node.
        //release memory of top node i.e delete the node.
        free(temp);
    }
}


void display()
{
    Node* temp;
    // check for stack underflow
    if( top ==NULL){
        cout<<"\n stack underflow ";
        return 1;//exist(1);
    } 
    else {
        temp = top;
        while ( temp!=NULL){
            cout<<temp->data<<"->";
            //assign temp link to temp
            temp = temp ->link;
        }
    }
}

// drivers code

int main()
{
    push(11);
    push(22);
    push(33);
    push(44);
    
    display(); //dispaly stack elements
    cout<<"\n Top element is "<<peek()<<endl;

    // delete top elements of stack
    pop();
    pop();
    display();
    // print top element of stack 
    cout <<"\n topelement is "<<peek()<<endl;
    return 0;
}


