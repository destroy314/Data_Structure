#include <iostream>
#include <stack>
using namespace std;

int main(){
    int pri[128]={0};//运算符优先级
    pri['+']=1;
    pri['-']=1;
    pri['*']=2;
    pri['/']=2;
    pri['^']=3;
    pri['(']=4;
    pri[')']=5;
    pri['#']=-1;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        stack<char> sym;
        while(1){
            char p;
            cin>>p;
            switch(pri[p]){
            case 0:
                cout<<p;
                break;
            case 5:
                while(sym.top()!='('){
                    cout<<sym.top();
                    sym.pop();
                }
                sym.pop();
                break;
            case -1:
                while(!sym.empty()){
                    cout<<sym.top();
                    sym.pop();
                }
                goto end;
            default:
                while(!sym.empty()&&pri[sym.top()]>=pri[p]){
                    if(p=='^'){break;}
                    if(sym.top()=='('){break;}
                    cout<<sym.top();
                    sym.pop();
                }
                sym.push(p);
            }
        }
        end:;
        cout<<endl;
    }
    return 0;
}