#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define left LEFT
#define right RIGHT

using namespace std;

int FASTBUFFER;

const int N = 300005;

int left[N << 2], right[N << 2], n, m;
long long v1[N << 2], v2[N << 2], ans[N << 2];
long long h[N << 2], s[N << 2], d[N << 2], ansNow, v1Now;

void up(int i) {
    int lc = (i << 1), rc = (lc | 1);
    ans[i] = max(max(ans[lc], ans[rc]), v2[rc] - v1[lc]);
    v1[i] = min(v1[lc], v1[rc]);
    v2[i] = max(v2[lc], v2[rc]);
}

void make(int l, int r, int i) {
    left[i] = l, right[i] = r;
    if (l == r) {
        v1[i] = s[r - 1] - 2 * h[(r - 1) % n + 1];
        v2[i] = s[r - 1] + 2 * h[(r - 1) % n + 1];
        ans[i] = 0;
        return;
    }
    
    int mid = (l + r) >> 1;
    make(l, mid, (i << 1));
    make(mid + 1, r, ((i << 1) | 1));
    up(i);
}

void ask(int l, int r, int i) {
    if (l > right[i] || r < left[i]) {
        return;
    }
    
    if (l <= left[i] && r >= right[i]) {
        ansNow = max(ansNow, ans[i]);
        ansNow = max(ansNow, v2[i] - v1Now);
        v1Now = min(v1Now, v1[i]);
        return;
    }
    
    ask(l, r, (i << 1));
    ask(l, r, ((i << 1) | 1));
}

int main() {
   // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &d[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + d[i];
    }
    
    for (int i = n + 1; i <= n + n; i++) {
        s[i] = s[i - 1] + d[i - n];
    }
    
    make(1, n + n, 1);
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x <= y) {
            ansNow = 0;
            v1Now = (1LL << 61);
            ask(y + 1, n + x - 1, 1);
        } else {
            ansNow = 0;
            v1Now = (1LL << 61);
            ask(y + 1, x - 1, 1);
        }
        
        cout << ansNow << endl;
    }

    return 0;
}