#include <cstdio>
#include <vector>
using namespace std;
struct T {
    int line[128] = {
        0};  //存储简单析取式，1代表有某个原子命题，-1代表有它的否定
};
vector<T> S0;
vector<T> S1;
vector<T> S2;

int canres(T C1, T C2) {
    for (int i = 0; i < 128; i++) {
        if (C1.line[i] + C2.line[i] == 0 && C1.line[i] != 0) {
            return 1;
        }
    }
    return 0;
}

T Res(T C1, T C2) {
    T C;
    int resed = 0;
    for (int i = 0; i < 128; i++) {
        C.line[i] = C1.line[i] + C2.line[i];
        if (C1.line[i] + C2.line[i] == 0 && C1.line[i] != 0) {
            if (resed == 0) {
                resed = 1;
            } else {
                C.line['-'] = 1;  //如果之前消去过，就产生不可破坏的恒真命题p|!p
            }
        }
        if (C.line[i] == 2) {
            C.line[i] = 1;
        } else if (C.line[i] == -2) {
            C.line[i] = -1;
        }
    }
    return C;
}

int isempty(T C) {
    for (int i = 0; i < 128; i++) {
        if (C.line[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int belon(vector<T> S, T C) {
    for (int i = 0; i < S.size(); i++) {
        int judje = 0;
        for (int j = 0; j < 128; j++) {
            if (S[i].line[j] != C.line[j]) {
                judje = 1;
                break;
            }
        }
        if (judje == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char c;
    scanf("%c", &c);
    while (1) {  //输入
        if (c == '\n') {
            break;
        } else if (c == '(') {
            T v;
            scanf("%c", &c);
            while (1) {
                if (c == ')') {
                    break;
                } else if (c == '!') {
                    scanf("%c", &c);
                    v.line[c] += -1;
                    if (v.line[c] == -2) {
                        v.line[c] = -1;
                    }
                } else if (c != '|') {
                    v.line[c] += 1;
                    if (v.line[c] == 2) {
                        v.line[c] = 1;
                    }
                }
                scanf("%c", &c);
            }
            S1.push_back(v);
        } else if (c != '&') {
            int val = 1;
            T v;
            if (c == '!') {
                val = -1;
                scanf("%c", &c);
            }
            v.line[c] = val;
            S1.push_back(v);
        }
        scanf("%c", &c);
    }
start:;
    for (int i = 0; i < S0.size(); i++) {
        for (int j = 0; j < S1.size(); j++) {
            if (canres(S0[i], S1[j])) {
                T C = Res(S0[i], S1[j]);
                if (isempty(C)) {
                    printf("NO\n");
                    return 0;
                }
                if (!belon(S0, C) && !belon(S1, C)) {
                    S2.push_back(C);
                }
            }
        }
    }
    for (int i = 0; i < S1.size(); i++) {
        for (int j = i + 1; j < S1.size(); j++) {
            if (canres(S1[i], S1[j])) {
                T C = Res(S1[i], S1[j]);
                if (isempty(C)) {
                    printf("NO\n");
                    return 0;
                }
                if (!belon(S0, C) && !belon(S1, C)) {
                    S2.push_back(C);
                }
            }
        }
    }
    if (S2.empty()) {
        printf("YES\n");
        return 0;
    } else {
        for (int i = 0; i < S1.size(); i++) {
            S0.push_back(S1[i]);
        }
        S1 = S2;
        S2.clear();
        goto start;
    }
}