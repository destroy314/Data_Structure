#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    int i;
    struct NODE *lson;
    struct NODE *rson;
}node;

node *find(int n,node *root){
    int r=root->i;
    if(n<r){
        if(root->lson==NULL){
            return root;
        }
        else{
            return find(n,root->lson);
        }
    }
    if(root->rson==NULL){
        return root;
    }
    else{
        return find(n,root->rson);
    }
}

void out(node *root,int deep){
    if(root->lson!=NULL){
        out(root->lson,deep+1);
    }
    for(int i=0;i<deep*4;i++){
        printf(" ");
    }
    printf("%d\n",root->i);
    if(root->rson!=NULL){
        out(root->rson,deep+1);
    }
}

void mid(node *root){
    if(root->lson!=NULL){
        mid(root->lson);
    }
    printf(" %d",root->i);
    if(root->rson!=NULL){
        mid(root->rson);
    }
}

int main(){
    int in;
    scanf("%d",&in);
    node *root;
    root=(node*)malloc(sizeof(node));
    root->i=in;
    root->lson=NULL;
    root->rson=NULL;
    while(1){
        scanf("%d",&in);
        if(in==0){break;}
        node *t;
        t=(node*)malloc(sizeof(node));
        t->i=in;
        t->lson=NULL;
        t->rson=NULL;
        node *res;
        res=find(in,root);
        int n=res->i;
        if(in<n){res->lson=t;}
        else{res->rson=t;}
    }
    out(root,0);
    printf("\n");
    mid(root);
    printf("\n");
    return 0;
}