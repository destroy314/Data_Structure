#include <cstdio>
#include <vector>
using namespace std;
typedef struct PEER {
    int key;
    int num;
} peer;
vector<peer> list;

int find(int k, int start, int end) {
    if (start == end) {
        if (list[start].key == k) {
            return list[start].num;
        } else {
            return -1;
        }
    }
    int mid = (start + end) / 2;
    int j = list[mid].key;
    if (k <= j) {
        return find(k, start, mid);
    } else {
        return find(k, mid + 1, end);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        peer t;
        scanf("%d %d", &t.key, &t.num);
        int j;
        for (j = 0; j < list.size(); j++) {
            if (list[j].key > t.key) {
                break;
            }
        }
        list.insert(list.begin() + j, t);
    }
    int findkey;
    scanf("%d", &findkey);
    int index = find(findkey, 0, list.size());
    for (int j = 0; j < list.size(); j++) {
        printf("(%d %d)", list[j].key, list[j].num);
    }
    if (index >= 0) {
        printf("\n(%d %d)\n", findkey, index);
    } else {
        printf("\nerror\n");
    }
    return 0;
}