/*

//  SINGLY  LINKED LIST….


#include <stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

// now we make a function for creating node---->
// ye function eak node bnakr uska address return karega struct node
// type ke pointer ko

struct node *createNode()
{
    struct node *m;
    m = (struct node *)malloc(sizeof(struct node));
    return (m);
}

// now we make a function to insert data in node--->

void insertData()
{
    struct node *temp, *t;
    temp = createNode();
    printf("Enter data : ");
    scanf("%d", &temp->info);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp; // ab start hmari abhi abhi bni pahli node ko point krege
    }
    else
    {
        // ager pahle se hi kafi node pdi hai list me
        // aur hme apna node last me insert krna ho to
        // hm else me aayenge
        // eak nye pointer me head ka address dekr uske through puri list traverse krenge
        // jaise hi hme aakhiri list milegi , jiske link me null hoga
        // uske link ko hm apni node a address pkda denge , jo ki temp me rakha hai
        t = start;
        while (t->link != NULL)
        {
            t = t->link; // ye agli node ka address t me dal rha hai;
        }
        // agr yha aaye matalab t me null hai aur hm aakhiri node pr hai
        // ab eske link ko temp me rakha address de do
        t->link = temp;
    }
}

// now we create a function to traverse in array

void view(){
    struct node * temp;
    if(start==NULL){
        printf("List is empty : ");
    }
    else{
        temp=start;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            printf("\n");
            temp=temp->link;// temp me next node ka address dal diya;
        }

    }
}

// now we will create a function to delete node

void delete ()
{
    struct node *r;
    if (start == NULL)
    {
        printf("List is empty : ");
    }
    else
    {
        r = start;           // pahli node ka address r me rakh liya , baad me eesko delete kr denge
        start = start->link; // ab ye agli node ko point karega
        free(r);
    }
}
int menu()
{
    char ch;
    printf("\n1. Add value to the linked list :  ");
    printf("\n2. delete value from the linked list :  ");
    printf("\n3. view  value of the linked list :  ");
    printf("\n4. EXIT  ");
    printf("\n. Enter your choice  :  ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    while(1){
        switch(menu()){
            case 1:
            insertData();
              break;
            case 2:
            delete();
            break;// it will delete the first node;
            case 3:
            view();
            break;
            case 4:
            exit(0);
            
            default :
            {
                printf("Oops ! Invalid choice ");

            }
        }
    }
    return 0;
}



*/



