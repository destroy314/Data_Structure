#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef struct NODE {
    int i;
    NODE *next;
} node;

vector<char> name;
vector<node *> link;
queue<int> bfs;
int main() {
    char c;
    scanf("%c", &c);
    getchar();
    while (c != '*') {
        name.push_back(c);
        link.push_back(NULL);
        scanf("%c", &c);
        getchar();
    }
    int a, b;
    scanf("%d,%d", &a, &b);
    while (a != -1) {
        node *u, *v, *t;
        u = (node *)malloc(sizeof(node));
        v = (node *)malloc(sizeof(node));
        u->i = a;
        v->i = b;
        t = link[b];
        if (t == NULL) {
            u->next = NULL;
            link[b] = u;
        } else if (t->i < a) {
            u->next = t;
            link[b] = u;
        } else {
            while (t->next != NULL && t->next->i > a) {
                t = t->next;
            }
            u->next = t->next;
            t->next = u;
        }
        t = link[a];
        if (t == NULL) {
            v->next = NULL;
            link[a] = v;
        } else if (t->i < b) {
            v->next = t;
            link[a] = v;
        } else {
            while (t->next != NULL && t->next->i > b) {
                t = t->next;
            }
            v->next = t->next;
            t->next = v;
        }
        scanf("%d,%d", &a, &b);
    }
    printf("the ALGraph is\n");
    for (int i = 0; i < name.size(); i++) {
        printf("%c", name[i]);
        node *t = link[i];
        while (t != NULL) {
            printf(" %d", t->i);
            t = t->next;
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    int vis[1000] = {0};
    for (int j = 0; j < name.size(); j++) {
        if (vis[j] == 0) {
            printf("%c", name[j]);
            vis[j] = 1;
            node *t = link[j];
            while (t != NULL) {
                bfs.push(t->i);
                t = t->next;
            }
            while (!bfs.empty()) {
                int i = bfs.front();
                bfs.pop();
                if (vis[i] == 0) {
                    vis[i] = 1;
                    printf("%c", name[i]);
                    node *t = link[i];
                    while (t != NULL) {
                        if (vis[t->i] == 0) {
                            bfs.push(t->i);
                        }
                        t = t->next;
                    }
                }
            }
        }
    }
    printf("\n");
    return 0;
}