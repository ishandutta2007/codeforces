#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, m, a[N], b[N], x, y, A[N], B[N];

int ask_(int i, int j, int op) {
    return min(i, B[j]) - min(n - i, n - B[j]) + op*(x > i && y == j);
}

bool check_(int val) {
    if (a[x] + b[y] <= val)
        return 1;
    
    ll v1 = 0, v2 = 0, mx1, mx2;

    for (int i = 1, j = m; i <= n; i++) {
        while (a[i] + b[j] > val && j)
            j--;

        A[i] = j, v1 += m - j; 
    }

    for (int i = 1, j = n; i <= m; i++) {
        while (b[i] + a[j] > val && j)
            j--;
        
        B[i] = j;
    }

    v2 = v1 - 1;
    mx1 = v1, mx2 = v2;
    
    for (int i = 1, j = 0; i <= n; i++) {
        v1 += min(A[i], j) - min(m - A[i], m - j);

        while (j < m && ask_(i, j + 1, 0) >= 0)
            v1 += ask_(i, ++j, 0);
        
        mx1 = max(mx1, v1);
    }

    for (int i = 1, j = 0; i <= n; i++) {
        v2 += min(A[i], j) - min(m - A[i], m - j) + (i == x && j < y);

        while (j < m && ask_(i, j + 1, 1) >= 0)
            v2 += ask_(i, ++j, 1);
        
        mx2 = max(mx2, v2);
    }

    return mx1 == mx2;
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    
    x = a[1], y = b[1];

    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++)
        if (x == a[i]) {
            x = i;
            break;
        }
    
    for (int i = 1; i <= m; i++)
        if (y == b[i]) {
            y = i;
            break;
        }

    int l = 2, r = a[x] + b[y];

    while (l < r) {
        int mid = (l + r)>>1;

        if (check_(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", l);
}