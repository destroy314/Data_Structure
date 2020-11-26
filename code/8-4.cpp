#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> map;
queue<int> sec;
int vis[10] = {0};

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        vector<int> emp;
        map.push_back(emp);
    }
    scanf("%d", &n);
    while (n != -1) {
        scanf("%d", &m);
        map[n].push_back(m);
        map[m].push_back(n);
        scanf("%d", &n);
    }
    for (int i = 0; i < map.size(); i++) {
        sort(map[i].begin(), map[i].begin() + map[i].size());
    }
    for (int i = 0; i < map.size(); i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            printf("%d", i);
            for (int j = 0; j < map[i].size(); j++) {
                sec.push(map[i][j]);
            }
            while (!sec.empty()) {
                int p = sec.front();
                sec.pop();
                if (vis[p] == 0) {
                    vis[p] = 1;
                    printf("-%d", p);
                    for (int k = 0; k < map[p].size(); k++) {
                        if (vis[map[p][k]] == 0) {
                            sec.push(map[p][k]);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}