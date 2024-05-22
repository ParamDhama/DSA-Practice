/*
Program name : Singly Linked List
Author : Param Dhama
Date : 23/May/2024
Description : In this program i perform all singly linked list operation like insertion, delection , Search and Display
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct linkList
{
    int info;
    struct linkList *next;
};

typedef struct linkList *nodeptr;

nodeptr head;

// Initial point of linked list
void init()
{
    head = NULL;
}

// Create a node of linked list
nodeptr createNode()
{
    return (nodeptr)malloc(sizeof(struct linkList));
}

// Insertion operation :
// Insertion at beginning of the list
void insAtBeg()
{
    nodeptr p = createNode();
    printf("\nEnter your element value here: ");
    scanf("%d", &p->info);

    p->next = head;
    head = p;
}

// Insertion at end of the list
void insAtEnd()
{
    nodeptr loc;
    nodeptr p = createNode();
    printf("\nEnter your element value here: ");
    scanf("%d", &p->info);
    p->next = NULL;
    if (head==NULL)
    {
        head = p;
    }
    else{
    for (loc = head; loc->next != NULL; loc = loc->next);
    loc->next = p;
    }
    
}

// Insertion before a Element
void insBefEle()
{
    nodeptr loc;
    nodeptr p = createNode();
    int ele;
    printf("\nEnter your element value here: ");
    scanf("%d", &p->info);
    printf("\nEnter element value: ");
    scanf("%d", &ele);
    for (loc = head; (loc->next)->info != ele && loc->next != NULL; loc = loc->next)
        ;
    p->next = loc->next;
    loc->next = p;
}

// insertion after a node
void insAftEle()
{
    nodeptr loc;
    nodeptr p = createNode();
    int ele;
    printf("\nEnter your element value here: ");
    scanf("%d", &p->info);
    printf("\nEnter element value: ");
    scanf("%d", &ele);
    for (loc = head; loc->info != ele && loc->next != NULL; loc = loc->next)
        ;
    p->next = loc->next;
    loc->next = p;
}

// Deletion Operation:
// Deletion form beginning of the list
void delAtBeg()
{
    nodeptr p = head;
    head = p->next;
    free(p);
    printf("\nDeletion successfully");
}

// Deletion from end Of the list
void delAtEnd()
{
    nodeptr p, loc;
    for (loc = head; (loc->next)->next != NULL; loc = loc->next)
        ;
    p = loc->next;
    loc->next = NULL;
    free(p);
    printf("\nDeletion successfully");
}

// Deletion before a element
void delBefEle()
{
    int ele;
    nodeptr p, loc;
    printf("\nEnter element value: ");
    scanf("%d", &ele);
    for (loc = head; ((loc->next)->next)->info != ele && loc->next != NULL; loc = loc->next)
        ;
    p = loc->next;
    loc->next = p->next;
    free(p);
    printf("\nDeletion successfully");
}

// Deletion After a element
void delAftEle()
{
    int ele;
    nodeptr p, loc;
    printf("\nEnter element value: ");
    scanf("%d", &ele);
    for (loc = head; loc->info != ele && loc->next != NULL; loc = loc->next)
        ;
    p = loc->next;
    loc->next = p->next;
    free(p);
}

// Deletion of an element
void delEle()
{
    int ele;
    nodeptr p, loc;
    printf("\nEnter element value: ");
    scanf("%d", &ele);
    for (loc = head; (loc->next)->info != ele && loc->next != NULL; loc = loc->next)
        ;
    p = loc->next;
    loc->next = p->next;
    free(p);
    printf("\nDeletion successfully");
}

// Display all node of the list
void display()
{
    system("cls");
    printf("Link List: \n");
    for (nodeptr loc = head; loc != NULL; loc = loc->next)
    {
        printf("%d\t", loc->info);
    }
    getch();
}

nodeptr search()
{
    nodeptr loc;
    int val;
    system("cls");
    printf("Enter element value: ");
    scanf("%d",&val);
    for(loc = head; loc!=NULL; loc=loc->next){
        if (loc->info == val)
        {
            return loc;
        }
        
    }
    return NULL;
}

int insert()
{
    system("cls");
    int opt;
    printf("\nEnter choice");
    printf("\n1. Insertion at Begninning of linked list");
    printf("\n2. Insertion at End of linked list");
    printf("\n3. Insertion before a element of linked list");
    printf("\n4. Insertion after a element of linked list");
    printf("\n5. Back\n");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        insAtBeg();
        break;
    case 2:
        insAtEnd();
        break;
    case 3:
        insBefEle();
        break;
    case 4:
        insAftEle();
        break;
    case 5:
        return 0;
        break;

    default:
        printf("Wrong Choice");
        insert();
        break;
    }
}

int delete()
{
    system("cls");
    int opt;
    printf("Enter choice");
    printf("\n1. Deletion at Begninning of linked list");
    printf("\n2. Deletion at End of linked list");
    printf("\n3. Deletion before a element of linked list");
    printf("\n4. Deletion after a element of linked list");
    printf("\n5. Deletion  a element of linked list");
    printf("\n6. Back\n");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        delAtBeg();
        break;
    case 2:
        delAtEnd();
        break;
    case 3:
        delBefEle();
        break;
    case 4:
        delAftEle();
        break;
    case 5:
        delEle();
        break;
    case 6:
        return 0;
        break;

    default:
        printf("Wrong Choice");
        delete ();
        break;
    }
}

// Main Function of  program
void main()
{
    init();
    int opt;
    while (1)
    {
        system("cls");
        printf("Enter your choice: \n");
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("\nChoice Correctly");
            break;
        }
    }
}
