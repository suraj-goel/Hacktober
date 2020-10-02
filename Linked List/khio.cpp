#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};
typedef struct node nd;
nd *insertb(nd* head){

	printf("insertb");
	nd *p=(nd *)malloc(sizeof(nd));
	int x;
	scanf("%d",&x);
	p->val=x;
	p->next=head;
	return p;
}
nd *inserte(nd*head){
	
	printf("inserte");
	int x;
	nd *p=(nd *)malloc(sizeof(nd)),*q=head;
	if(q==NULL)
		return insertb(head);
	scanf("%d",&x);
	while(q->next!=NULL)
		q=q->next;
	p->val=x;
	p->next=NULL;
	q->next=p;
	return head;
}
nd *deleteb(nd *head){
	
	printf("deleteb");
	if(head==NULL)
		return NULL;
	nd *p=head;
	p=p->next;
	free(head);
	return p;
}
nd *deletee(nd* head){
	
	printf("deletee");
	nd *p=head,*q=head;
	if(p==NULL||p->next==NULL)
		return deleteb(head);
	while(p->next->next!=NULL)
		p=p->next;
	q=p->next;
	p->next=q->next;
	free(q);
	return head;

}
nd *display(nd *head){
	printf("display");
	nd *p=head;
	while(p!=NULL)
		{
		printf("%d",p->val);
		p=p->next;
		}
	return head;
	
}

int main(){
	nd *head=NULL;
	int t=1;
	while(t){
		
		scanf("%d",&t);
		switch(t){
			case 1: head=insertb(head);
				break;
			case 2: head=inserte(head);
				break;
			case 3: head = deleteb(head);
				break;
			case 4: head= deletee(head);
				break;
			case 5: head=display(head);
				
		}
		
	}
	
	
}
