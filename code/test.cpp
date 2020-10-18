#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;
typedef struct NODE{
    stack<int> B;
}node;
int main(){
    node *p=(node*)malloc(sizeof(node));
    int X;
    p->B.push(123);
    return 0;
}