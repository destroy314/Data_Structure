#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(){
    int p=0;
    while(1){
        stack<int> output;
        queue<int> input;
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0){break;}
        if(p!=0){cout<<endl;}
        p++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                output.push(j+1);
                int a;
                cin>>a;
                input.push(a);
                while(!output.empty()&&output.top()==input.front()){
                    output.pop();
                    input.pop();
                }
            }
            if(!output.empty()){
                while(!output.empty()){
                    output.pop();
                    input.pop();
                }
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}