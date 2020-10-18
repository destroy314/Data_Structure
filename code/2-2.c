#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int w,h;
    int index;//平面的编号
    struct NODE *next;
    struct NODE *previous;
}node;
long long int ans[100000];

int main(){
    int N;
    scanf("%d",&N);
    node *head;
    head=(node*)malloc(sizeof(node));
    head->h=1000001;
    node *tail=head,*start=head;
    for(int i=0;i<N;i++){
        node *t;
        t=(node*)malloc(sizeof(node));
        tail->next=t;
        scanf("%d %d",&t->w,&t->h);
        t->index=i;
        t->previous=tail;
        if(t->h<start->h){start=t;}
        tail=t;
    }
    node *t;
    t=(node*)malloc(sizeof(node));
    t->h=1000001;
    t->previous=tail;
    tail->next=t;
    long long int time=0;
    node *increase=start;//水量增加的平面
    if(N==1){goto last;}
    while(1){
        while(increase->h>increase->previous->h){
            increase=increase->previous;
        }
        while(increase->h>increase->next->h){
            increase=increase->next;
        }
        node *target=increase;//水量增加的目标平面
        if(target->previous->h>target->next->h){
            target=target->next;
        }
        else{
            target=target->previous;
        }
        time+=increase->w;
        ans[increase->index]=time;
        time+=increase->w*(target->h-increase->h-1);
        increase->previous->next=increase->next;
        increase->next->previous=increase->previous;
        target->w+=increase->w;
        increase=target;
        if(increase->previous->h==increase->next->h){
            last:;
            ans[increase->index]=time+increase->w;
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