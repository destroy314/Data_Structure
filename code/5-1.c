#include <stdio.h>
#include <math.h>
int n,m;
int num=0;

/*计算n个节点的树在深度m的最多节点个数*/
void cal(int n,int m){
    if(m+1>n){return;}//出锅
    if(m<27&&n>=pow(2,m+1)-1){//去整
        num+=(int)pow(2,m);
        return;
    }
    if((n>=27)&&(m>=27)){//粗略去尾
        n-=(m-27);
        m=27;
    }
    while(n<=pow(2,m+1)-1){//去尾
        n--;
        m--;
        if(n<0||m<0){
            break;
        }
    }
    n++;
    m++;
    if(n>=pow(2,m+1)-1){//去整
        num+=(int)pow(2,m);
        return;
    }
    n-=(int)(pow(2,m)-1);//去肉
    int k=(int)pow(2,m-1);//肉的底部
    if(k==0){k=1;}
    num+=k;
    cal(n,m);//继续加工
    return;
}

int main(){
    int T;
    scanf("%d",&T);
    for(;T>0;T--){
        scanf("%d %d",&n,&m);
        cal(n,m);
        printf("%d\n",num);
        num=0;
    }
    return 0;
}