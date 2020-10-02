#include<stdio.h>
#include<stdlib.h>
struct dnode{
	int info;
	struct dnode *prev,*next;
};
typedef struct dnode DNODE;
DNODE* insertbeg(DNODE *head,int y){
	 DNODE *p,*q=head; 
	 p=(DNODE *)malloc(sizeof(DNODE));
	 p->info=y;
	 if(head==NULL){
	 	p->prev=p;
	 	p->next=p;
	 }
	 else{
	    p->next=head;
	    p->prev=head->prev;
	    head->prev=p;
	    while(q->next!=head)
	       q=q->next;
	    q->next=p;
     }
	 return p;
}
DNODE* insertend(DNODE *head,int y){
	DNODE *p,*q=head;
	p=(DNODE *)malloc(sizeof(DNODE));
	if(head==NULL){
		head=insertbeg(head,y);
		return head;
	}
	p->info=y;
    p->next=head;
    p->prev=head->prev;
    (head->prev)->next=p;
    head->prev=p;
    return head;
}
DNODE* insertafter(DNODE *head,int x,int y){
	    DNODE *p,*q=head;
        p=(DNODE *)malloc(sizeof(DNODE));
        p->info=y;
        if(head==NULL){
            printf("%d doesn't exist in the linked list\n",x);
            return head;
        }
        if((head->prev)->info==x){
       	    head=insertend(head,y);
       	    return head;
	    }
        while(q->next!=head && q->info!=x)
            q=q->next;
        if(q->next==head){
           printf("%d doesn't exist in the linked list\n",x);
           return head;
        }
        p->next=q->next;
        q->next=p;
        p->prev=q;
        (p->next)->prev=p;
        return head;
}
DNODE* insertbefore(DNODE *head,int x,int y){
        DNODE *p,*q=head->next;
        p=(DNODE *)malloc(sizeof(DNODE));
        p->info=y;
        if(head==NULL){
           printf("%d doesn't exist in the linked list\n",x);
           return head;
        }
        if(head->info==x){
        	head=insertbeg(head,y);
        	return head;
		}
        while(q!=head && (q->info!=x))
           q=q->next;
        if(q->info!=x){
           printf("%d doesn't exist in the linked list\n",x);
           return head;
        }
        p->next=q;
        p->prev=q->prev;
        (q->prev)->next=p;
        q->prev=p;
        return head;     
}
DNODE* deletestart(DNODE *head){
        DNODE *p=head;
        if(head==NULL){
           printf("List is empty\n");
           return NULL;
        }
        if(head->next==head){
     	   free(p);
     	   return NULL;
	    }
        head=head->next;
        (p->prev)->next=head;
        head->prev=p->prev;
        free(p);
        return head;
}
DNODE* deleteend(DNODE *head){
        DNODE* p=head;
        if(head==NULL){
           printf("List is empty\n");
           return head;
        }
        if(head->next==head){
           free(p);
           return NULL;
        }
        p=p->prev;
        (p->prev)->next=head;
        head->prev=p->prev;
        free(p);
        return head;
}
DNODE* deletex(DNODE *head,int x){
        DNODE *p=head;
        if(head==NULL){
           printf("List is empty\n");
           return head;	
		}
		if(head->info==x){
		   head=deletestart(head);
		   return head;	
		}
		p=p->next;
		while(p!=head && p->info!=x)
		      p=p->next;
	    if(p==head){
	    	printf("%d doesn't exist in the linked list\n",x);
            return head;
		}
		(p->prev)->next=p->next;
		(p->next)->prev=p->prev;
		free(p);
		return head;
}
void display(DNODE *head){
     DNODE *p=head;
     if(head==NULL)
        printf("List is empty\n");
     else{
     	printf("%d\t",p->info);
     for(p=head->next;p!=head && p!=NULL;p=p->next)
        printf("%d\t",p->info);
        printf("\n");
     }
}
main(){
     DNODE *head=(DNODE *)malloc(sizeof(DNODE));
	 head=NULL;
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

