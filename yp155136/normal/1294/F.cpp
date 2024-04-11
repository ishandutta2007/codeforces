#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int n;
vector<int> G[N];

vector<int> get_dis(int x) {
    vector<int> dis(n + 1, N);
    dis[x] = 0;
    queue<int> que;
    que.push(x);
    while (!que.empty()) {
        int t = que.front(); que.pop();
        for (int i: G[t]) {
            if (dis[i] == N) {
                dis[i] = dis[t] + 1;
                que.push(i);
            }
        }
    }
    dis[0] = -1;
    return dis;
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> ret = get_dis(1);
    int v1 = max_element(ret.begin(), ret.end()) - ret.begin();
    vector<int> dis1 = get_dis(v1);
    int v2 = max_element(dis1.begin(), dis1.end()) - dis1.begin();
    vector<int> dis2 = get_dis(v2);
    int ans = -1;
    int a, b, c;
    for (int i = 1; i <= n; ++i) {
        int val = (dis1[v2] + dis1[i] + dis2[i]) / 2;
        if (val > ans && i != v1 && i != v2) {
            ans = val;
            a = v1, b = v2, c = i;
        }
    }
    printf("%d\n", ans);
    printf("%d %d %d\n", a, b, c);
}