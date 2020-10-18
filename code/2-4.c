#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int coe;//系数
    int exp;//指数
    struct NODE *next;
}node;

node *AddPolyn(node* P1,node* P2){
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *tail=head;
    node *p=P1->next;
    node *q=P2->next;
    while(p!=NULL){
        if(p->exp<q->exp){
            node *t=(node*)malloc(sizeof(node));
            t->coe=p->coe;
            t->exp=p->exp;
            t->next=NULL;
            tail->next=t;
            tail=t;
            p=p->next;
        }
        else if(p->exp==q->exp){
            if(p->coe+q->coe==0){
                p=p->next;
                q=q->next;
                goto end;
            }
            node *t=(node*)malloc(sizeof(node));
            t->coe=p->coe+q->coe;
            t->exp=p->exp;
            t->next=NULL;
            tail->next=t;
            tail=t;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp){
            node *t=(node*)malloc(sizeof(node));
            t->coe=q->coe;
            t->exp=q->exp;
            t->next=NULL;
            tail->next=t;
            tail=t;
            q=q->next;
        }
        end:;
    }
    while(q!=NULL){
        node *t=(node*)malloc(sizeof(node));
        t->coe=q->coe;
        t->exp=q->exp;
        t->next=NULL;
        tail->next=t;
        tail=t;
        q=q->next;
    }
    return head;
}

void PrintPolyn(node *p){
    p=p->next;
    if(p==NULL){
        printf("<0,0>\n");
        return;
    }
    int n=0;
    while(p!=NULL){
        if(n!=0){printf(",");}
        printf("<%d,%d>",p->coe,p->exp);
        p=p->next;
        n++;
    }
    printf("\n");
    return;
}

int main(){
    int fun;
    scanf("%d",&fun);
    if(fun==0){return 0;}
    node *Poly[5];
    for(int i=0;i<3;i++){
        node *P=(node*)malloc(sizeof(node));
        node *tail=P;
        int item;
        scanf("%d",&item);
        for(int j=0;j<item;j++){
            node *t=(node*)malloc(sizeof(node));
            scanf("%d %d",&t->coe,&t->exp);
            t->next=NULL;
            tail->next=t;
            tail=t;
        }
        Poly[i]=P;
    }
    Poly[3]=AddPolyn(Poly[0],Poly[1]);
    Poly[4]=AddPolyn(Poly[3],Poly[2]);
    for(int i=0;i<5;i++){
        PrintPolyn(Poly[i]);
    }
    return 0;
}