/*

//   DOUBLY LINKED LIST….

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*prev,*next;

};
struct node *start=NULL;
// creating function to create node
struct node* createNode(){
    struct node *m;// this will temporerly  keep the address of new node
    m=(struct node*)malloc(sizeof(struct node));
    return m;
}
// creating a function to find address of given node number
struct node* find_node_address_by_node_number(int n){
    //printf("Welcome to find \n");
    if(start==NULL){
        printf("No such data exist in the list. ");
        
     }
     else
     {
        struct node*temp;int count=0;// for traversing in list
        temp=start;
        count++;
        if(n==count){
            printf("Returning for node 1\n");
            return temp;
        }
        while(temp->next!=NULL)
        {
            
               temp= temp->next;
            count++;
            if(count==n){
                return temp;
            }
        }
        printf("Please enter a valid node number, at this time list has only %d nodes \n",count);
        return NULL;
     }
 
}

// creating function for getting address of that node who is 
// containing data passed as argument
 struct node* find_node_address_by_value(int n){
     if(start==NULL){
        printf("No such data exist in the list. ");
        
     }
     else
     {
        struct node*temp;// for traversing in list
        temp=start;
        while(temp!=NULL)
        {
            if(temp->info==n)
            {
                return temp;
            }
            else
            {
               temp= temp->next;
            }
        }
        printf("\n No such value is present in the list\n");
        return NULL;
     }
 }

// creating function for insert as first  node
  void insert_as_first_node(){
    struct node *temp;// this will keep the address of newly created node
    temp=createNode();// this function will crreate a node and return his address
    printf("\n Enter a number : ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    temp->prev=NULL; 
    if(start==NULL){
        start=temp;//ab start newly created address ko point kakrega
    }
    else{
        start->prev=temp;//new node ka address eske baad wali ko de diya 
        temp->next=start;//new node ke next me uske baad wali ka address dal diya
        start=temp;// new node ko start se point kra diya
    }
  }

 // insert node after a node by giving value
  void insert_after_a_node_by_giving_value()
  {
    int data_for_traverse,new_value;
    printf("Enter data after which you want to insert new node :");
   scanf("%d",&data_for_traverse);
    struct node * ptr=find_node_address_by_value(data_for_traverse); // return the address of data enteredd
    
    struct node *p; // pointer to keep address of newly created node;
    p=createNode();
    printf("Enter the value you want to add in the list after %d : ",data_for_traverse);
    scanf("%d",&new_value);
    p->info=new_value; // nye node me value daal di
    p->prev=ptr; // nye node se pahle ki node ka address dal diya
   p->next= ptr->next; // nye node ke baad wali node ka adrdress nyi node ke next me rakh diya
   // ab nye node ke baad wali node me es nye node ka address rakhna hoga
   // pr pahle check kr lo ki nynode ke baad me koi node hai bhi ya nhi

   if(ptr->next!=NULL){
    (ptr->next)->prev=p;
   }
   // ab nyi node ke pahle wali node ke next me eska addres dal do
   ptr->next=p;

   //done .......nyi node beech me khi add ho gyi hai add ho gyi
  }

// creating function to insert after a node by giving node number
 // insert node after a node by giving value
  void insert_after_a_node_by_giving_node_number()
  {
    int data_for_traverse,new_value;
    printf("Enter node number after which you want to enter :");
   scanf("%d",&data_for_traverse);
    struct node * ptr=find_node_address_by_node_number(data_for_traverse); // return the address of data enteredd
    
    struct node *p; // pointer to keep address of newly created node;
    p=createNode();
    printf("Enter the value you want to add in the list after %d : ",data_for_traverse);
    scanf("%d",&new_value);
    p->info=new_value; // nye node me value daal di
    p->prev=ptr; // nye node se pahle ki node ka address dal diya
   p->next= ptr->next; // nye node ke baad wali node ka adrdress nyi node ke next me rakh diya
   // ab nye node ke baad wali node me es nye node ka address rakhna hoga
   // pr pahle check kr lo ki nynode ke baad me koi node hai bhi ya nhi

   if(ptr->next!=NULL){
    (ptr->next)->prev=p;
   }
   // ab nyi node ke pahle wali node ke next me eska addres dal do
   ptr->next=p;

   //done .......nyi node beech me khi add ho gyi hai add ho gyi
  }

//now we will create a node to delete first node

void delete_first_node()
{
    struct node * r;// this will keep address permanently to delete that node
    if(start==NULL)
    {
        printf("\nList is empty.\n\n ");
    }
    else{
        r=start;// r bhi ab pahle node ko point kr rha hai 
        start=start->next;// pahli node ke next se agli ka address lekr start ko de diya
        start->prev=NULL;// since second node is now first so uske prev ko null kr diya
         printf("Deleted -> %d ",r->info);
         free(r);// ab pahle node se sab kam ka nikal lene ke baad usko delete kr do;
    }
}
// creating a function to delete from last
void delete_last_node()
{
    struct node * r;// this will keep address permanently to delete that node
    if(start==NULL)
    {
        printf("\nList is empty.\n\n ");
    }
          r=start;
          while(r->next !=NULL)
          {
            r=r->next;
          }
          (r->prev)->next=NULL;// last se pahle wale ke next me null daal diya
          printf("\nDeleted value : %d \n",r->info);
          free(r);
}

// creating a function to delete node by node number
void delete_node_by_node_number(){
    int n;

    printf("Enter the node number you want to delete : ");
    scanf("%d",&n);

    struct node * deleteble;

    deleteble=find_node_address_by_node_number(n);
    // ager invalid node number diya hoga to null return hoga
    if(deleteble==NULL){
        return;
    }

    // ager node number first node ka diya ho to ....
    if(deleteble->prev==NULL){
        (deleteble->next)->prev=NULL;// pahli node delete krni hai to dusri ka prev null kr diya
    start=deleteble->next; // start ab second row ko point krega
    printf(" First node  having value %d is successfully deleted \n",deleteble->info);
    free(deleteble);
    }
    // ager node number lastt node ka diya ho too......
    else if(deleteble->next==NULL){
        // means ye last node delete krne ko bol rha hai
        (deleteble->prev)->next=NULL; // last se pahle wali ko last bnane ke liye uske next ko null ke diya
        
        printf(" Last node  having value %d is successfully deleted \n",deleteble->info);
            free(deleteble);
    }

    // ager koi intermidiate node number aa jaye to 
    else{
    (deleteble->next)->prev=deleteble->prev;
    (deleteble->prev)->next=deleteble->next;
    printf("Node number %d having value %d is successfully deleted \n",n,deleteble->info);
    free(deleteble);
}
}

// creating a function to delete node by given value
void delete_node_by_value_given(){
    int n;
    printf("Enter the value you want to delete : \n");
    scanf("%d",&n);
    struct node * d;
    d=find_node_address_by_value(n);// d me address hoga us node ka jisne value n rakha hai
     // ager invalid value given hai to null return hoga
     if(d==NULL){
        return;
    }

    // if value is of first node ....
    if(d->prev==NULL){
        (d->next)->prev=NULL;// pahli node delete krni hai to dusri ka prev null kr diya
    start=d->next; // start ab second row ko point krega
    printf(" First node  having value %d is successfully deleted \n",d->info);
    free(d);
    }
    // if value belong to last node ......
    else if(d->next==NULL){
        // means ye last node delete krne ko bol rha hai
        (d->prev)->next=NULL; // last se pahle wali ko last bnane ke liye uske next ko null ke diya
        
        printf(" Last node  having value %d is successfully deleted \n",d->info);
            free(d);
    }

    // ager koi intermidiate node number aa jaye to 
    else{
    (d->next)->prev=d->prev;
    (d->prev)->next=d->next;
    printf("Node number %d having value %d is successfully deleted \n",n,d->info);
    free(d);
}

}

// create a function to insert node at last 

void inser_node_at_last(){
    printf("Welcome 1");
    struct node* temp;//it will hold the address of newly created node
    temp=createNode();
   printf("\nEnter your data for last node.\n");
    scanf("%d",&temp->info);// nyi node me data daal diya
    temp->next=NULL;// ager ye last node hai to eske next me null rakhna hoga;
    if(start==NULL)
    {
        // means pahle se koi node nhi hai 
        // to ye pahli node banegi 
        // so eske next and prev dono me null rakhna hoga aur 
        //eska address start ko dena hoga
        // next me null pahle hi daal diya prev me ab rakh do
        temp->prev=NULL;
        start=temp; 
    }
    else
    {
        // means pahle se aur bhi node present hai
        // last node pe jakr es node ko add ke do 
        // create a pointer to traverse till last node
        struct node * t;// whit this pointer t we will traverse  till last node;
        t=start;// t ko start ka address de diya
        while(t->next!=NULL){
            t=t->next;
           
        }
        
        t->next=temp; // second last me address de diya last ka
        temp->prev=t; // last node ke prev me address de diya second last ka
         
        
    }
   

}

// Now creating a function to tracerse list;

void view_list()
{
     struct node * t;
     if(start==NULL)
     {
        printf("\n\nThe list is empty :\n\n ");
     }
     else{
        t=start; int count=0;
        printf("\nValues present in the list are : \n");
        while(t!=NULL)
        {
            printf(" %d ",t->info);
            count++;
             printf("\n");
            t=t->next;
        }
        printf(" Total number of node is : %d \n\n",count);
       
     }
}

int menu()
{
    char ch;
    printf("\n1. Add value from begning to the doubly linked list :  ");
    printf("\n2. Add value from last to the doubly linked list :  ");
    printf("\n3. Add value  after a node by giving value of previous node  :  ");
    printf("\n4. Add value  after a node by giving node number in doubly linked list :  ");
    printf("\n5. delete value from the begning of doubly linked list :  ");
    printf("\n6. delete value from the last of doubly linked list :  ");
    printf("\n7. delete any node by giving node number in doubly list :  ");
    printf("\n8. delete any node by giving value in doubly list :  ");
    printf("\n9. view/print  value in the doubly linked list :  ");
    printf("\n10. EXIT  ");
    
    printf("\n\nEnter your choice  :  ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    while(1){
        switch(menu()){ 
            case 1:
            insert_as_first_node();
              break;
            case 5:
            delete_first_node();
            break;// it will delete the first node;
            case 6 :
            delete_last_node();
            break;
            case 7:
            delete_node_by_node_number();
            break;
            case 8:
            delete_node_by_value_given();
            break;
            case 9:
            view_list();
            break;
            case(2):
            inser_node_at_last();
            break;
            case(3):
            insert_after_a_node_by_giving_value();
            break;
            case(4):
            insert_after_a_node_by_giving_node_number();
            break;
            case (10):
            exit(0);
            
            default :
            {
                printf("Oops ! Invalid choice ");

            }
        }
    }
    return 0;
}








*/











