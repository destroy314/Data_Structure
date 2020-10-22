#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct NODE{
    int i,n;//委托序号，数量
    float pri;//价格
    NODE *next;
}node;

int main(){
    node *Slist[10000];
    node *Blist[10000];
    for(int i=0;i<10000;i++){
        node *Shead=(node*)malloc(sizeof(node));
        Shead->next=NULL;
        node *Bhead=(node*)malloc(sizeof(node));
        Bhead->next=NULL;
        Slist[i]=Shead;
        Blist[i]=Bhead;
    }
    int entrust[100000]={0};//每个委托的股票编码
    int newindex=1;
    
    while(1){
        int code,number;
        float price;
        char intent;
        int mode;
        int index;
        node *p,*q;
        cin>>mode;
        switch(mode){
        case 0:
            return 0;
        case 1:
            cin>>code>>price>>number>>intent;
            index=newindex;
            newindex++;
            printf("orderid: %04d\n",index);
            if(intent=='s'){
                p=Blist[code]->next;
                if(p==NULL){goto adding1;}
                while(p!=NULL&&p->pri>=price){
                    int deal=number<p->n?number:p->n;
                    float dealpri=(price+p->pri)/2;
                    number-=deal;
                    p->n-=deal;
                    printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n",dealpri,deal,index,p->i);
                    if(p->n==0){
                        node *temp=p;
                        Blist[code]->next=p->next;
                        p=p->next;
                        free(temp);
                    }
                    if(number==0){break;}
                }
                adding1:;
                if(number!=0){
                    p=Slist[code]->next;
                    q=Slist[code];
                    while(p!=NULL&&p->pri<=price){
                        p=p->next;
                        q=q->next;
                    }
                    node *t;
                    t=(node*)malloc(sizeof(node));
                    t->i=index;
                    t->pri=price;
                    t->n=number;
                    t->next=p;
                    q->next=t;
                    entrust[index]=code;
                }
            }
            else{
                p=Slist[code]->next;
                if(p==NULL){goto adding2;}
                while(p!=NULL&&p->pri<=price){
                    int deal=number<p->n?number:p->n;
                    float dealpri=(price+p->pri)/2;
                    number-=deal;
                    p->n-=deal;
                    printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n",dealpri,deal,index,p->i);
                    if(p->n==0){
                        node *temp=p;
                        Slist[code]->next=p->next;
                        p=p->next;
                        free(temp);
                    }
                    if(number==0){break;}
                }
                adding2:;
                if(number!=0){
                    p=Blist[code]->next;
                    q=Blist[code];
                    while(p!=NULL&&p->pri>=price){
                        p=p->next;
                        q=q->next;
                    }
                    node *t;
                    t=(node*)malloc(sizeof(node));
                    t->i=index;
                    t->pri=price;
                    t->n=number;
                    t->next=p;
                    q->next=t;
                    entrust[index]=code;
                }
            }
            break;
        case 2:
            cin>>code;
            cout<<"buy orders:"<<endl;
            p=Blist[code]->next;
            while(p!=NULL){
                printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n",p->i,code,p->pri,p->n);
                p=p->next;
            }
            cout<<"sell orders:"<<endl;
            p=Slist[code]->next;
            while(p!=NULL){
                printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n",p->i,code,p->pri,p->n);
                p=p->next;
            }
            break;
        case 3:
            cin>>index;
            code=entrust[index];
            p=Blist[code]->next;
            q=Blist[code];
            while(p!=NULL){
                if(p->i==index){
                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: b\n",p->i,code,p->pri,p->n);
                    q->next=p->next;
                    free(p);
                    goto end;
                }
                p=p->next;
                q=q->next;
            }
            p=Slist[code]->next;
            q=Slist[code];
            while(p!=NULL){
                if(p->i==index){
                    printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: s\n",p->i,code,p->pri,p->n);
                    q->next=p->next;
                    free(p);
                    goto end;
                }
                p=p->next;
                q=q->next;
            }
            cout<<"not found"<<endl;
        }
        end:;
    }
}

/*
NULL
↑pri=10
↑pri=9
↑pri=8<-Shead

↓pri=7<-Bhead
↓pri=6
↓pri=5
NULL
*/