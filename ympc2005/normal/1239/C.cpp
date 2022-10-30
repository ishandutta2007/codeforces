#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, p, t[N], id[N], q1[N], l, r;

ll ans[N];

priority_queue <int, vector <int>, greater <int> > q2;

bool cmp_(int u, int v) {
    return t[u] == t[v] ? u < v : t[u] < t[v];
}

int main() {
    scanf("%d%d", &n, &p);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp_);
    ll cur = 0;
    int pos = 1;
    l = 1, r = 0;

    while (pos <= n || l <= r || q2.size()) {
        if (l <= r) {
            int x = q1[l];
            cur = ans[x];

            while (pos <= n && t[id[pos]] < cur) {
                if (id[pos] < q1[r]) {
                    q1[++r] = id[pos];
                    ans[id[pos]] = ans[q1[r - 1]] + p;
                } else {
                    q2.push(id[pos]);
                }

                pos++;
            }

            l++;
        }       

        if (l > r && !q2.size()) {
            cur = t[id[pos]];
        }

        while (pos <= n && cur == t[id[pos]]) {
            q2.push(id[pos++]);
        }

        if (q2.size() && (l > r || q2.top() < q1[r])) {
            q1[++r] = q2.top();
            q2.pop();
            ans[q1[r]] = max(cur, ans[q1[r - 1]]) + p;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
}