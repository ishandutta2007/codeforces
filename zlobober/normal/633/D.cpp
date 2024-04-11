#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 1050;
int orig_cnt[N];
int cnt[N];
int A[N];
int B[N];

int ver[N];
int curver = 0;

int k;

int index(int x) {
    int* res = lower_bound(B, B + k, x);
    if (res == B + k || *res != x)
        return -1;
    return res - B;
}

bool dec(int x) {
    x = index(x);
    if (x == -1)
        return false;
    if (ver[x] != curver)
        cnt[x] = orig_cnt[x], ver[x] = curver;
    if (cnt[x] == 0)
        return false;
    cnt[x]--;
    return true;
}

int get(int a, int b) {
    if (a == 0 && b == 0)
        return -42;
    curver++;
    assert(dec(a));
    assert(dec(b));
    int ans = 2;
    while (true) {
        int c = a + b;
        if (!dec(c))
            break;
        ans++;
        a = b;
        b = c;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || A[i] != A[i - 1])
            B[k] = A[i], cnt[k] = 1, k++;
        if (i != 0 && (A[i] == A[i - 1]))
            cnt[k - 1]++;
    }
    memcpy(orig_cnt, cnt, sizeof(cnt));
    int best = 2;
    int pos0 = find(B, B + k, 0) - B;
    if (pos0 != k) {
        best = max(best, cnt[pos0]);
    }
    for (int i = 0; i < k; i++) {
        if (orig_cnt[i] >= 2)
            best = max(best, get(B[i], B[i]));
        for (int j = 0; j < i; j++) {
            best = max(best, get(B[i], B[j]));
            best = max(best, get(B[j], B[i]));
        }
    }
    printf("%d\n", best);
}