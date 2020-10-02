#include<stdio.h>
#include<stdlib.h>
struct node{
   int info;
   struct node *next;
};
typedef struct node NODE;
NODE* insertbeg(NODE *head,int y){
      NODE *p;
      p=(NODE *)malloc(sizeof(NODE));
      p->info=y;
      ++head->info;
      p->next=head->next;
      head->next=p;
      return head;
}
NODE* insertend(NODE *head,int y){
      NODE *p,*q=head->next;
      p=(NODE *)malloc(sizeof(NODE));
      p->info=y;
      p->next=head;
      if(head->info==0){
         head=insertbeg(head,y);
         return head;
      }
      while(q->next!=head)
            q=q->next;
      q->next=p;
      ++head->info;
      return head;
}
NODE* insertafter(NODE *head,int x,int y){
	    int i;
        NODE *p,*q=head->next;
        p=(NODE *)malloc(sizeof(NODE));
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
	    p->next=q->next;
	    q->next=p;
	    ++head->info;
	    return head;
}
NODE* insertbefore(NODE *head,int x,int y){
      NODE *p,*q=head;
      p=(NODE *)malloc(sizeof(NODE));
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
      p->next=q->next;
      q->next=p;
      ++head->info;
      return head;
}
NODE* deletestart(NODE *head){
     NODE *p=head->next,*q=head;
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
     --head->info;
     free(p);
     return head;
}
NODE* deleteend(NODE *head){
     NODE* p=head;
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
     return head;
}
NODE* deletex(NODE *head,int x){
      NODE *p=head->next,*q;
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
void display(NODE *head){
     NODE *p;
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
     NODE *head=(NODE *)malloc(sizeof(NODE));
     head->info=0;
     head->next=head;
     int choice,x,y;
     while(1){
        printf("Enter 1 to Insert an element at the start of the header based circular linked list.\n");
        printf("Enter 2 to Insert an element at the end of the header based circular linked list.\n");
        printf("Enter 3 to Insert an element before an existing element whose information is x in a header based circular linked list.\n");
        printf("Enter 4 to Insert an element after an existing element whose information is x in a header based circular linked list.\n");
        printf("Enter 5 to Delete the first element of the header based circular linked list.\n");
        printf("Enter 6 to Delete the last element of the header based circular linked list.\n");
        printf("Enter 7 to Delete the element whose information is x from a header based circular linked list.\n");
        printf("Enter 8 to Display the contents of the header based circular linked list.\n");
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

