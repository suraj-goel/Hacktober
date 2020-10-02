#include<stdio.h>
#include<stdlib.h>
struct node{
        
        int val;
        struct node *next;
};
struct node *insertb(struct node *head)
{
        struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));
	
        int x;
	printf("Enter Number to Insert");
	scanf("%d",&x);	
	
	q->val=x;
	q->next=head->next;
	head->next=q;
	head->val++;
	
	return head;
        
        
}
struct node *inserte(struct node *head){
	struct node *p=head,*q=(struct node *)malloc(sizeof(struct node));

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
	while((p->next)->val!=y)
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
	
	p=p->next;
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
	
	struct node *p=head->next,*q;
		
	if(head->next==NULL)
	{
		printf("Empty");
		return head;
	}
	q=head->next->next;
	free(head->next);
	head->next=q;
	head->val--;	
	return head;
}

struct node *deletee(struct node *head){
	struct node *p=head;
	if(p->next==NULL)
		return deleteb(head);
	if(head->next->next==NULL)
		{
			free(head->next);
			
	                head->val--;	
			return head;
		}
	while(p->next->next!=NULL)
	{
		
		p=p->next;
		
	}
	free(p->next);
	p->next=NULL;
	head->val--;	
	return head;
}

struct node *display(struct node *head){
	struct node *p=head;
	if(head->next==NULL)
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
struct node *deletex(struct node *head){
	struct node *p=head,*q;
	int x,y;
	printf("Enter x:");
	scanf("%d",&x);
	p=p->next;
	if(p->val==x)
	        {
	        head->next=p->next;
	        free(p);
	        head->val--;
	        return head;
	        }
	while(p->next->val!=x){
		p=p->next;
	}
	q=p->next->next;
	free(p->next);
	head->val--;
	p->next=q;
	return head;
}


main()
{
        struct node *head=(struct node *)malloc(sizeof(struct node));
        head->val=0;
        int t;
        head->next=NULL;
        while(1){
		printf("1. To insert at begining:");
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
                                head=insertbfr(head);
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
