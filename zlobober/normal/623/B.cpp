#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1000500;

int A[N];

typedef long long llong;

inline int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

set<int> all[2];
set<int> cur;
set<int> nxt;

const llong inf = 1e16;

int main() {
    int n;
    llong a, b;
    scanf("%d", &n);
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]); 
    }
    for (int it = 0; it < 2; it++) {
        cur.clear();    
        cur.insert(0);
        nxt.clear();
        for (int i = 0; i < n; i++) {
            int x = A[i];
            for (int c : cur) {
                for (int dx = -1; dx <= 1; dx++) {
                    int g = gcd(x + dx, c);
                    if (g != 1)
                        nxt.insert(g);
                }
            }
            cur.swap(nxt);
            nxt.clear();
            for (int c : cur)
                all[it].insert(c);
        }
        reverse(A, A + n);
    }
    eprintf("%d %d\n", (int)all[0].size(), (int)all[1].size());
    set<int> aall;
    for (int x : all[0]) {
        aall.insert(x);
        for (int y : all[1]) {
            aall.insert(y);
            int g = gcd(x, y);
            if (g != 1)
                aall.insert(g);
        }
    }
    aall.erase(0);

    llong bans = inf;

    vector<llong> cost(n);
    for (int g : aall) {
        cost.resize(n);
        int linf = n, rinf = -1;
        for (int i = 0; i < n; i++) {
            cost[i] = inf;
            for (int dx = -1; dx <= 1; dx++)
                if ((A[i] + dx) % g == 0)
                    cost[i] = min(cost[i], (llong)abs(dx) * b);
            if (cost[i] == inf)
                linf = min(linf, i), rinf = max(rinf, i);
        }
        llong tmp;
        for (int iter = 0; iter < 2; iter++) {
            if (iter == 0) {
                tmp = cost.back();
                cost.pop_back();
                --n;
            }
            if ((iter == 0 && rinf != n + 1 - 1) || (iter == 1 && linf != -1)) {
                if (linf > rinf) {
                    llong tot = accumulate(cost.begin(), cost.end(), 0ll);
                    llong mn = 0;
                    llong cur_sum = 0;
                    llong ans = tot;
                    for (int i = 0; i < n; i++) {
                        cur_sum += cost[i] - a;
                        mn = min(mn, cur_sum);
                        llong best = cur_sum - mn;
                        ans = min(ans, tot - best);
                    }
                    bans = min(bans, ans + tmp);
                } else {
                    llong ansl = accumulate(cost.begin(), cost.begin() + linf, 0ll);
                    llong ansr = accumulate(cost.begin() + rinf + 1, cost.end(), 0ll);
                    llong tot = (rinf - linf + 1) * a + ansl + ansr;
                    llong mn = 0;
                    llong cur_sum = 0;
                    for (int i = 0; i < linf; i++) {
                        cur_sum += cost[i] - a;
                        mn = min(mn, cur_sum);
                        if (i == linf - 1) {
                            llong best = cur_sum - mn;
                            ansl = min(ansl, ansl - best);
                        }
                    }
                    mn = 0;
                    cur_sum = 0;
                    for (int i = n - 1; i > rinf; i--) {
                        cur_sum += cost[i] - a;
                        mn = min(mn, cur_sum);
                        if (i == rinf + 1) {
                            llong best = cur_sum - mn;
                            ansr = min(ansr, ansr - best);
                        }
                    }
                    tot = min(tot, (rinf - linf + 1) * a + ansl + ansr);
                    bans = min(bans, tot + tmp);
                }
            }
            if (iter == 0) {
                cost.push_back(tmp);
                tmp = cost.front();
                cost.erase(cost.begin());
                linf--;
                rinf--;
            }
            if (iter == 1) {
                n++;
            }
        }
    }
    cout << bans << endl;
}