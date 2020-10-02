#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};
struct node *insertb(struct node *head){
	
	struct node *p=(struct node *)malloc(sizeof(struct node)),*q=head;
	int x;
	printf("Enter Number to Insert");
	scanf("%d",&x);	
	
	p->val=x;
	p->next=head->next;
	head->next=p;
	head->val++;
	return head;
	
}
struct node *inserte(struct node *head){
	struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));
	int x;
	printf("Enter Number to Insert");
	scanf("%d",&x);
	while(p->next!=head)
	{
		
		p=p->next;
		
	}
	q->val=x;
	q->next=head;
	p->next=q;
	head->val++;
	
	return head;
}
struct node *insertbfr(struct node *head){
	struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	printf("Enter y:");
	scanf("%d",&y);
	
	q->val=x;
	while(p->next->val!=y)
	{
	p=p->next;
	}
	q->next=p->next;
	p->next=q;
	head->val++;
	return head;
	
	
}

struct node *insertafter(struct node *head){
	struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	printf("Enter y:");
	scanf("%d",&y);
	q->val=x;
	
	if(p->val==y)
		{
		return inserte(head);
		}
	while(p->val!=y)
	{
		p=p->next;
	}	
	q->next=p->next;
	p->next=q;
	head->val++;
	return head;
}
struct node *deleteb(struct node *head){
	
	struct node *p=head,*r;
		
	if(head==NULL)
	{
		printf("Empty");
		return NULL;
	}
	if(head->next==head)
	{
		free(head);
		return NULL;
	}
	
	while(p->next!=head)
	{	
		p=p->next;	
	}
	r=head->next;
	p->next=r;
	free(head);
	head->val--;
	return r;
	
}

struct node *deletee(struct node *head){
	struct node *p=head;
	if(p==NULL)
		return deleteb(head);
	if(head->next==head)
		{
			free(head);
			return NULL;
		}
	while(p->next->next!=head)
	{
		
		p=p->next;
		
	}
	free(p->next);
	p->next=head;
	head->val--;
	return head;
}

struct node *deletex(struct node *head){
	struct node *p=head,*q;
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	if(p->val==x)
	{

		return deleteb(head);
	}
	while(p->next->val!=x){
		p=p->next;
	}
	if(p->next->next==head)
	        return deletee(head);
	q=p->next->next;
	free(p->next);
	p->next=q;
	
	head->val--;
	return head;
}

struct node *display(struct node *head){
	struct node *p=head;
	if(head->val==0)
		{
		printf("Empty:");
		return head;
		}
		
	while(p->next!=head){
		if(p==head)
		printf("number of elements ");
		printf("%d ",p->val);
		if(p==head)
		printf("\n");
		
		p=p->next;
	}
		printf("%d ",p->val);
		
	return head;
}
main(){
	
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head->val=0;
	head->next=head;
	int t;
	
	while(1){
		printf("\n1. To insert at begining:");
		printf("\n2. To insert at end:");
		printf("\n3. To insert x before y:");
		printf("\n4. To insert x after y:");
		printf("\n5. To delete at begining:");
		printf("\n6. To delete at end:");
		printf("\n7. To delete x:");
		printf("\n8. To Display content");
		scanf("%d",&t);
		switch(t){
				
			case 1: 
				head=insertb(head);
				break;
			case 2:
				head=inserte(head);
				break;
			case 3:
				head = insertbfr(head);
				break;
			case 4:
				head=insertafter(head);
				break;
			case 5:
				head= deleteb(head);	
				break;
			case 6:
				head=deletee(head);
				break;
			case 7:
				head=deletex(head);
				break;
				
			case 8:
				head=display(head);
				break;
			
		}
		
	}
}
