#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> V[15];
set<long long> ban, vis;
priority_queue<pair<int, vector<int>>> Q;

int main() {
    scanf("%d", &n);
    for (int i = 0, c; i < n; i++) {
        scanf("%d", &c);
        while (c--) {
            int x; scanf("%d", &x);
            V[i].push_back(x);
        }
    }
    scanf("%d", &m);
    while (m--) {
        long long h = 0;
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x), x--;
            h = (233 * h + x) % 1000000007;
        }
        ban.insert(h);
    }
    vector<int> mx;
    int num = 0;
    for (int i = 0; i < n; i++) {
        mx.push_back(V[i].size() - 1), num += V[i].back();
    }
    Q.emplace(num, mx);
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h = (233 * h + p.second[i]) % 1000000007;
        }
        if (vis.count(h)) continue;
        vis.insert(h);
        if (!ban.count(h)) {
            for (int i = 0; i < n; i++) {
                printf("%d ", p.second[i] + 1);
            }
            exit(0);
        }
        for (int i = 0; i < n; i++) {
            p.second[i]--;
            if (~p.second[i]) Q.emplace(p.first - V[i][p.second[i] + 1] + V[i][p.second[i]], p.second);
            p.second[i]++;
        }
    }
    return 0;
}