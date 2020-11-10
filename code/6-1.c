#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE{
    struct NODE *one;
    struct NODE *zero;
}node;
char code[500000];

node *newnode(){
    node *t=(node*)malloc(sizeof(node));
    t->one=NULL;
    t->zero=NULL;
    return t;
}

int main(){
    int n;
    scanf("%d",&n);
    node *root=newnode();
    for(int i=0;i<n;i++){
        scanf("%s",&code[0]);
        int added=0;
        int len=strlen(code);
        node *p=root;
        for(int pos=0;pos<len;pos++){
            if(code[pos]=='1'){
                if(p->one==NULL){
                    node *t=newnode();
                    p->one=t;
                    p=p->one;
                    added++;
                }
                else{
                    p=p->one;
                    if((pos<len-1)&&p->one==NULL&&p->zero==NULL){goto end;}
                    //如果某个编码在叶子上添加了节点，前面某个编码是它的前缀
                }
            }
            else if(code[pos]=='0'){
                if(p->zero==NULL){
                    node *t=newnode();
                    p->zero=t;
                    p=p->zero;
                    added++;
                }
                else{
                    p=p->zero;
                    if((pos<len-1)&&p->one==NULL&&p->zero==NULL){goto end;}
                }
            }
        }
        if(added==0){//如果一个编码沿着之前编码的路径走且没添加新节点，这个编码是前面输入的某个编码的前缀
            end:;
            printf("%s\n",code);
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}