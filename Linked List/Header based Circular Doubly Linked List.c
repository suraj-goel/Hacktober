#include<stdio.h>
#include<stdlib.h>
struct dnode{
   int info;
   struct dnode *next,*prev;
};
typedef struct dnode DNODE;
DNODE* insertbeg(DNODE *head,int y){
      DNODE *p;
      p=(DNODE *)malloc(sizeof(DNODE));
      ++head->info;
      p->info=y;
      p->next=head->next;
      p->prev=head;
      (head->next)->prev=p;
      head->next=p;
      return head;
}
DNODE* insertend(DNODE *head,int y){
      DNODE *p,*q=head->next;
      p=(DNODE *)malloc(sizeof(DNODE));
      p->info=y;
      p->next=head;
      p->prev=(head->prev);
      if(head->info==0){
         head=insertbeg(head,y);
         return head;
      }
      while(q->next!=head)
            q=q->next;
      q->next=p;
      head->prev=p;
      ++head->info;
      return head;
}
DNODE* insertafter(DNODE *head,int x,int y){
	    int i;
        DNODE *p,*q=head->next;
        p=(DNODE *)malloc(sizeof(DNODE));
        p->info=y;
        if(head->info==0){
       	  printf("%d doesn't exist in the linked list\n");
       	  return head;
	    }
	    while(q!=head && q->info!=x)
	        q=q->next;
	    if(q==head){
	      printf("%d doesn't exist in the linked list\n");
	      return head;
		}
		if(q->next==head){
			head=insertend(head,y);
			return head;
		}
		p->prev=q;
	    p->next=q->next;
	    (q->next)->prev=p;
	    q->next=p;
	    ++head->info;
	    return head;
}
DNODE* insertbefore(DNODE *head,int x,int y){
      DNODE *p,*q=head->next;
      p=(DNODE *)malloc(sizeof(DNODE));
      p->info=y;
      if(head->info==0){
         printf("%d doesn't exist in the linked list\n",x);
           return head;
      }
      if(q->info==x){
      	head=insertbeg(head,y);
      	return head;
	  }
      while(q!=head && (q->next)->info!=x)
           q=q->next;
      if(q==head){
          printf("%d doesn't exist in the linked list\n",x);
           return head;
      }
      p->prev=q;
      p->next=q->next;
      q->next=p;
      (q->next)->prev=p;
      ++head->info;
      return head;
}
DNODE* deletestart(DNODE *head){
     DNODE *p=head->next,*q=head;
     if(head->info==0){
        printf("List is empty\n");
        return head;
     }
     if(head->info==1){
         head->next=p->next;
         --head->info;
         free(p);
         return head;
     }
     head->next=p->next;
     p->prev=head;
     --head->info;
     free(p);
     return head;
}
DNODE* deleteend(DNODE *head){
     DNODE* p=head;
     if(head->info==0){
        printf("List is empty\n");
        return head;
     }
     if(head->info==1){
        head=deletestart(head);
        return head;
     }
     while((p->next)->next!=head)
          p=p->next;
     free(p->next);
     --head->info;
     p->next=head;
     head->prev=p;
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
      while(p->next!=head && (p->next)->info!=x) 
            p=p->next;
      if(p->next==head){
      	 if(p->info==x){
		    head=deleteend(head);
		    return head;
		 }
      	 else{
         printf("%d is not present in the linked list\n",x);
         return head;
         } 
      }
      q=p->next;
      p->next=q->next;
      --head->info;
      free(q);
      return head;
}
void display(DNODE *head){
     DNODE *p;
     if(head->info==0){
     	printf("List is empty");
	 }
     else{
     for(p=head->next;p!=head;p=p->next)
        printf("%d\t",p->info);
     }
     printf("\n");
}
main(){
     DNODE *head=(DNODE *)malloc(sizeof(DNODE));
     head->info=0;
     head->prev=head;
     head->next=head;
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



