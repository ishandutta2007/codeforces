#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int a[N];
int vis[N];
int vis_id = 880301;

void go() {
    ++vis_id;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        a[i] = i - x;
    }
    int now = 1;
    vector<int> v;
    while (vis[now] != vis_id) {
        v.push_back(now);
        vis[now] = vis_id;
        now = a[now];
    }
    vector<int> ans;
    while (v.back() != now) {
        ans.push_back(v.back());
        v.pop_back();
    }
    ans.push_back(now);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
    }
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}