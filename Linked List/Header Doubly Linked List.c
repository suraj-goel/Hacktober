#include<stdio.h>
#include<stdlib.h>
struct dnode{
	int info;
	struct dnode *prev,*next;
};
typedef struct dnode DNODE;
DNODE* insertbeg(DNODE *head,int y){
	DNODE *p;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	p->prev=head;
	p->next=head->next;
	head->next=p;
	++head->info;
	if(head->info!=0)
	   (head->next)->prev=p;
	return head;
}
DNODE* insertend(DNODE *head,int y){
	if(head->info==0){
		head=insertbeg(head,y);
		return head;
	}
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	p->next=NULL;
	++head->info;
	while(q->next!=NULL)
	    q=q->next;
	q->next=p;
	p->prev=q;
	return head;
}
DNODE* insertbefore(DNODE *head,int x,int y){
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	p->info=y;
	if(head->info==0){
		printf("%d doesn't exist in the linked list\n",x);
        return head;
	}
	if((head->next)->info==x){
		head=insertbeg(head,y);
		return head;
	}
	q=q->next;
    while(q->next!=NULL && (q->next)->info!=x)
          q=q->next;
	if(q->next==NULL){
		printf("%d doesn't exist in the linked list\n",x);
        return head;
	}
	++head->info;
	p->next=q->next;
	p->prev=q;
	(q->next)->prev=p;
	q->next=p;
	return head;
}
DNODE* insertafter(DNODE *head,int x,int y){
	DNODE *p,*q=head->next;
       p=(DNODE *)malloc(sizeof(DNODE));
       p->info=y;
       if(head->info==0){
           printf("%d doesn't exist in the linked list\n",x);
           return head;
       }
       while(q!=NULL && q->info!=x)
             q=q->next;
       if(q==NULL){
           printf("%d doesn't exist in the linked list\n",x);
           return head;
       }
       if(q->next==NULL){
       	   head=insertend(head,y);
       	   return head;
	   }
       p->next=q->next;
       p->prev=q;
       (q->next)->prev=p;
       q->next=p;
       ++head->info;
       return head;
}
DNODE* deletestart(DNODE *head){
	DNODE *p=head;
	if(head->info==0){
		printf("List is empty");
		return head;
	}
	if(head->info==1){
		head->next=NULL;
		--head->info;
		free(p);
		return head;
	}
	--head->info;
	p=p->next;
	head->next=p->next;
	(p->next)->prev=head;
	free(p);
	return head;	
}
DNODE*deleteend(DNODE *head){
	DNODE *p=head->next;
	if(head->info==0){
		printf("List is empty");
		return head;
	}
	if(head->info==1){
		head->next=NULL;
		--head->info;
		free(p);
		return head;
	}
	while((p->next)->next!=NULL)
          p=p->next;
     free(p->next);
     --head->info;
     p->next=NULL;
	return head;
}
DNODE* deletex(DNODE *head,int x){
        DNODE *p=head->next,*q;
        if(head->info==0){
           printf("List is empty\n");
           return head;	
		}
		if(p->info==x){
		   head=deletestart(head);
		   return head;	
		}
		while(p->next!=NULL && (p->next)->info!=x)
            p=p->next;
        if(p->next==NULL){
         printf("%d is not present in the linked list\n",x);
         return head;
        }
        q=p->next;
        if(q->next==NULL){
        	head=deleteend(head);
        	return head;
		}
		--head->info;
		p->next=q->next;
		(q->next)->prev=p;
		free(q);
		return head;
}
void display(DNODE *head){
	DNODE *p=head->next;
	if(head->info==0){
		printf("List is empty");
	}
	else{
	    for(;p!=NULL;p=p->next)
	       printf("%d ",p->info);
    }
}
main(){
     DNODE *head=(DNODE *)malloc(sizeof(DNODE));
	 head->info=0;
	 head->prev=NULL;
	 head->next=NULL;
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
        else if(choice==5){
           head=deletestart(head);
       }
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

