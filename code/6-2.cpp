#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct NODE{
    int fre;
    struct NODE *l;
    struct NODE *r;
}node;
int sym[10000];
vector<node*> leaf;
int WPL=0;

node *newnode(){
    node *t=(node*)malloc(sizeof(node));
    t->l=NULL;
    t->r=NULL;
    return t;
}

void cal(node *t,int length){
    if(t->l==NULL&&t->r==NULL){
        WPL+=t->fre*length;
        return;
    }
    if(t->l!=NULL){
        cal(t->l,length+1);
    }
    if(t->r!=NULL){
        cal(t->r,length+1);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&sym[i]);
    }
    sort(sym,sym+n);
    for(int i=0;i<n;i++){
        node *t=newnode();
        t->fre=sym[i];
        leaf.push_back(t);
    }
    while(leaf.size()>1){
        node *p=leaf[0];
        leaf.erase(leaf.begin());
        node *q=leaf[0];
        leaf.erase(leaf.begin());
        node *t=newnode();
        t->fre=p->fre+q->fre;
        t->l=p;
        t->r=q;
        int i=0;
        while(i<=leaf.size()&&(leaf[i]->fre<=t->fre)){i++;}
        if(i>leaf.size()){leaf.push_back(t);}
        else{leaf.insert(leaf.begin()+i,t);}
    }
    cal(leaf[0],0);
    printf("WPL=%d\n",WPL);
    return 0;
}