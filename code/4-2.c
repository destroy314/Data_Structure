#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    char i;
    struct NODE *lson;
    struct NODE *rson;
}node;
node *treeeee[1000]={NULL};
int leaf=0;

void readtree(){
    int p=0,q=0;
    node *newtreee[1000]={NULL};
    while(treeeee[p]!=NULL){
        char c=getchar();
        if(c=='\n'){return;}
        node *t;
        t=(node*)malloc(sizeof(node));
        if(c!='#'){t->i=c;}
        else{t->i='\0';}
        t->lson=NULL;
        t->rson=NULL;
        treeeee[p]->lson=t;
        newtreee[q++]=t;
        c=getchar();
        if(c=='\n'){return;}
        t=(node*)malloc(sizeof(node));
        if(c!='#'){t->i=c;}
        else{t->i='\0';}
        t->lson=NULL;
        t->rson=NULL;
        treeeee[p]->rson=t;
        newtreee[q++]=t;
        p++;
    }
    q=0;
    while(newtreee[q]!=NULL){
        treeeee[q]=newtreee[q];
        q++;
    }
    treeeee[q]=NULL;
    readtree();
}

node *start(){
    char c=getchar();
    node *t;
    t=(node*)malloc(sizeof(node));
    t->i=c;
    t->lson=NULL;
    t->rson=NULL;
    treeeee[0]=t;
    if(t->i!='#'){
        readtree();
    }
    else{
        t->i='\0';
        leaf=-1;
    }
    return t;
}

void cal(node *root){
    if(root->i=='\0'){
        return;
    }
    if(root->lson==root->rson){
        leaf++;
        return;
    }
    else if(root->rson==NULL&&root->lson->i=='\0'){
        leaf++;
        return;
    }
    else if(root->rson!=NULL&&root->lson->i==root->rson->i){
        leaf++;
        return;
    }
    if(root->lson!=NULL){
        cal(root->lson);
    }
    if(root->rson!=NULL){
        cal(root->rson);
    }
    return;
}

void printtree(node *root,int deep){
    if(root->i=='\0'){return;}
    for(int i=0;i<deep;i++){
        printf("    ");
    }
    printf("%c\n",root->i);
    if(root->lson!=NULL){
        printtree(root->lson,deep+1);
    }
    if(root->rson!=NULL){
        printtree(root->rson,deep+1);
    }
    return;
}

void out(node *root,char t[]){
    if(root->i=='\0'){return;}
    int i=0;
    while(i<3){
        switch(t[i]){
        case 'f':
            if(root->i!='\0'){printf("%c",root->i);}
            break;
        case 'l':
            if(root->lson!=NULL){
                out(root->lson,t);
            }
            break;
        case 'r':
            if(root->rson!=NULL){
                out(root->rson,t);
            }
            break;
        }
        i++;
    }
    return;
}

void swap(node *root){
    if(root->lson==root->rson){return;}
    node *temp=root->lson;
    root->lson=root->rson;
    root->rson=temp;
    if(root->lson!=NULL){
        swap(root->lson);
    }
    if(root->rson!=NULL){
        swap(root->rson);
    }
    return;
}

void output(node *t){
    printtree(t,0);
    printf("pre_sequence  : ");
    out(t,(char*)"flr");
    printf("\nin_sequence   : ");
    out(t,(char*)"lfr");
    printf("\npost_sequence : ");
    out(t,(char*)"lrf");
    printf("\n");
}

int main(){
    node *t=start();
    printf("BiTree\n");
    output(t);
    cal(t);
    printf("Number of leaf: %d\n",leaf);
    swap(t);
    printf("BiTree swapped\n");
    output(t);
    return 0;
}