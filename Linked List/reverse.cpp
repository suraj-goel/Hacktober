#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};/*struct node*palin(struct node*head){
	struct node *p=head,*q,*r;
	if(head==NULL)
	{
		printf("palin");
		return head;
	}
	q=head->next;
	while(q->next!=NULL)
		q=q->next;
	while(1){
		
		if(p->val!=q->val)
		{
			printf("not palin");
			break;
		}
		if(p->next==q){
		
			printf("palin");
			break;
		}
		
		r=p;
		while(r->next!=q)
			r=r->next;
		q=r;
		p=p->next;
		if(p==q)
			{
				printf("palin");
				break;
			}
		
	}
	return head;
	
	
}*/
struct node *insertb(struct node *head){
	
	struct node *p=(struct node *)malloc(sizeof(struct node));
	int x;
	printf("Enter Number to Insert");
	scanf("%d",&x);	
	if(head==NULL)
	{
		p->val=x;
		p->next=NULL;
		return p;
	}
	p->val=x;
	p->next=head;
	head=p;
	return p;
}
struct node *inserte(struct node *head){
	struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));
	if(p==NULL)
		return insertb(head);
	int x;
	printf("Enter Number to Insert");
	scanf("%d",&x);
	while(p->next!=NULL)
	{
		
		p=p->next;
		
	}
	q->val=x;
	q->next=NULL;
	p->next=q;
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
	
	if(p->val==y)
		{
		q->next=p;
		return q;
		}
	while((p->next)->val!=y)
	{
		p=p->next;
	}	
	q->next=p->next;
	p->next=q;
	
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
		q->next=p;
		return q;
		}
	while(p->val!=y)
	{
		p=p->next;
	}	
	q->next=p->next;
	p->next=q;	
	return head;
}
struct node *deleteb(struct node *head){
	
	struct node *p=head;
		
	if(head==NULL)
	{
		printf("Empty");
		return NULL;
	}
	p=p->next;
	free(head);
	return p;
}

struct node *deletee(struct node *head){
	struct node *p=head;
	if(p==NULL)
		return deleteb(head);
	if(head->next==NULL)
		{
			free(head);
			return NULL;
		}
	while(p->next->next!=NULL)
	{
		
		p=p->next;
		
	}
	free(p->next);
	p->next=NULL;
	return head;
}

struct node *deletex(struct node *head){
	struct node *p=head,*q;
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	if(p->val==x)
	{
		q=p->next;
		free(p);
		return q;
	}
	while(p->next->val!=x){
		p=p->next;
	}
	q=p->next->next;
	free(p->next);
	p->next=q;
	return head;
}

struct node *reverse(struct node *head){
	struct node *p=head,*q,*head2=NULL;
	q=head;
	while(p!=NULL)
	{p=head;
		
		
		while(p->next!=NULL&&p->next->next!=NULL)
		{
			p=p->next;
		}
		if(p->next!=NULL){
			
			if(head2==NULL){
				
				head2=p->next;
				p->next=NULL;
				head2->next=NULL;
				q=head2;
				continue;
			}
			
			
			q->next=p->next;
			p->next=NULL;
			q=q->next;
		}
		else
		{
			if(head2==NULL){
				
				head2=p;
				p=NULL;
				head2->next=NULL;
				q=head2;
				continue;
			}
			
			
			q->next=p;
			p=NULL;
			q=q->next;
		
		}
	}
	
	return head2;
}

struct node *display(struct node *head){
	struct node *p=head;
	if(head==NULL)
		{
		printf("Empty:");
		return head;
		}
	while(p!=NULL){
		
		printf("%d ",p->val);
		p=p->next;
	}
	return head;
}
bool check(struct node *head1,struct node *head2)
{struct node *p=head1,*q=head2;
while(p!=NULL&&q!=NULL)
	{
	if(p->val!=q->val)
		{
			printf("not equal");
			return false;
		}
		p=p->next;
		q=q->next;
	}
	if(p==NULL^q==NULL)
	{
		printf("not equal");
		return false;
		
	}
	return true;
}
struct node *swap(int x,struct node *head){
	struct node*p=head,*q;
	
	if(p->val==x)
	{
		q=p->next;
	p->next=q->next;
	q->next=p;
	head=q;
	return head;
	}
	while(p->next->val!=x){
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	q->next=p->next->next;
	p->next->next=q;
	return head;
}
struct node *move(struct node*head){
	struct node*p=head,*q;
	int x=-1;
	if(p==NULL)
	{
		printf("NULL");
		return head;
	}
	while(p!=NULL)
	{
		if(p->val>x)
			{
				x=p->val;
				q=p;
			}
		p=p->next;
		
	}
	p=head;
	while(p->next!=q){
		p=p->next;
	}
	p->next=q->next;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
	q->next=NULL;
	return head;
}
int palin(struct node* head){
	struct node *p=head,*q=NULL,*r;
	while(p!=q && p->next!=q){
		 r=p->next;
		 while(r->next!=q)
		    r=r->next;
		 q=r;
		 if(p->val!=q->val)
		    return 0;
		 p=p->next;
	}
	return 1;
}

main(){
	
	struct node *head=NULL;int t;
	while(1){
		printf("\n1. To insert at begining:");
		printf("\n2. To insert at end:");
		printf("\n3. To insert x before y:");
		printf("\n4. To insert x after y:");
		printf("\n5. To delete at begining:");
		printf("\n6. To delete at end:");
		printf("\n7. To delete x:");
		printf("\n8. To Display content");
		printf("\n9. To reverse");
		printf("\n10. To reverse");
		
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
			case 9: head= reverse(head);
			break;
			case 10:head =swap(3,head);
				break;
			case 11:
				head = move(head);
					break;
			case 12:
				if(palin(head)==1)
				 printf("Palindrome");
				else
				printf("Not palindrome");
				break;
		}
		
	}
}
