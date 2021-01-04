#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;


void swap(NODE a,NODE b);
NODE getNode()
{

    NODE x;
    x=malloc(sizeof(struct node));
    if(x==NULL)
    {

        exit(0);
    }
    else
    {
        return x;
    }
}
NODE insert_front(int item,NODE start)
{
    NODE temp;
    temp=getNode();
    temp->data=item;
    temp->next=start;
    start=temp;
    return start;
}

NODE insert_end(int item,NODE start)
{
    NODE temp,cur;
    temp=getNode();
    temp->data=item;
    temp->next=NULL;

    cur=start;
    while(cur->next!=NULL)
    {

        cur=cur->next;
    }
    cur->next=temp;
    return start;
}

NODE delete_front(NODE start)
{
    NODE ptr;
    if(start==NULL)
    {
        printf("List IS Empty And Cannot Be Deleted\n");
    }
    ptr=start;
    printf("Item Deleted is %d\n",ptr->data);
    start=start->next;
    free(ptr);
    return start;
}

NODE delete_end(NODE start)
{
    NODE ptr,preptr;
     if(start==NULL)
    {
        printf("List IS Empty And Cannot Be Deleted\n");
    }
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    printf("Item Deleted is %d\n",ptr->data);
    free(ptr);
    return start;
}

NODE display(NODE start)
{
    NODE temp;
    if(start==NULL)
    {
        printf("List Is Empty And Cannot Be Displayed\n");
        exit(0);
    }
    temp=start;
    printf("items are \n");
    printf("\n");
    for(temp=start;temp!=NULL;temp=temp->next)
    {
      printf("%d\n",temp->data);
    }
    printf("\n");
    return start;
}


void bubbleSort(NODE start)
{
    int swapped;
    NODE cur;
    NODE prev = NULL;

    if (start == NULL)
    {
        printf("Empty Linked List\n");
        return;
    }

    do
    {
        swapped = 0;
        cur = start;

        while (cur->next != prev)
        {
            if (cur->data > cur->next->data)
            {
                swap(cur, cur->next);
                swapped = 1;
            }
            cur = cur->next;
        }
        prev=cur;
    }
    while (swapped);
}
void swap(NODE a,NODE b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void reverseList(NODE start)
{
    NODE prev,cur;

    if(start!= NULL)
    {
        prev = start;
        start = start->next;
        cur=start;
        prev->next = NULL; // Make first node as last node
        while(start!= NULL)
        {
            start=start->next;
            cur->next = prev;

            prev = cur;
            cur = start;
        }
        start=prev; // Make last node as head

        printf("SUCCESSFULLY REVERSED LIST\n");
    }

    NODE temp;
    temp=start;
    printf("Reversed List is \n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}


int main()
{

    int option,item;
    NODE start=NULL;
    do
    {
        printf("1:Insert Front\n");
        printf("2:Insert End\n");
        printf("3:Delete First\n");
        printf("4:Delete End\n");
        printf("5:Display\n");
        printf("6:Sort\n");
        printf("7:Reverse\n");
        printf("8:exit\n");
        printf("Enter Your Choice\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            start=insert_front(item,start);
            break;
        case 2:
            printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            start=insert_end(item,start);
            break;

        case 3:
            start=delete_front(start);
            break;

        case 4:
            start=delete_end(start);
            break;

        case 5:
            start=display(start);
            break;

        case 7:
            bubbleSort(start);
            printf("Items In Sorted Order are\n");
            start=display(start);
            break;

        case 8:
            reverseList(start);
            break;
        }
    }while(option!=10);
}
