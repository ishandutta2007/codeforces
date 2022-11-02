#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, a[N], b[N], f[N], p[N];

set <int> s;

set <int> :: iterator it;

queue <int> q;

int main() {
    scanf("%d", &n), s.insert(0);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }

    memset(f, -1, sizeof(f));
    f[n] = 0, q.push(n), s.erase(n);

    while (!q.empty()) {
        int u = q.front(), x = u + b[u]; q.pop();

        it = s.lower_bound(x - a[x]);

        while (it != s.end() && (*it) < x) {
            int v = *it;
            f[v] = f[u] + 1, p[v] = u, q.push(v);
            s.erase(v), it = s.lower_bound(x - a[x]); 
        }
    }

    if (f[0] == -1) {
        puts("-1");
    } else {
        printf("%d\n", f[0]);
        vector <int> ans;

        for (int i = 0; i != n; i = p[i]) {
            ans.push_back(i);
        }

        for (int i = (int) ans.size() - 1; i >= 0; i--) {
            printf("%d ", ans[i]);
        }

        puts("");
    }
}