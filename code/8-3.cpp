#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

typedef struct locate {
    int i;
    int j;
} l;
vector<vector<int>> maze;
vector<vector<int>> vis;
stack<l> path;
int n, m;

int block(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return 1;
    }
    return maze[i][j] || vis[i][j];
}

int dfs(int i, int j) {
    if (i == n - 1 && j == m - 1) {
    finded:;
        l pos;
        pos.i = i + 1;
        pos.j = j + 1;
        path.push(pos);
        return 1;
    }
    if (block(i - 1, j) && block(i, j - 1) && block(i + 1, j) &&
        block(i, j + 1)) {
        return 0;
    }
    vis[i][j] = 1;
    if (!block(i + 1, j)) {
        if (dfs(i + 1, j) == 1) {
            goto finded;
        }
    }
    if (!block(i, j + 1)) {
        if (dfs(i, j + 1) == 1) {
            goto finded;
        }
    }
    if (!block(i - 1, j)) {
        if (dfs(i - 1, j) == 1) {
            goto finded;
        }
    }
    if (!block(i, j - 1)) {
        if (dfs(i, j - 1) == 1) {
            goto finded;
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<int> line;
        vector<int> zero;
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            line.push_back(t);
            zero.push_back(0);
        }
        maze.push_back(line);
        vis.push_back(zero);
    }
    if (dfs(0, 0) == 0) {
        printf("There is no solution!\n");
        return 0;
    }
    while (!path.empty()) {
        l step = path.top();
        path.pop();
        printf("<%d,%d> ", step.i, step.j);
    }
    printf("\n");
    return 0;
}