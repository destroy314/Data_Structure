#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int s;
    struct NODE *next;
}node;
int row=1;
void output(int i){
    if(row!=1){printf(" ");}
    printf("%d",i);
    if(row==10){
        printf("\n");
        row=1;
        return;
    }
    row++;
    return;
}
int main(){
    int n,k,m;
    scanf("%d,%d,%d",&n,&k,&m);
    if(n<1||k<1||m<1){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    if(k>n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    node *head;
    head=(node*)malloc(sizeof(node));
    head->s=1;
    node *tail=head,*starter=head;
    for(int i=2;i<=n;i++){
        node *t;
        t=(node*)malloc(sizeof(node));
        tail->next=t;
        t->s=i;
        if(i==k){starter=t;}
        tail=t;
    }
    tail->next=head;
    node *p=starter,*q=starter;
    while(q->next!=p){
        q=q->next;
    }
    int count=0;
    while(1){
        count++;
        if(count==m){
            output(p->s);
            if(p==q){
                if(row!=1){printf("\n");}
                return 0;
            }
            q->next=p->next;
            p=q->next;
            count=0;
            continue;
        }
        p=p->next;
        q=q->next;
    }
}