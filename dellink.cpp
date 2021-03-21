#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
typedef struct node Node;

struct node
{
    int num;
    Node *next;

}*head;

void create_node();
void del_Begin();
void del_End();
void del_Middle(int c);
void display();

int main()
{
    system("CLS");
    int c,ch,num,pos;
    printf("\t\t\t\t1. Create Node\n\t\t\t\t2. Delete\n\t\t\t\t3. Display\n\t\t\t\t4. Exit\n\n");
    printf("\t\t\t\tEnter choice: ");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        create_node();
        break;
    case 2:
        system("CLS");
        printf("\t\t\t\t1. Delete In First\n");
        printf("\t\t\t\t2. Delete In End\n");
        printf("\t\t\t\t3. Delete In Middle\n\n");
        printf("\t\t\t\tEnter Choice: ");
        scanf("%d", &ch);
        if(ch==1)
        {
            del_Begin();
            getch();
            main();
        }
        else if(ch==2)
        {
            del_End();
            getch();
            main();
        }
        else if(ch==3)
        {
            printf("\n\t\t\t\tEnter Position: ");
            scanf("%d", &pos);
            del_Middle(pos);
            getch();
            main();
        }
        else
        {
            printf("\n\t\t\t\tWrong Choice!!\n");
            getch();
            main();
        }
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("\n\t\t\t\tWrong Choice!!!\n\n\t\t\t\tTry Again");
        getch();
        main();
    }
    return 0;
}

void create_node()
{
    Node *fnode, *tmp;
    int num;
    int i,n;
    head=(Node*)malloc(sizeof(Node));
    if(head==NULL)
    {
        printf("\n\t\t\t\tMemory can not be allocated");
    }
    else
    {
        printf("\n\t\t\t\tEnter the number of nodes:");
        scanf("%d", &n);
        printf("\n\t\t\t\tEnter data for node 1:");
        scanf(" %d", &num);
        head->num=num;
        head->next=NULL;
        tmp=head;
        for(i=2; i<=n; i++)
        {
            fnode=(Node*)malloc(sizeof(Node));
            if(fnode==NULL)
            {
                printf("\n\t\t\t\tMemory can not be allocated");
                break;
            }
            else
            {
                printf("\n\t\t\t\tEnter data for node %d:", i);
                scanf(" %d", &num);
                fnode->num=num;
                fnode->next=NULL;
                tmp->next=fnode;
                tmp=tmp->next;
            }
        }
        main();
    }
}
void del_Begin()
{
    Node *fnode,*start;
    fnode = (Node*)malloc(sizeof(Node));
    if(fnode==NULL)
        cout<<"\nError......List is empty\n";
    else
    {
        Node* tmp=start;
        start=tmp->next;
        delete tmp;
        cout<<"\nFirst node deleted successfully....!!!";

    }
}
void del_End()
{
    Node *fnode,*start,*tmp;
    fnode = (Node*)malloc(sizeof(Node));
    if(fnode==NULL)
        cout<<"\nError....List is empty";
    else

    {
        Node* fnode=start;

        while(fnode->next->next!=NULL)
            fnode=fnode->next;
        tmp=fnode->next;
        fnode->next=NULL;
        delete tmp;
        cout<<"\nDeleted successfully...";
    }

}

void del_Middle(int c)
{
    int i;
    Node *fnode,*start, *tmp;
    fnode = (Node*)malloc(sizeof(Node));
    //Node* fnode=start;
    for(int i=2; i<c; i++)
    {
        fnode=fnode->next;
        if(fnode==NULL)
            cout<<"\nNode not found\n";
    }
    if(i==c)
    {
        Node* p=fnode->next;
        fnode->next=p->next;
        delete p;
        cout<<"Deleted Successfully";
    }


}

void display()
{
    Node *tmp;
    if(head==NULL)
    {
        printf("\n\t\t\t\tList is empty");
    }
    else
    {
        tmp=head;
        printf("\n\t\t\t\tData Entered in list:\n\n");
        while(tmp!=NULL)
        {
            printf("\t\t\t\tDATA = %p %d %p\n",tmp, tmp->num, tmp->next);
            tmp=tmp->next;
        }
    }
    getch();
    main();
}

