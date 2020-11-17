#include <stdio.h>
int max[10000];                              //大顶堆
void shiftdown(int arr[], int t, int end) {  //大顶堆堆化
    int p;
    if (2 * t + 1 > end) {
        return;
    }
    if (2 * t + 2 <= end) {
        if (arr[t] >= arr[2 * t + 1] && arr[t] >= arr[2 * t + 2]) {
            return;
        }
        if (arr[t] < arr[2 * t + 1] && arr[t] < arr[2 * t + 2]) {
            if (arr[2 * t + 1] > arr[2 * t + 2]) {
                int temp = arr[t];
                arr[t] = arr[2 * t + 1];
                arr[2 * t + 1] = temp;
                p = 2 * t + 1;
                goto next;
            }
            if (arr[2 * t + 1] <= arr[2 * t + 2]) {
                int temp = arr[t];
                arr[t] = arr[2 * t + 2];
                arr[2 * t + 2] = temp;
                p = 2 * t + 2;
                goto next;
            }
        }
        if (arr[t] < arr[2 * t + 1]) {
            int temp = arr[t];
            arr[t] = arr[2 * t + 1];
            arr[2 * t + 1] = temp;
            p = 2 * t + 1;
            goto next;
        }
        if (arr[t] < arr[2 * t + 2]) {
            int temp = arr[t];
            arr[t] = arr[2 * t + 2];
            arr[2 * t + 2] = temp;
            p = 2 * t + 2;
            goto next;
        }
        return;
    }
    if (2 * t + 1 <= end) {
        if (arr[t] >= arr[2 * t + 1]) {
            return;
        }
        int temp = arr[t];
        arr[t] = arr[2 * t + 1];
        arr[2 * t + 1] = temp;
        p = 2 * t + 1;
    }
next:;
    shiftdown(arr, p, end);
}
void output(int arr[], int l) {
    for (int i = 0; i < l; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d \n", arr[l]);
}
int main() {
    int T;
    scanf("%d", &T);
    int end = 0;
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        max[end++] = n;
    }
    for (int i = T - 1; i >= 0; i--) {
        shiftdown(max, i, end - 1);
    }
    output(max, end - 1);
    max[0] = max[--end];
    shiftdown(max, 0, end - 1);
    output(max, end - 1);
    max[0] = max[--end];
    shiftdown(max, 0, end - 1);
    output(max, end - 1);
    return 0;
}

//依次插入和读入二叉树后从下向上堆化得到的堆是不同的