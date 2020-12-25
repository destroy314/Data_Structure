#include <cstdio>
using namespace std;

//将哈斯图表示为树，若y覆盖x则y是x的根
int ele[127] = {0};  //元素
int in[127] = {0};   //入度
int out[127] = {0};  //出度
int main() {
    while (1) {
        int e;
        char c;
        scanf("%c", &e);
        ele[e] = 1;
        c = getchar();
        if (c == '\n') {
            break;
        }
    }
    while (1) {
        int i, j;
        char c;
        getchar();
        scanf("%c,%c", &i, &j);
        in[i]++;
        out[j]++;
        getchar();
        c = getchar();
        if (c == '\n') {
            break;
        }
    }
    int p = 0;
    for (int i = 0; i < 127; i++) {
        if (ele[i] == 1 && out[i] == 0) {
            if (p != 0) {  //这一步在乐学会造成RE，原因未知
                printf(",");
            }
            printf("%c", i);
            p++;
        }
    }
    printf("\n");
    p = 0;
    for (int i = 0; i < 127; i++) {
        if (ele[i] == 1 && in[i] == 0) {
            if (p != 0) {
                printf(",");
            }
            printf("%c", i);
            p++;
        }
    }
    printf("\n");
    return 0;
}