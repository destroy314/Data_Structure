#include <stdio.h>
int median3[20];
int pos = 0;
int list[10000];

void swap(int a, int b) {
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
    return;
}

void insertsort(int start, int end) {
    int temp;
    for (int i = start; i <= end; i++) {
        temp = list[i];
        int j;
        for (j = i; j > 0 && list[j - 1] > temp; j--) {
            list[j] = list[j - 1];
        }
        list[j] = temp;
    }
}

int median(int start, int end) {
    int mid = (start + end) / 2;
    if (list[start] > list[mid]) {
        swap(start, mid);
    }
    if (list[start] > list[end]) {
        swap(start, end);
    }
    if (list[mid] > list[end]) {
        swap(mid, end);
    }
    swap(mid, end - 1);
    median3[pos++] = list[end - 1];
    return list[end - 1];
}

void quicksort(int start, int end) {
    if (end - start + 1 <= 5) {
        insertsort(start, end);
        return;
    }
    int p = median(start, end);
    int i = start, j = end - 1;
    while (1) {
        while (list[++i] < p)
            ;
        while (list[--j] > p)
            ;
        if (i < j) {
            swap(i, j);
        } else {
            break;
        }
    }
    swap(i, end - 1);
    quicksort(start, i - 1);
    quicksort(i + 1, end);
}

int main() {
    int i;
    for (i = 0; i < 20; i++) {
        median3[i] = -1;
    }
    for (i = 0; 1; i++) {
        int n, j;
        j = scanf("%d", &n);
        if (!j) {
            break;
        }
        list[i] = n;
    }
    quicksort(0, i - 1);
    printf("After Sorting:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", list[j]);
    }
    printf("\nMedian3 Value:\n");
    if (median3[0] == -1) {
        printf("none\n");
    } else {
        i = 0;
        while (median3[i++] != -1) {
            printf("%d ", median3[i - 1]);
        }
        printf("\n");
    }
    return 0;
}