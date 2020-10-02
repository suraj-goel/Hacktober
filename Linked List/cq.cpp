#include<stdio.h>
int size=3;
struct queue{
	int q[3];
	int front,rear;
	int count;
};
typedef struct queue Q;
void enq(Q *s){
	
	if(s->count==size)
		return ;
	s->rear++;
	s->count++;
	s->rear=s->rear%size;
	int x;
	printf("enetr num");
	scanf("%d",&x);
	s->q[s->rear]=x;
}
void deq(Q *s){
	if(s->count==0)
		{
			printf("und");
			return ;
		}
		s->count--;
	s->front++;
	s->front=s->front%size;
	printf("de");
}
void display(Q *s){
	int i=s->front;
	int x=s->count;
	while(x--){
		printf("%d ", s->q[i]);
		i++;
	}
}

main()
{
	Q s;s.count=0;
	s.front=0;s.rear=-1;
	int t=1;
	while(t)
	{
		
		switch(t){
			case 1:enq(&s);
			break;
			case 2:deq(&s);
			break;
			case 3:display(&s);
			break;	
		}
		scanf("%d",&t);
	}
}
