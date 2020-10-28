#include <queue>
#include <vector>
#include <iostream>
using namespace std;
queue<char> ans[100];
vector<char> in;
vector<char> post;

void analyse(int start,int end,int deep){
    if(start>end){return;}
    ans[deep].push(post[end]);//末尾一定是父节点
    char root=post[end];
    post.erase(post.begin()+end);
    int i=start;
    while(in[i]!=root){i++;}
    post.insert(post.begin()+i,root);
    analyse(start,i-1,deep+1);
    analyse(i+1,end,deep+1);
    return;
}

int main(){
    char inseq[1000];
    char postseq[1000];
    cin>>inseq;
    cin>>postseq;
    int i=0;
    while(inseq[i]!='\0'){
        in.push_back(inseq[i]);
        post.push_back(postseq[i]);
        i++;
    }
    analyse(0,i-1,0);
    i=0;
    while(!ans[i].empty()){
        while(!ans[i].empty()){
            cout<<ans[i].front();
            ans[i].pop();
        }
        i++;
    }
    cout<<endl;
    return 0;
}