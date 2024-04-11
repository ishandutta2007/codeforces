#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

const int N = 1 << 19;

typedef long long llong;

llong T[N], W[N];

llong Ts[N];


struct ev {
    llong t;
    int tp;
    int id;
    // 1 - team added
    // 2 - ts
    ev(llong _t, int _tp, int _id = -1) {
        t = _t, tp = _tp;
        id = _id;
    }
    friend bool operator <(ev a, ev b) {
        if (a.t != b.t)
            return a.t > b.t;
        return a.tp > b.tp;
    }
};

int pos[N];

const llong inf = (llong)(1.1e18);

int Tcnt[2 * N];
llong Tsum[2 * N];

inline llong add(llong a, llong b) {
    if ((a += b) >= inf)
        return inf;
    else
        return a;
}

void add(int i) {
    llong ad = W[i] - T[i] + 1;
    i = pos[i] + N;
    while (i >= 1) {
        Tcnt[i]++;
        Tsum[i] = add(Tsum[i], ad);
        i >>= 1;
    }
}

int num(llong rem, int v = 1) {
    assert(rem >= 0);
    assert(Tsum[v] > rem);
    if (v >= N) {
        return 0;
    }
    if (Tsum[2 * v] <= rem) {
        return Tcnt[2 * v] + num(rem - Tsum[2 * v], 2 * v + 1);
    } else {
        return num(rem, 2 * v);
    }
}

struct team {
    int id;
    llong wt;
    team(int _id, llong _wt) {
        id = _id;
        wt = _wt;
    }
    friend bool operator <(team a, team b) {
        return a.wt < b.wt;
    }
    team(){}
} teams[N];

int main() {
    int n;
    scanf("%d", &n);
    llong t0, w0;
    scanf("%lld %lld", &t0, &w0);
    int tpt = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld %lld", &T[i], &W[i]);
        Ts[tpt++] = T[i];
        teams[i] = team(i, W[i] - T[i] + 1);
    }
    Ts[tpt++] = t0;
    Ts[tpt++] = 0;
    sort(Ts, Ts + tpt);
    tpt = unique(Ts, Ts + tpt) - Ts;
    vector<ev> E;
    for (int i = 0; i < tpt; i++) {
        E.emplace_back(Ts[i], 2);
    }
    for (int i = 0; i < n - 1; i++) {
        E.emplace_back(T[i], 1, i);
    }
    sort(E.begin(), E.end());
    sort(teams, teams + n - 1);
    for (int i = 0; i < n - 1; i++) {
        pos[teams[i].id] = i;
    }

    int ans = N + 1;
    int cnt_better = 0;
    for (int i = 0; i < (int)E.size(); i++) {
        if (E[i].tp == 1) {
            add(E[i].id);
            cnt_better++;
        } else {
            llong t = E[i].t;
            if (t <= t0) {
                llong rem = t0 - t;
                int got = 0;
                if (Tsum[1] <= rem) {
                    got = Tcnt[1];
                } else {
                    got = num(rem);
                }
                ans = min(ans, cnt_better - got + 1);
            }
        }
    }
    printf("%d\n", ans);
}