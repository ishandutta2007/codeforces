#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b) \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    }
int n;
int q[200001];
int ans_min[200001];
int ans_max[200001];

int max_heap_size;
int max_heap[200001];

int min_heap_size;
int min_heap[200001];

void up_max_heap(int node) {
    while (node > 1) {
        if (max_heap[node / 2] < max_heap[node]) {
            swap(max_heap[node / 2], max_heap[node]);
            node /= 2;
        } else {
            break;
        }
    }
}

void up_min_heap(int node) {
    while (node > 1) {
        if (min_heap[node / 2] > min_heap[node]) {
            swap(min_heap[node / 2], min_heap[node]);
            node /= 2;
        } else {
            break;
        }
    }
}

int pop_max_heap() {
    int res = max_heap[1];
    int node = 1;
    while (true) {
        int left = node * 2;
        if (left > max_heap_size) break;
        int right = node * 2 + 1;
        if ((right > max_heap_size) || (max_heap[left] > max_heap[right])) {
            swap(max_heap[node], max_heap[left]);
            node = left;
        } else {
            swap(max_heap[node], max_heap[right]);
            node = right;
        }
    }
    if (node != max_heap_size) {
        swap(max_heap[node], max_heap[max_heap_size]);
        up_max_heap(node);
    }
    max_heap_size--;
    return res;
}

int pop_min_heap() {
    int res = min_heap[1];
    int node = 1;
    while (true) {
        int left = node * 2;
        if (left > min_heap_size) break;
        int right = node * 2 + 1;
        if ((right > min_heap_size) || (min_heap[left] < min_heap[right])) {
            swap(min_heap[node], min_heap[left]);
            node = left;
        } else {
            swap(min_heap[node], min_heap[right]);
            node = right;
        }
    }
    if (node != min_heap_size) {
        swap(min_heap[node], min_heap[min_heap_size]);
        up_min_heap(node);
    }
    min_heap_size--;
    return res;
}

void push_heap(int value) {
    max_heap_size++;
    max_heap[max_heap_size] = value;
    up_max_heap(max_heap_size);
    min_heap_size++;
    min_heap[min_heap_size] = value;
    up_min_heap(min_heap_size);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    int done = 0;
    for (int i = 1; i <= n; i++)
        if (q[i] > done) {
            for (int value = done + 1; value < q[i]; value++) push_heap(value);
            done = q[i];
            ans_min[i] = q[i];
            ans_max[i] = q[i];
        } else {
            ans_max[i] = pop_max_heap();
            ans_min[i] = pop_min_heap();
        }
    for (int i = 1; i <= n; i++) printf("%d ", ans_min[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans_max[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}