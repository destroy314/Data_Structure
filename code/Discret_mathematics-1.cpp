#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

typedef struct NODE {
    char sym;
    int val;
    struct NODE *lson;
    struct NODE *rson;
} node;
stack<node *> gene;        //从后缀表达式构造树所用的栈
int symval[128] = {0};     //储存每个命题变元的值
int truelist[1024] = {0};  //真值表
int pri[128] = {0};        //运算符优先级
stack<char> calcu;         //转后缀表达式使用的栈
queue<char> anser;         //转后缀表达式的结果

/*计算root的值*/
void cal(node *root) {
    if (root->lson == root->rson) {
        root->val = symval[root->sym];
        return;
    }
    if (root->lson != NULL) {
        cal(root->lson);
    }
    if (root->rson != NULL) {
        cal(root->rson);
    }
    switch (root->sym) {
        case '!':
            root->val = !root->lson->val;
            break;
        case '&':
            root->val = root->lson->val && root->rson->val;
            break;
        case '|':
            root->val = root->lson->val || root->rson->val;
            break;
        case '-':
            if (root->lson->val == 1 && root->rson->val == 0) {
                root->val = 0;
            } else {
                root->val = 1;
            }
            break;
        case '+':
            if (root->lson->val == root->rson->val) {
                root->val = 1;
            } else {
                root->val = 0;
            }
            break;
    }
    return;
}

node *newnode(char c) {
    node *t = (node *)malloc(sizeof(node));
    t->sym = c;
    t->val = 0;
    t->lson = NULL;
    t->rson = NULL;
    return t;
}

int main() {
    pri['-'] = 1;
    pri['+'] = 1;
    pri['&'] = 2;
    pri['|'] = 2;
    pri['!'] = 3;
    pri['('] = -1;
    pri[')'] = 4;
    char c;
    while (1) {  //将输入转化为后缀表达式
        scanf("%c", &c);
        if (c == '\n') {
            while (!calcu.empty()) {
                anser.push(calcu.top());
                calcu.pop();
            }
            goto end;
        }
        symval[c] = 1;
        switch (pri[c]) {
            case 4:
                while (calcu.top() != '(') {
                    anser.push(calcu.top());
                    calcu.pop();
                }
                calcu.pop();
                break;
            case 0:
                anser.push(c);
                break;
            case -1:
                calcu.push(c);
                break;
            default:
                while (!calcu.empty() && pri[calcu.top()] >= pri[c]) {
                    anser.push(calcu.top());
                    calcu.pop();
                }
                calcu.push(c);
        }
    }
end:;
    node *p;
    while (!anser.empty()) {  //将后缀表达式转化为二叉树
        c = anser.front();
        anser.pop();
        switch (pri[c]) {
            case 3:
                p = newnode('!');
                p->lson = gene.top();
                gene.pop();
                gene.push(p);
                break;
            case 0:
                p = newnode(c);
                gene.push(p);
                break;
            default:
                p = newnode(c);
                p->rson = gene.top();
                gene.pop();
                p->lson = gene.top();
                gene.pop();
                gene.push(p);
                break;
        }
    }
    node *root = gene.top();
    int syms, syme;
    for (int i = 65; i < 123; i++) {  //计算使用的命题变元字母
        if (symval[i - 1] < symval[i]) {
            syms = i;
        }
        if (symval[i - 1] > symval[i]) {
            syme = i - 1;
            break;
        }
    }
    int num = syme - syms + 1;
    for (int i = 0; i < pow(2, num); i++) {  //计算真值表
        for (int j = syms; j <= syme; j++) {
            symval[j] =
                1 &
                i >> (syme -
                      j);  //用右移位和按位与将i转化为命题变元取值的二进制编码
        }
        cal(root);
        truelist[i] = root->val;
    }
    int out = 0;
    for (int i = 0; i < pow(2, num); i++) {  //主析取范式
        if (truelist[i] == 1) {
            if (out > 0) {
                printf("∨ ");
            }
            printf("m%d ", i);
            out++;
        }
    }
    if (out == 0) {
        printf("0 ");
    }
    printf(";");
    out = 0;
    for (int i = 0; i < pow(2, num); i++) {  //主合取范式
        if (truelist[i] == 0) {
            if (out > 0) {
                printf(" ∧");
            }
            printf(" M%d", i);
            out++;
        }
    }
    if (out == 0) {
        printf(" 1");
    }
    printf("\n");
    return 0;
}