// CIRCULAR LINKED LIST….

#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*prev,*next;

};
struct node *start=NULL;
// creating function to create node
struct node* createNode(){
    struct node *m;// this will temporerly  keep the address of new node
    m=(struct node*)malloc(sizeof(struct node));
    return m;
}
// creating a function to find address of given node number
struct node* find_node_address_by_node_number(int n){
    //printf("Welcome to find \n");
    if(start==NULL){
        printf("No such data exist in the list. ");
        
     }
     else
     {
        struct node*temp;int count=0;// for traversing in list
        temp=start;
        count++;
        if(n==count){
            printf("Returning for node 1\n");
            return temp;
        }
        while(temp->next!=NULL)
        {
            
               temp= temp->next;
            count++;
            if(count==n){
                return temp;
            }
        }
        printf("Please enter a valid node number, at this time list has only %d nodes \n",count);
        return NULL;
     }
 
}

// creating function for getting address of that node who is 
// containing data passed as argument
 struct node* find_node_address_by_value(int n){
     if(start==NULL){
        printf("No such data exist in the list. ");
        
     }
     else
     {
        struct node*temp;// for traversing in list
        temp=start;
        while(temp!=NULL)
        {
            if(temp->info==n)
            {
                return temp;
            }
            else
            {
               temp= temp->next;
            }
        }
        printf("\n No such value is present in the list\n");
        return NULL;
     }
 }

