#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MN = 300300;

ll t[MN], d[MN]; //ballons, remain

P idx[MN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", t+i, d+i);
        d[i] = (d[i]-t[i])+1;
        idx[i] = P(t[i], i);
    }
    sort(idx, idx+n, [&](P l, P r){
        if (l.first != r.first) {
            return l.first > r.first;
        }
        return l.second < r.second;
    });

    int pos = -1;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < n; i++) {
        int p = idx[i].second;
        if (p == 0) {
            pos = i;
            break;
        }
        que.push(d[p]);
    }
    assert(pos >= 0);
    ll rem = t[0];
    int ans = pos;
    int ers = 0;
    while (que.size()) {
        ll us = que.top(); que.pop();
        if (rem < us) break;
        rem -= us;
        ers++;
        while (pos < n-1) {
            int nx = idx[pos+1].second;
            if (t[nx] <= rem) break;
            pos++;
            que.push(d[nx]);
        }
        ans = min(ans, pos-ers);
    }
    printf("%d\n", ans+1);
    return 0;
}