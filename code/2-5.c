/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		  sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int ans[100000]={0};
void solution2(NODE *P,NODE *Q,NODE *r){
    NODE *p=P->next;
    while(p!=NULL){
        NODE *q=Q->next;
        while(q!=NULL){
            ans[p->exp+q->exp]+=p->coef*q->coef;
            q=q->next;
        }
        p=p->next;
    }
    NODE *tail=r;
    for(int i=0;i<100000;i++){
        if(ans[i]!=0){
            NODE *newp=(NODE*)malloc(sizeof(NODE));
            newp->coef=ans[i];
            newp->exp=i;
            newp->next=NULL;
            tail->next=newp;
            tail=newp;
        }
    }
        if(r->next==NULL){
        NODE *newp=(NODE*)malloc(sizeof(NODE));
        newp->coef=0;
        newp->exp=0;
        newp->next=NULL;
        r->next=newp;
    }
    return;
}

void multiplication(NODE *P,NODE *Q,NODE *r){
    int lenp=0,lenq=0;
    NODE *p=P->next;
    NODE *q=Q->next;
    while(p!=NULL){
        p=p->next;
        lenp++;
    }
    while(q!=NULL){
        q=q->next;
        lenq++;
    }
    if(lenp*lenq>100){//“自动感知数据特征，并灵活地应用算法策略”
        solution2(P,Q,r);
        return;
    }

    p=P->next;
    while(p!=NULL){
        q=Q->next;
        while(q!=NULL){
            NODE *t=r,*u=r;
            t=t->next;
            int ae=p->exp+q->exp;
            while(t!=NULL&&ae>t->exp){
                t=t->next;
                u=u->next;
            }
            NODE *newp=(NODE*)malloc(sizeof(NODE));
            if(t!=NULL&&t->exp==ae){
                t->coef+=p->coef*q->coef;
                if(t->coef==0){
                    u->next=t->next;
                }
                goto end;
            }
            if(p->coef*q->coef==0){goto end;}
            newp->coef=p->coef*q->coef;
            newp->exp=p->exp+q->exp;
            newp->next=t;
            u->next=newp;
            end:;
            q=q->next;
        }
        p=p->next;
    }
    if(r->next==NULL){
        NODE *newp=(NODE*)malloc(sizeof(NODE));
        newp->coef=0;
        newp->exp=0;
        newp->next=NULL;
        r->next=newp;
    }
    return;
}