#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
struct Pi {
    int x, y;
    Pi() {}
    Pi(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator<(Pi &r) {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
};
struct Ti {
    int x, y, z;
    Ti() {}
    Ti(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
};
const int MN = 202000;
vector<int> g[MN];
int res[MN];
void dfs(int i, int d) {
    res[i] = d;
    for (int u: g[i]) {
        dfs(u, 1-d);
    }
}
int main() {
    int n;
    cin >> n;
    priority_queue<Ti, vector<Ti>, greater<Ti>> que;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; y++;
        que.push(Ti(x, y, i));
    }
    int c = n;
    while (que.size() >= 2) {
        Ti q1 = que.top(); que.pop();
        Ti q2 = que.top(); que.pop();
        if (q1.y > q2.y) swap(q1, q2);
        g[q1.z].push_back(q2.z);
        g[c].push_back(q1.z);
        que.push(Ti(q1.y, q2.y, c));
        c++;
    }
    dfs(que.top().z, 0);
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}