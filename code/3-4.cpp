#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<char> sym;
vector<char> ans;
int pri[128]={0};//运算符优先级

/*从答案队列中读取队尾的一个数字或是一对括号，放入sym中*/
void mov(){
    char p;
    p=ans.back();
    ans.pop_back();
    sym.push(p);
    if(pri[p]==0){return;}//压入一个数字
    int k=1;
    while(1){//压入成对的括号
        p=ans.back();
        ans.pop_back();
        sym.push(p);
        if(p==')'){k++;}
        if(p=='('){k--;}
        if(k==0){return;}
    }
}

/*读入流，处理成后缀放入ans，直到遇到对应的括号*/
void add(){
    int k=0;//乘方列长度
    int ignore=0;//要忽略括号中的乘方符号,此为括号层级
    while(1){
        char p;//最新读入的字符
        cin>>p;
        switch(pri[p]){
        case 0://数字
            ans.push_back(p);
            break;
        case 3://乘方
            sym.push(p);
            mov();
            k++;
            break;
        case 4://左括号，递归调用输出整个括号内的内容
            sym.push(p);
            ans.push_back(p);
            add();
            break;
        case 5://右括号，弹出整个括号对，调用中止
            ignore=0;
            if(k==0){
                while(sym.top()!='('){
                    ans.push_back(sym.top());
                    sym.pop();
                }
                ans.push_back(')');
                sym.pop();
            }
            else{
                while(1){
                    if(sym.top()=='('){ignore++;}
                    if(sym.top()==')'){ignore--;}
                    if(sym.top()=='^'&&ignore==0){k--;}
                    ans.push_back(sym.top());
                    sym.pop();
                    if(k==0){break;}
                }
            }
            return;
        case -1://中止符
            while(!sym.empty()){
                ans.push_back(sym.top());
                sym.pop();
            }
            return;
        default://其他符号，即四则运算
            ignore=0;
            if(k==0){//前面没有乘方列时正常弹出优先级更高的运算符
                while(!sym.empty()&&pri[sym.top()]>=pri[p]){
                    if(sym.top()=='('){break;}
                    ans.push_back(sym.top());
                    sym.pop();
                }
            }
            else{
                while(!sym.empty()){//前面有乘方列时先弹出整个乘方列
                    if(sym.top()=='('){ignore++;}
                    if(sym.top()==')'){ignore--;}
                    if(sym.top()=='^'&&ignore==0){k--;}
                    ans.push_back(sym.top());
                    sym.pop();
                    if(k==0){break;}
                }
                while(!sym.empty()&&pri[sym.top()]>=pri[p]){//再弹出优先级更高的运算符
                    if(sym.top()=='('){break;}
                    ans.push_back(sym.top());
                    sym.pop();
                }
            }
            sym.push(p);
            break;
        }
    }
}

int main(){
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
        add();
        while(!ans.empty()){
            if(ans[0]!='('&&ans[0]!=')'){
                cout<<ans[0];
            }
            ans.erase(ans.begin());
        }
        cout<<endl;
    }
    return 0;
}

//此程序使用的乘方定义为：2^3^4=43^2^
//没有十年脑溢血想不出来