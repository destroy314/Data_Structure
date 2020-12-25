#include <cstdio>
using namespace std;

int main() {
    int mat[11][11];
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            mat[i][j] = 0;
        }
    }
    char c;
    int n;  //关系的基数-1
    for (n = 0; n < 11; n++) {
        scanf("%d", &mat[0][n]);
        c = getchar();
        if (c == '\n') {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%d", &mat[i][j]);
            getchar();
        }
    }
    while (1) {
        int add = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (mat[i][j] == 1) {
                    for (int k = 0; k <= n; k++) {
                        if (mat[j][k] == 1) {
                            if (mat[i][k] == 0) {
                                mat[i][k] = 1;
                                add++;
                            }
                        }
                    }
                }
            }
        }
        if (add == 0) {
            break;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("%d\n", mat[i][n]);
    }
    return 0;
}