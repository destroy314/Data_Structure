#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main(){
    stack<int> brackets;
    char a;
    while(1){
        a=getchar();
        if(a=='\n'){break;}
        if(a!='('&&a!=')'&&a!='['&&a!=']'){continue;}
        if(a=='('||a=='['){
            brackets.push(a);
            continue;
        }
        else{
            if(brackets.empty()){
                cout<<"Match false!"<<endl;
                return 0;
            }
            if(a==')'&&brackets.top()!='('){
                cout<<"Match false!"<<endl;
                return 0;
            }
            if(a==']'&&brackets.top()!='['){
                cout<<"Match false!"<<endl;
                return 0;
            }
            brackets.pop();
        }
    }
    if(brackets.empty()){
        cout<<"Match succeed!"<<endl;
    }
    else{
        cout<<"Match false!"<<endl;
    }
    return 0;
}