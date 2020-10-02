#include<stdio.h>
#include<stdlib.h>
struct dnode{
	int info;
	struct dnode *next,*prev;
};
typedef struct dnode DNODE;
DNODE *insertbeg(DNODE *head,int y){
	DNODE *p;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	p->next=head;
	p->prev=NULL;
	if(head!=NULL)
	  head->prev=p;
	return p;
}
DNODE *insertend(DNODE *head,int y){
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	p->next=NULL;
	if(head==NULL){
	   p->prev=NULL;
	   return p;
    }
    while(q->next!=NULL)
         q=q->next;
    p->prev=q;
    q->next=p;
    return head;
}
DNODE *insertafter(DNODE *head,int y,int x){
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	while(q!=NULL && q->info!=x)
	    q=q->next;
	if(q==NULL){
		printf("%d doesn't exist in the linked list\n",x);
		return head;
	}
    p->prev=q;
    p->next=q->next;
    if(q->next==NULL){
    	head=insertend(head,y);
    	return head;
	}
	(q->next)->prev=p;
	q->next=p;
	return head;
}
DNODE *insertbefore(DNODE *head,int y,int x){
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	while(q!=NULL || q->info!=x)
	    q=q->next;
	if(q==NULL){
		printf("%d doesn't exist in the linked list\n",y);
		return head;
	}
	if(q->prev==NULL){
		head=insertbeg(head,y);//insert be ruko
		return head;
	}
	DNODE *r=q->prev;
	r->next=p;
	p->next=q;
	p->prev=r;
	/* p->prev=q->prev;
	p->next=q;
	(q->prev)->next=p;
	q->prev=p;*/
	return head;
}
DNODE* deletestart(DNODE *head){
     DNODE *p=head;
     if(head==NULL){
        printf("List is empty\n");
        return head;
     }
     head=head->next;
     free(p);
     return head;
}
DNODE* deleteend(DNODE *head){
     DNODE* p=head;
     if(head==NULL){
        printf("List is empty\n");
        return head;
     }
     if(head->next==NULL){
        head=head->next;
        free(p);
        return head;
     }
     while((p->next)->next!=NULL)
          p=p->next;
     free(p->next);
     p->next=NULL;
     return head;
}
DNODE* deletex(DNODE *head,int x){
      DNODE *p=head,*q;
      if(head==NULL){
      printf("List is empty\n");
        return head;
      }
      if(p->info==x){
          head=head->next;
          free(p);
          return head;
      }
      while(p->next!=NULL && (p->next)->info!=x)
            p=p->next;
      if(p->next==NULL){
         printf("%d is not present in the linked list\n",x);
         return head;
      }
      q=p->next;
      p->next=q->next;
      free(q);
}
void display(DNODE *head){
     DNODE *p;
     for(p=head;p!=NULL;p=p->next)
        printf("%d\t",p->info);
}
main(){
     DNODE *head=NULL;
     int choice,x,y;
     while(1){
        printf("Enter 1 to Insert an element at the start of the linked list.\n");
        printf("Enter 2 to Insert an element at the end of the linked list.\n");
        printf("Enter 3 to Insert an element before an existing element whose information is x in a linked list.\n");
        printf("Enter 4 to Insert an element after an existing element whose information is x in a linked list.\n");
        printf("Enter 5 to Delete the first element of the linked list.\n");
        printf("Enter 6 to Delete the last element of the linked list.\n");
        printf("Enter 7 to Delete the element whose information is x from a linked list.\n");
        printf("Enter 8 to Display the contents of the linked list.\n");
        printf("Enter 9 to exit\n");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter number to be inserted:");
            scanf("%d",&y);
            head=insertbeg(head,y);
        }
        else if(choice==2){
            printf("Enter number to be inserted:");
            scanf("%d",&y);
            head=insertend(head,y);
        }
        else if(choice==3){
           printf("Enter element to be inserted");
           scanf("%d",&y);
           printf("Enter x before which number is to be inserted:");
           scanf("%d",&x);
           head=insertbefore(head,x,y);
        }
        else if(choice==4){
           printf("Enter element to be inserted");
           scanf("%d",&y);
           printf("Enter x after which number is to be inserted:");
           scanf("%d",&x);
           head=insertafter(head,x,y);
        }
        else if(choice==5)
           head=deletestart(head);
        else if(choice==6)
           head=deleteend(head);
        else if(choice==7){
           printf("Enter element to be deleted:");
           scanf("%d",&x);
           head=deletex(head,x);
        }
        else if(choice==8)
           display(head);
        else 
           exit(0); 
  }
}

