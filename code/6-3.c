#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    char i;
    int stw;//step to win
    int height;
    struct NODE *son;
    struct NODE *brother;
}node;
node *strAck[1000];
int poiNter=0;

void treein(){
    node *t;
    t=(node*)malloc(sizeof(node));
    t->i=getchar();
    t->brother=NULL;
    t->son=NULL;
    strAck[poiNter]=t;
    int NUmofnEW=poiNter;
    poiNter++;
    char n=getchar();
    while(n!=')'){
        getchar();
        treein();
        n=getchar();
    }
    poiNter--;
    while(poiNter-1>NUmofnEW){
        strAck[poiNter-1]->brother=strAck[poiNter];
        poiNter--;
    }
    if(poiNter>NUmofnEW){
        strAck[poiNter-1]->son=strAck[poiNter];
    }
    else{
        poiNter++;
    }
    return;
}

void number(node *root){
    if(root->son==NULL){
        root->stw=0;
        root->height=0;
    }
    else{
        number(root->son);
        int min=10000;
        int max=0;
        node *t=root->son;
        while(t!=NULL){
            min=t->stw<min?t->stw:min;
            max=t->height>max?t->height:max;
            t=t->brother;
        }
        root->stw=min+1;
        root->height=max+1;
    }
    if(root->brother!=NULL){
        number(root->brother);
    }
    return;
}

void out(node *root){
    printf("%c\n",root->i);
    if(root->son!=NULL){
        out(root->son);
    }
    if(root->brother!=NULL){
        out(root->brother);
    }
    return;
}

int main(){
    getchar();
    treein();
    number(strAck[0]);
    out(strAck[0]);
    while(1){
        node *p=strAck[0];
        printf("Who play first(0: computer; 1: player )?\n");
        int opt;
        scanf("%d",&opt);
        getchar();
        if(opt==1){
            goto player;
        }
        while(1){
            if(p->stw==0){
                printf("Congratulate, you win.\nContinue(y/n)?\n");
                char con;
                scanf("%c",&con);
                getchar();
                if(con=='y'){
                    break;
                }
                else{
                    return 0;
                }
            }
            node *sons[100];
            node *l=p->son;
            node *maxh=l;
            node *minh;
            int i=0;
            while(l!=NULL){
                if(l->stw%2==0){
                    sons[i]=l;
                    i++;
                }
                if(l->height>maxh->height){
                    maxh=l;
                }
                l=l->brother;
            }
            switch(i){//电脑走棋
            case 1://存在可以确保取胜的一个孩子结点
                p=sons[0];
                break;
            case 0://不存在可以确保取胜的一个孩子结点
                p=maxh;
                break;
            default://存在多个可以确保取胜的孩子结点
                minh=sons[0];
                for(int j=0;j<i;j++){
                    if(sons[j]->height<minh->height){
                        minh=sons[j];
                    }
                }
                p=minh;
                break;
            }
            printf("computer: %c\n",p->i);
            if(p->stw==0){
                printf("Sorry, you lost.\nContinue(y/n)?\n");
                char con;
                scanf("%c",&con);
                getchar();
                if(con=='y'){
                    break;
                }
                else{
                    return 0;
                }
            }
            player:;//玩家走棋
            printf("player:\n");
            char n;
            scanf("%c",&n);
            getchar();
            node *next=p->son;
            while(1){
                if(next->i==n){
                    p=next;
                    break;
                }
                next=next->brother;
                if(next==NULL){
                    printf("illegal move.\n");
                    goto player;
                }
            }
        }
    }
    return 0;
}