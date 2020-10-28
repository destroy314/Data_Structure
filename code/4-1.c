#include <stdio.h>
#include <stdlib.h>
typedef struct NODE{
    char i;
    struct NODE *son;
    struct NODE *brother;
}node;
node *strAck[1000];
int poiNter=0;
int dEgrEE[100]={0};

void treein(){
    node *t;
    t=(node*)malloc(sizeof(node));
    t->i=getchar();
    if(t->i==')'){
        printf("Degree of tree: 0\n");
        printf("Number of nodes of degree 0: 0\n");
        exit(0);
    }
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
    dEgrEE[poiNter-NUmofnEW]++;
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
void treeout(node *s,int deep){
    while(s!=NULL){
        for(int i=0;i<deep;i++){
            printf("    ");
        }
        printf("%c\n",s->i);
        if(s->son!=NULL){
            treeout(s->son,deep+1);
        }
        s=s->brother;
    }
}
int main(){
    getchar();
    treein();
    treeout(strAck[0],0);
    int i=99;
    while(dEgrEE[i]==0){
        i--;
    }
    printf("Degree of tree: %d\n",i);
    int j=0;
    while(j<=i){
        printf("Number of nodes of degree %d: %d\n",j,dEgrEE[j]);
        j++;
    }
    return 0;
}