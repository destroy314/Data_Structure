/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE * );  
void change( int, int, NODE * );  
  
void output( NODE * head )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m;  
    NODE * head;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

#include <math.h>
int check(NODE *a,NODE *b){
    for(int i=0;i<5;i++){
        ;
    }
}
void change(int n,int m,NODE *head){
    NODE *ex=(NODE*)malloc(sizeof(NODE));
    ex->data=-1;
    ex->next=NULL;
    NODE *tail=head,*extail=ex;
    int mod=n%m;
    int res;
    while(1){
        NODE *p=ex,*q=head;
        res=(mod*10)/m;
        mod=(mod*10)%m;
        while(p->next!=NULL){
            if((p->data==mod&&q->data==res)||(p->data==mod&&res==0)){
                if(mod==0){
                    tail->next=NULL;
                    return;
                }
                tail->next=q;
                return;
            }
            p=p->next;
            q=q->next;
        }
        if((p->data==mod&&q->data==res)||(p->data==mod&&res==0)){
            if(mod==0){
                tail->next=NULL;
                return;
            }
            tail->next=q;
            return;
        }
        NODE *t=(NODE*)malloc(sizeof(NODE));
        tail->next=t;
        t->data=res;
        t->next=NULL;
        tail=t;
        NODE *e=(NODE*)malloc(sizeof(NODE));
        extail->next=e;
        e->data=mod;
        e->next=NULL;
        extail=e;
    }
}

//https://blog.csdn.net/qq742762377/article/details/80572811?tdsourcetag=s_pctim_aiomsg
//做两个链表分别存储结果和余数，每算出一个新的余数就向前查找；
//如果找到相同的余数，就把结果链表的尾节点连到对应的结果节点上
//大部分都遵循以上的规律，但7 18是一个有趣的反例，因此同时检查商