// creating function for insert as first  node
  void insert_as_first_node(){
    struct node *temp;// this will keep the address of newly created node
    temp=createNode();// this function will crreate a node and return his address
    printf("\n Enter a number : ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    temp->prev=NULL; 
    if(start==NULL){
        start=temp;//ab start newly created address ko point kakrega
    }
    else{
        start->prev=temp;//new node ka address eske baad wali ko de diya 
        temp->next=start;//new node ke next me uske baad wali ka address dal diya
        start=temp;// new node ko start se point kra diya
    }
  }

 // insert node after a node by giving value
  void insert_after_a_node_by_giving_value()
  {
    int data_for_traverse,new_value;
    printf("Enter data after which you want to insert new node :");
   scanf("%d",&data_for_traverse);
    struct node * ptr=find_node_address_by_value(data_for_traverse); // return the address of data enteredd
    
    struct node *p; // pointer to keep address of newly created node;
    p=createNode();
    printf("Enter the value you want to add in the list after %d : ",data_for_traverse);
    scanf("%d",&new_value);
    p->info=new_value; // nye node me value daal di
    p->prev=ptr; // nye node se pahle ki node ka address dal diya
   p->next= ptr->next; // nye node ke baad wali node ka adrdress nyi node ke next me rakh diya
   // ab nye node ke baad wali node me es nye node ka address rakhna hoga
   // pr pahle check kr lo ki nynode ke baad me koi node hai bhi ya nhi

   if(ptr->next!=NULL){
    (ptr->next)->prev=p;
   }
   // ab nyi node ke pahle wali node ke next me eska addres dal do
   ptr->next=p;

   //done .......nyi node beech me khi add ho gyi hai add ho gyi
  }

// creating function to insert after a node by giving node number
 // insert node after a node by giving value
  void insert_after_a_node_by_giving_node_number()
  {
    int data_for_traverse,new_value;
    printf("Enter node number after which you want to enter :");
   scanf("%d",&data_for_traverse);
    struct node * ptr=find_node_address_by_node_number(data_for_traverse); // return the address of data enteredd
    
    struct node *p; // pointer to keep address of newly created node;
    p=createNode();
    printf("Enter the value you want to add in the list after %d : ",data_for_traverse);
    scanf("%d",&new_value);
    p->info=new_value; // nye node me value daal di
    p->prev=ptr; // nye node se pahle ki node ka address dal diya
   p->next= ptr->next; // nye node ke baad wali node ka adrdress nyi node ke next me rakh diya
   // ab nye node ke baad wali node me es nye node ka address rakhna hoga
   // pr pahle check kr lo ki nynode ke baad me koi node hai bhi ya nhi

   if(ptr->next!=NULL){
    (ptr->next)->prev=p;
   }
   // ab nyi node ke pahle wali node ke next me eska addres dal do
   ptr->next=p;

   //done .......nyi node beech me khi add ho gyi hai add ho gyi
  }

//now we will create a node to delete first node

void delete_first_node()
{
    struct node * r;// this will keep address permanently to delete that node
    if(start==NULL)
    {
        printf("\nList is empty.\n\n ");
    }
    else{
        r=start;// r bhi ab pahle node ko point kr rha hai 
        start=start->next;// pahli node ke next se agli ka address lekr start ko de diya
        start->prev=NULL;// since second node is now first so uske prev ko null kr diya
         printf("Deleted -> %d ",r->info);
         free(r);// ab pahle node se sab kam ka nikal lene ke baad usko delete kr do;
    }
}
// creating a function to delete from last
void delete_last_node()
{
    struct node * r;// this will keep address permanently to delete that node
    if(start==NULL)
    {
        printf("\nList is empty.\n\n ");
    }
          r=start;
          while(r->next !=NULL)
          {
            r=r->next;
          }
          (r->prev)->next=NULL;// last se pahle wale ke next me null daal diya
          printf("\nDeleted value : %d \n",r->info);
          free(r);
}

// creating a function to delete node by node number
void delete_node_by_node_number(){
    int n;

    printf("Enter the node number you want to delete : ");
    scanf("%d",&n);

    struct node * deleteble;

    deleteble=find_node_address_by_node_number(n);
    // ager invalid node number diya hoga to null return hoga
    if(deleteble==NULL){
        return;
    }

    // ager node number first node ka diya ho to ....
    if(deleteble->prev==NULL){
        (deleteble->next)->prev=NULL;// pahli node delete krni hai to dusri ka prev null kr diya
    start=deleteble->next; // start ab second row ko point krega
    printf(" First node  having value %d is successfully deleted \n",deleteble->info);
    free(deleteble);
    }
    // ager node number lastt node ka diya ho too......
    else if(deleteble->next==NULL){
        // means ye last node delete krne ko bol rha hai
        (deleteble->prev)->next=NULL; // last se pahle wali ko last bnane ke liye uske next ko null ke diya
        
        printf(" Last node  having value %d is successfully deleted \n",deleteble->info);
            free(deleteble);
    }

    // ager koi intermidiate node number aa jaye to 
    else{
    (deleteble->next)->prev=deleteble->prev;
    (deleteble->prev)->next=deleteble->next;
    printf("Node number %d having value %d is successfully deleted \n",n,deleteble->info);
    free(deleteble);
}
}

// creating a function to delete node by given value
void delete_node_by_value_given(){
    int n;
    printf("Enter the value you want to delete : \n");
    scanf("%d",&n);
    struct node * d;
    d=find_node_address_by_value(n);// d me address hoga us node ka jisne value n rakha hai
     // ager invalid value given hai to null return hoga
     if(d==NULL){
        return;
    }

    // if value is of first node ....
    if(d->prev==NULL){
        (d->next)->prev=NULL;// pahli node delete krni hai to dusri ka prev null kr diya
    start=d->next; // start ab second row ko point krega
    printf(" First node  having value %d is successfully deleted \n",d->info);
    free(d);
    }
    // if value belong to last node ......
    else if(d->next==NULL){
        // means ye last node delete krne ko bol rha hai
        (d->prev)->next=NULL; // last se pahle wali ko last bnane ke liye uske next ko null ke diya
        
        printf(" Last node  having value %d is successfully deleted \n",d->info);
            free(d);
    }

    // ager koi intermidiate node number aa jaye to 
    else{
    (d->next)->prev=d->prev;
    (d->prev)->next=d->next;
    printf("Node number %d having value %d is successfully deleted \n",n,d->info);
    free(d);
}

}

// create a function to insert node at last 

void inser_node_at_last(){
    printf("Welcome 1");
    struct node* temp;//it will hold the address of newly created node
    temp=createNode();
   printf("\nEnter your data for last node.\n");
    scanf("%d",&temp->info);// nyi node me data daal diya
    temp->next=NULL;// ager ye last node hai to eske next me null rakhna hoga;
    if(start==NULL)
    {
        // means pahle se koi node nhi hai 
        // to ye pahli node banegi 
        // so eske next and prev dono me null rakhna hoga aur 
        //eska address start ko dena hoga
        // next me null pahle hi daal diya prev me ab rakh do
        temp->prev=NULL;
        start=temp; 
    }
    else
    {
        // means pahle se aur bhi node present hai
        // last node pe jakr es node ko add ke do 
        // create a pointer to traverse till last node
        struct node * t;// whit this pointer t we will traverse  till last node;
        t=start;// t ko start ka address de diya
        while(t->next!=NULL){
            t=t->next;
           
        }
        
        t->next=temp; // second last me address de diya last ka
        temp->prev=t; // last node ke prev me address de diya second last ka
         
        
    }
   

}

// Now creating a function to tracerse list;

void view_list()
{
     struct node * t;
     if(start==NULL)
     {
        printf("\n\nThe list is empty :\n\n ");
     }
     else{
        t=start; int count=0;
        printf("\nValues present in the list are : \n");
        while(t!=NULL)
        {
            printf(" %d ",t->info);
            count++;
             printf("\n");
            t=t->next;
        }
        printf(" Total number of node is : %d \n\n",count);
       
     }
}

int menu()
{
    char ch;
    printf("\n1. Add value from begning to the doubly linked list :  ");
    printf("\n2. Add value from last to the doubly linked list :  ");
    printf("\n3. Add value  after a node by giving value of previous node  :  ");
    printf("\n4. Add value  after a node by giving node number in doubly linked list :  ");
    printf("\n5. delete value from the begning of doubly linked list :  ");
    printf("\n6. delete value from the last of doubly linked list :  ");
    printf("\n7. delete any node by giving node number in doubly list :  ");
    printf("\n8. delete any node by giving value in doubly list :  ");
    printf("\n9. view/print  value in the doubly linked list :  ");
    printf("\n10. EXIT  ");
    
    printf("\n\nEnter your choice  :  ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    while(1){
        switch(menu()){ 
            case 1:
            insert_as_first_node();
              break;
            case 5:
            delete_first_node();
            break;// it will delete the first node;
            case 6 :
            delete_last_node();
            break;
            case 7:
            delete_node_by_node_number();
            break;
            case 8:
            delete_node_by_value_given();
            break;
            case 9:
            view_list();
            break;
            case(2):
            inser_node_at_last();
            break;
            case(3):
            insert_after_a_node_by_giving_value();
            break;
            case(4):
            insert_after_a_node_by_giving_node_number();
            break;
            case (10):
            exit(0);
            
            default :
            {
                printf("Oops ! Invalid choice ");

            }
        }
    }
    return 0;
}

