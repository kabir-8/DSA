#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int val;
    struct node *next;
};
void removenode(struct node **p,int key)
{
    int flag=0;
    struct node *cur=*p;
    struct node *n=cur->next;
    if(cur->val==key)
    {
        cur->val=n->val;
        cur->next=n->next;
        free(n);
        return;
    }
    while(n!=NULL)
    {
        if(n->val==key)
        {
            cur->next=n->next;
            free(n);
            flag=1;
            break;
        }
        cur=cur->next;
        n=n->next;
        
    }
    if(flag==0)
    {
        printf("Node not found!!!\nTry Again...\n");
    }
    else
    printf("Node Deleted Successfully...\n");
}

void appendnode(struct node **p,int v)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->val=v;
    newnode->next=NULL;
    if(*p==NULL)
    {
        *p=newnode;
    }
    else
    {
    struct node *temp=*p;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    }

}

    

void printlist(struct node **p)
{
    struct node*temp=*p;
    printf("List----> ");
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    
}
void insertnode(struct node **p,int key,int v)
{
    int flag=0;
    struct node *newnode=malloc(sizeof(struct node));
    struct node *cur=*p;
    newnode->val=v;
    while(cur!=NULL)
    {
        if(cur->val==key)
        {
            newnode->next=cur->next;
            cur->next=newnode;
            flag=1;
            break;
            
        }
        cur=cur->next;
    }
    if (flag==0)
    {
        printf("Node Not Found :(\nTry Again...");
    }
    else
    printf("Node Inserted Successfully!!!\n");
    

}

int main()
{
    system("cls");
    int len,i,val;
    struct node *head=NULL;
    int c;
    while(c!=6)
    {
    
    printf("-------------Linked List Operations----------\n");
    printf("1.Create a Linked List\n");
    printf("2.Add Node\n");
    printf("3.Remove Node\n");
    printf("4.Insert Node\n");
    printf("5.Display Linked List\n");
    printf("6.EXIT\n");
    printf("Enter Your Choice:");
    scanf("%d",&c);
    switch (c)
    {
        case 1:
        {
        int len;
        printf("Enter Length of Linked List:");
        scanf("%d",&len);
        for(int i=0;i<len;i++)
        {
            int v;
            printf("Enter Node Value:");
            scanf("%d",&v);
            appendnode(&head,v);
        }
        printf("Linked List Created Successfully!!\n");
        
        
        }
        getch();
        system("cls");
        break;
        case 2:
        {
        int v;
        printf("Enter Node Value:");
        scanf("%d",&v);
        appendnode(&head,v);
        printf("Node Added!!");
        getch();
        system("cls");
        break;
        }
        case 3:
        {
        int v;
        printlist(&head);
        printf("Enter Node To Be Deleted:");
        scanf("%d",&v);
        removenode(&head,v);
        printlist(&head);
        getch();
        system("cls");
        }
        break;
        case 4:
        {
        int key,v;
        printlist(&head);
        printf("Enter Position:");
        scanf("%d",&key);
        printf("Enter Node to be inserted:");
        scanf("%d",&v);
        insertnode(&head,key,v);
        printlist(&head);

        getch();
        system("cls");
        }
        break;
        case 5:
        printlist(&head);
        getch();
        system("cls");
        break;
        default:
        system("cls");
        break;
    }
    }
    

    



    return 0;
}