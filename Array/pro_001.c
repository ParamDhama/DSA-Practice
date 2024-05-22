#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int arr[100],n=-1;
void display();
void insert();
void delete();
void search();
void update();

void main()
{
    int opt;
    while (1)
    {
        printf("\nEnter an option");
        printf("\n1. Display array");
        printf("\n2. Insert element in array");
        printf("\n3. Delete element in array");
        printf("\n4. Search element in array");
        printf("\n5. Update element in array");
        printf("\n6. Exit()\n");

        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            search();
            break;
        case 5:
            update();
            break;
        case 6:
            exit(0);
            break;
        
        default:
            printf("\nWrong Choice");
            break;
        }
    }
    
    
}

void display()
{
    printf("\nArrar:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
}
void insert()
{
    int val;
    
    printf("Enter value you want add in array");
    scanf("%d",&val);
    
    arr[n++] = val;
    
}


void delete()
{
    int pos;
    printf("Enter index: ");
    scanf("%d",&pos);
    for (int i = pos; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
}

void search()
{
    int val,index=-1;

    printf("Enter your value here");
    scanf("%d",&val);
    for (int i = 0; i < n+1; i++)
    {
        if(arr[i] == val)
        {
            printf("\nIndex = %d",i);
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        printf("\nNot found");
    }
}

void update()
{
    int index,value;
    printf("Enter index where you want to change value: ");
    scanf("%d",&index);

    printf("Enter new value: ");
    scanf("%d",&value);

    arr[index] = value;
}