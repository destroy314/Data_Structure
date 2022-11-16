#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int width,height;
    int number;//平面的编号
    struct NODE *next;
    struct NODE *previous;
}node;
long long int ans[100000];

int main(){
    int N;
    scanf("%d",&N);
    node *head;
    head=(node*)malloc(sizeof(node));
    head->height=1000001;
    node *tail=head,*start=head;
    for(int i=0;i<N;i++){
        node *t;
        t=(node*)malloc(sizeof(node));
        tail->next=t;
        scanf("%d %d",&t->width,&t->height);
        t->number=i;
        t->previous=tail;
        if(t->height<start->height){start=t;}
        tail=t;
    }
    node *t;
    t=(node*)malloc(sizeof(node));
    t->height=1000001;
    t->previous=tail;
    tail->next=t;
    long long int time=0;
    node *increase=start;//水量增加的平面
    if(N==1){//goto last;
	            ans[increase->number]=time+increase->width;}
    while(N!=1){
        while(increase->height>increase->previous->height){
            increase=increase->previous;
        }
        while(increase->height>increase->next->height){
            increase=increase->next;
        }
        
		    node *target=increase;//水量增加的目标平面
		
        if(target->previous->height>target->next->height){
            target=target->next;
        }
        else{
            target=target->previous;
        }
        time+=increase->width;
        ans[increase->number]=time;
        time+=increase->width*(target->height-increase->height-1);
        increase->previous->next=increase->next;
        increase->next->previous=increase->previous;
        target->width+=increase->width;
        increase=target;
        if(increase->previous->height==increase->next->height){
            //last:;
            ans[increase->number]=time+increase->width;
            break;
        }
    }
    for(int i=0;i<N;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}

/*
wall <-> plane <-> ... <-> plane <-> wall
h=MAX     h=                h=       h=MAX
          l=                l=
        index=0          index=N-1
*/
