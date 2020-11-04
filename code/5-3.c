#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    char c;
    int high;
    struct NODE *lson;
    struct NODE *rson;
}node;

node *newnode(){
    node *t;
    t=(node*)malloc(sizeof(node));
    t->lson=NULL;
    t->rson=NULL;
    return t;
}

int max(int a,int b){
    return a>b?a:b;
}

int min(int a,int b){
    return a<b?a:b;
}

int hight(node *p){
    if(p==NULL){return -1;}
    return p->high;
}

/*向左单旋转*/
node *sigrotL(node *k2){
    node *k1;
    k1=k2->lson;
    k2->lson=k1->rson;
    k1->rson=k2;
    k2->high=max(hight(k2->lson),hight(k2->rson))+1;
    k1->high=max(hight(k1->lson),k2->high)+1;
    return k1;
}

/*向右单旋转*/
node *sigrotR(node *k2){
    node *k1;
    k1=k2->rson;
    k2->rson=k1->lson;
    k1->lson=k2;
    k2->high=max(hight(k2->lson),hight(k2->rson))+1;
    k1->high=max(hight(k1->rson),k2->high)+1;
    return k1;
}

/*向左双旋转*/
node *dubrotL(node *k3){
    k3->lson=sigrotR(k3->lson);
    return sigrotL(k3);
}

/*向右双旋转*/
node *dubrotR(node *k3){
    k3->rson=sigrotL(k3->rson);
    return sigrotR(k3);
}

/*向树p插入x*/
node *insert(char x,node *p){
    if(p==NULL){
        p=newnode();
        p->c=x;
        p->high=0;
    }
    else if(x<p->c){
        p->lson=insert(x,p->lson);
        if(hight(p->lson)-hight(p->rson)==2){
            if(x<p->lson->c){
                p=sigrotL(p);
            }
            else{
                p=dubrotL(p);
            }
        }
    }
    else if(x>p->c){
        p->rson=insert(x,p->rson);
        if(hight(p->rson)-hight(p->lson)==2){
            if(x>p->rson->c){
                p=sigrotR(p);
            }
            else{
                p=dubrotR(p);
            }
        }
    }
    p->high=max(hight(p->lson),hight(p->rson))+1;
    return p;
}

void out(node *root,char *f){
    char *a=f;
    while(*a!='\0'){
        switch(*a){
        case 'f':
            printf("%c",root->c);
            break;
        case 'l':
            if(root->lson!=NULL){
                out(root->lson,f);
            }
            break;
        case 'r':
            if(root->rson!=NULL){
                out(root->rson,f);
            }
            break;
        }
        a++;
    }
}

void tree(node *root,int deep){
    if(root->rson!=NULL){
        tree(root->rson,deep+1);
    }
    for(int i=0;i<deep*4;i++){
        printf(" ");
    }
    printf("%c\n",root->c);
    if(root->lson!=NULL){
        tree(root->lson,deep+1);
    }
}

int main(){
    node *root=NULL;
    while (1){
        char x;
        scanf("%c",&x);
        if(x=='\n'){break;}
        root=insert(x,root);
    }
    printf("Preorder: ");
    out(root,(char*)"flr");
    printf("\nInorder: ");
    out(root,(char*)"lfr");
    printf("\nPostorder: ");
    out(root,(char*)"lrf");
    printf("\nTree:\n");
    tree(root,0);
    return 0;
}