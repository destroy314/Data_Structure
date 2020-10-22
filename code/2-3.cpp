#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int SET;
    scanf("%d",&SET);
    for(int i=0;i<SET;i++){
        int N,S,Q;
        int time=0;
        int cargo=0;
        vector<queue<int>> pf;//每个queue代表某站点的B平台
        scanf("%d %d %d",&N,&S,&Q);
        stack<int> truck;
        for(int j=0;j<N;j++){
            queue<int> B;
            int n,X;
            scanf("%d",&n);
            if(n>0){cargo++;}
            for(int k=0;k<n;k++){
                scanf("%d",&X);
                B.push(X);
            }
            pf.push_back(B);
        }
        int n=-1;//耗时与卡车的出发地有关，但题目中没有给
        while(1){
            n++;
            if(n==N){n=0;}
            int e=pf[n].empty();
            while(!truck.empty()){//卸货
                if(truck.top()==n+1){
                    truck.pop();
                    time++;
                    continue;
                }
                if(pf[n].size()==Q){break;}
                else{
                    pf[n].push(truck.top());
                    truck.pop();
                }
                time++;
            }
            if(cargo==0&&pf[n].empty()){break;}
            while(truck.size()<S){//装货
                if(pf[n].empty()){break;}
                truck.push(pf[n].front());
                pf[n].pop();
                time++;
            }
            if(pf[n].empty()&&!e){cargo--;}
            else if(e&&!pf[n].empty()){cargo++;}
            time+=2;
        }
        printf("%d\n",time);
    }
    return 0;
}