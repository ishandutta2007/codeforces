#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, m, tot, ans, a[N], b[N], pos, c[N], L[N], R[N];

vector <int> id[N];

void work_() {
    for (int i = 1; i <= m; i++) {
        if (L[pos] > R[pos])
            pos++;

        if (R[pos] - L[pos] + 1 >= m - i + 1) {
            for (int j = m; j >= i; j--)
                c[j] = id[pos][L[pos]++];
            
            break;
        } else
            c[i] = id[pos][R[pos]--];
    }

    for (int i = 2; i <= m; i++)
        for (int j = 1; j < i; j++)
            ans += c[j] < c[i];
}

void solve_() {
    scanf("%d%d", &n, &m);
    ans = 0, pos = 1;

    for (int i = 1; i <= n*m; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    
    sort(b + 1, b + n*m + 1), tot = unique(b + 1, b + n*m + 1) - b - 1;

    for (int i = 1; i <= tot; i++)
        id[i].clear();

    for (int i = 1; i <= n*m; i++)  
        id[lower_bound(b + 1, b + tot + 1, a[i]) - b].push_back(i);
    
    for (int i = 1; i <= tot; i++)  
        L[i] = 0, R[i] = id[i].size() - 1;

    for (int i = 1; i <= n; i++) 
        work_();

    printf("%d\n", ans); 
}

int main() {
    scanf("%d", &T);

    while (T--) 
        solve_();
}