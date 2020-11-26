#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<vector<char>> name;
vector<int> in;  //节点入度
vector<int> out;
vector<int> jin;
vector<int> vis;
struct line {
    int i;
    int p;
};
vector<vector<line>> map;

vector<queue<int>> path;
vector<queue<int>> longestpath;
struct pathindex {
    int sumvalue;  //路径总权值
    int i;         //路径索引
};
vector<pathindex> ind;
int n, m;

bool target(line m1, line m2) { return m1.i < m2.i; }
bool longway(pathindex p1, pathindex p2) { return p1.sumvalue > p2.sumvalue; }
bool waysmall(queue<int> w1, queue<int> w2) {
    int s = w1.size() < w2.size() ? w1.size() : w2.size();
    queue<int> t1 = w1;
    queue<int> t2 = w2;
    for (int i = 0; i < s; i++) {
        int n1 = t1.front();
        int n2 = t2.front();
        t1.pop();
        t2.pop();
        if (n1 < n2) {
            return true;
        } else if (n1 > n2) {
            return false;
        }
    }
}

void dfs(int i, int v, queue<int> way) {
    way.push(i);
    if (i == n - 1) {
        path.push_back(way);
        pathindex end;
        end.sumvalue = v;
        end.i = path.size() - 1;
        ind.push_back(end);
        return;
    }
    for (int j = 0; j < map[i].size(); j++) {
        dfs(map[i][j].i, v + map[i][j].p, way);
    }
    return;
}

int main() {
    scanf("%d,%d", &n, &m);
    getchar();
    char c;
    for (int i = 0; i < n; i++) {
        vector<char> node;
        scanf("%c", &c);
        while (c != ',' && c != '\n') {
            node.push_back(c);
            scanf("%c", &c);
        }
        name.push_back(node);
        vector<line> t;
        map.push_back(t);
        in.push_back(0);
        out.push_back(0);
        jin.push_back(0);
        vis.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        sort(map[i].begin(), map[i].end(), target);
    }
    for (int i = 0; i < m; i++) {
        line e;
        int s;
        scanf("<%d,%d,%d>", &s, &e.i, &e.p);
        getchar();
        map[s].push_back(e);
        in[e.i]++;
        out[s]++;
        jin[e.i]++;
    }

    int went = 0;
    for (int i = 0; i < n; i++) {
        if (jin[i] == 0 && vis[i] == 0) {
            vis[i] = 1;
            for (int j = 0; j < map[i].size(); j++) {
                jin[map[i][j].i]--;
            }
            went++;
            break;
        }
    }
    while (1) {
        int i;
        for (i = 0; i < n; i++) {
            if (jin[i] == 0 && vis[i] == 0) {  //入度为零且未被访问过
                vis[i] = 1;
                for (int j = 0; j < map[i].size(); j++) {
                    jin[map[i][j].i]--;
                }
                went++;
                break;
            }
        }
        if (i == n) {
            if (went != n) {
                printf("NO TOPOLOGICAL PATH\n");
                return 0;
            }
            for (int j = 0; j < vis.size(); j++) {
                vis[j] = 0;
            }
            break;
        }
    }

    int output = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0 && vis[i] == 0) {
            vis[i] = 1;
            for (int j = 0; j < name[i].size(); j++) {
                printf("%c", name[i][j]);
            }
            for (int j = 0; j < map[i].size(); j++) {
                in[map[i][j].i]--;
            }
            output++;
            break;
        }
    }
    while (1) {
        int i;
        for (i = 0; i < n; i++) {
            if (in[i] == 0 && vis[i] == 0) {  //入度为零且未被访问过
                vis[i] = 1;
                printf("-");
                for (int j = 0; j < name[i].size(); j++) {
                    printf("%c", name[i][j]);
                }
                for (int j = 0; j < map[i].size(); j++) {
                    in[map[i][j].i]--;
                }
                output++;
                break;
            }
        }
        if (output == n) {
            printf("\n");
            break;
        }
    }

    queue<int> root;
    dfs(0, 0, root);
    sort(ind.begin(), ind.end(), longway);  //得到的所有路径从大到小排列
    int i;
    for (i = 0; i < ind.size() && ind[i].sumvalue == ind[0].sumvalue; i++) {
        longestpath.push_back(path[ind[i].i]);
    }
    sort(longestpath.begin(), longestpath.begin() + i - 1, waysmall);
    for (int j = 0; j < i; j++) {
        for (int l = 0; l < name[longestpath[j].front()].size(); l++) {
            printf("%c", name[longestpath[j].front()][l]);
        }
        longestpath[j].pop();
        while (!longestpath[j].empty()) {
            printf("-");
            for (int l = 0; l < name[longestpath[j].front()].size(); l++) {
                printf("%c", name[longestpath[j].front()][l]);
            }
            longestpath[j].pop();
        }
        printf("\n");
    }
    return 0;
}