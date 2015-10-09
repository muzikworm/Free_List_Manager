#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
void *add;
struct node *next,*prev;
}*temp,*top,*beg,*temp2;
int count=0;
int init(int a)
{

   temp=(struct node *)malloc(sizeof(struct node));
   temp->data=a;
   temp->add=malloc(a*sizeof(char));
   temp->prev=NULL;
   temp->next=NULL;
   beg=temp;
   top=beg;

}
int insertatend(int a)
{
  printf("Malloc called  count=%d\n",count);
  if(top==NULL)
  {
    init(a);
    count++;

  }
  else{
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=a;
    temp->add=malloc(a*sizeof(char));
    temp->prev=top;
    temp->next=NULL;
    top->next=temp;
    top=temp;
    count++;
  }

}
void delete(int x)
{

    if(beg==NULL)
    {
        printf("No memory allocated");
    }
    else if (x==1 || count==1)
    {
        if(beg->next==NULL)
        {
            beg=NULL;
            free(beg);
            count--;
        }
        else
        {   temp=beg->next;
            beg=NULL;
            beg=temp;
            count--;
        }

    }
    else if(x>count)
    {
        printf("No memory defined");
    }
    else if (count==x)
    {
        int i=1;
        temp=beg;
        while(i<count)
        {
            temp=temp->next;
              i++;
        }
        temp->prev->next=NULL;
        temp=NULL;
        free(temp);
        count--;
    }
    else
    {
        temp=beg;
        int i=1;
        while(i<x)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        free(temp);
        temp=NULL;
        count--;

    }

}
void print()
{
    if(count==0 && top)
    {
        printf("No memory Allocated");
    }
    temp2=beg;
    while(temp2!=NULL)
    {

        printf("%d %p \n",temp2->data,temp2->add);
        temp2=temp2->next;
    }
}
int main()
{
top=NULL;
int i=0,a;
char cmd[10];
while(1)
{
    printf("\n");
    scanf("%s",cmd);
    if(strcmp(cmd,"malloc")==0)
    {

        scanf("%d",&a);
       insertatend(a);
    }
    else if(strcmp(cmd,"free")==0)
    {
        scanf("%d",&a);
        delete(a);
    }
    else if (strcmp(cmd,"print")==0)
    {
        print();
    }
    else if (strcmp(cmd,"exit")==0)
    {
        exit(0);
    }



}
return 0;
}
