#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int s;
    struct NODE *next;
    struct NODE *previous;
}node;

int main(){
    int n,k,m;
    scanf("%d,%d,%d",&n,&k,&m);
    if(n==0||k==0||m==0){
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
        t->previous=tail;
        if(i==k){starter=t;}
        tail=t;
    }
    tail->next=head;
    head->previous=tail;
    node *np=starter,*pp=starter;
    node *temp;
    while(1){
        for(int i=0;i<m-1;i++){
            np=np->next;
            pp=pp->previous;
        }
        if(np==pp){
            temp=np;
            np->previous->next=np->next;
            np->next->previous=np->previous;
            printf("%d,",np->s);
            np=np->next;
            pp=pp->previous;
            if(np==temp){
                printf("\n");
                return 0;
            }
        }
        else{
            temp=pp;
            np->previous->next=np->next;
            np->next->previous=np->previous;
            printf("%d-",np->s);
            np=np->next;
            if(np==pp){np=np->next;}
            pp->next->previous=pp->previous;
            pp->previous->next=pp->next;
            printf("%d,",pp->s);
            pp=pp->previous;
            if(pp==temp){
                printf("\n");
                return 0;
            }
        }
    }
}