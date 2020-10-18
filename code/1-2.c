#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE{
    int number;
    char name[10];
    struct NODE *next;
}node;

int main(){
    int l1,l2;
    scanf("%d",&l1);
    node *first=(node*)malloc(sizeof(node));
    node *head=first,*tail=first;
    scanf("%d %s",&head->number,&head->name);
    for(int i=1;i<l1;i++){
        node *t=(node*)malloc(sizeof(node));
        scanf("%d %s",&t->number,&t->name);
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
    scanf("%d",&l2);
    if(l2==0){
        printf("the LIST2 is NULL.\n");
        return 0;
    }
    int notin=0;
    for(int i=0;i<l2;i++){
        int num,found=0;
        char nam[10];
        scanf("%d %s",&num,&nam);
        node *p=head;
        while(p->next!=NULL){
            if(p->number==num&&strcmp(p->name,nam)==0){
                found=1;
                break;
            }
            p=p->next;
        }
        if(p->number==num&&strcmp(p->name,nam)==0){
            found=1;
        }
        if(found==0){
            notin++;
            printf("%d %s is not in LIST1.\n",num,nam);
        }
    }
    if(notin==0){
        printf("the records of LIST2 are all in the LIST1.\n");
    }
    return 0;
}