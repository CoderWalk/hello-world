#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct ele
{
	int data;
	struct ele * next;
}ele;
ele *head,*tail,*node,*cur,*prev;
void add();
void show();
void insert();
void delet();
void main()
{
	int ch;
	clrscr();
	head=tail=cur=NULL;
	do{
		printf("\n1:add\n2:show\n3:insert\n4:delete\nenter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add();break;
			case 2:show();break;
			case 3:insert();break;
			case 4:delet();break;
		}
	}while(ch!=5);
}
void add()
{
	node=(ele*)malloc(sizeof(ele));
	printf("\nenter node data");
	scanf("%d",&node->data);
	node->next=NULL;
	if(head==NULL)
	{
	       head=tail=node;
	}
	else
	{
		tail->next=node;
		tail=node;
	}
}
void show()
{
	cur=head;
	while(cur!=NULL)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}
}
void insert()
{
	int i=1,l;
	printf("\nenter location to insert new node");
	scanf("%d",&l);
	node=(ele*)malloc(sizeof(ele));
	printf("\nenter node data");
	scanf("%d",&node->data);
	node->next=NULL;
	prev=NULL;
	cur=head;
	while(i<l && cur!=NULL)
	{
		prev=cur;
		cur=cur->next;
		i++;
	}
	if(i>l)
	printf("location not found");
	else
	{
		if(cur==head)
		{
			node->next=head;
			head=node;
		}
		else if(prev==tail)
		{
			tail->next=node;
			tail=node;
		}
		else
		{
			prev->next=node;
			node->next=cur;
		}
	}
}

void delet()
{

	int i=1,l;
	printf("\nenter location to delete  node");
	scanf("%d",&l);
	prev=NULL;
	cur=head;
	while(i<l && cur!=NULL)
	{
		prev=cur;
		cur=cur->next;
		i++;
	}
	if(i>l)
	printf("location not found");
	else
	{
		if(cur==head)
		{
			head=cur->next;
			cur->next=NULL;
		}
		else if(cur==tail)
		{
			tail=prev;
			tail->next=NULL;
		}
		else
		{
			prev->next=cur->next;
		}
		free(cur);
	}
}