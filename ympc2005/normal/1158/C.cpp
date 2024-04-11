#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, a[N], d[N], s[N], top, p[N], cnt;

vector <int> e[N];

void work_() {
    e[n + 1].clear();
    d[n + 1] = 0;
    s[top = 1] = n + 1;

    for (int i = n; i; i--) {
        if (a[i] == -1) {
            s[++top] = i;
            continue;
        }

        while (top && s[top] < a[i]) {
            d[s[top]]++;
            e[i].push_back(s[top--]);
        }

        if (s[top] != a[i]) {
            cout<<-1<<'\n';
            return;
        }

        if (a[i] <= n) {
            d[i]++;
            e[a[i]].push_back(i);
        }

        s[++top] = i;
    }

    queue <int> q;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }

    cnt = n;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        p[u] = cnt--;

        for (int v : e[u]) {
            if (!--d[v]) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout<<p[i]<<' ';
    }

    cout<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        cin>>n;

        for (int i = 1; i <= n; i++) {
            cin>>a[i];
            e[i].clear();
            d[i] = 0;
        }

        work_();
    }
}