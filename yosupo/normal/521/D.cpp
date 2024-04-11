//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>
#include <cstdio>

using namespace std;
typedef long long ll;
typedef long double D;
const int MK = 100100;

typedef pair<ll, int> P;
typedef pair<D, int> PD;

int k, n, m;

int muln;
vector<P> mul;
D mulsum[MK];
void mulcalc() {
    mulsum[0] = 0;
    for (int i = 0; i < muln; i++) {
        mulsum[i+1] = mulsum[i] + mul[i].first;
    }
}

ll d[MK];
int addn;
vector<P> add[MK];
int addc[MK];
vector<PD> addres;
D addsum[MK];
void addcalc() {
    priority_queue<PD> q;
    for (int i = 0; i < k; i++) {
        if (add[i].size()) {
            q.push(PD( (D)(add[i][0].first+d[i]) / d[i], i ));
        }
    }    
    addsum[0] = 0;
    for (int i = 0; i < addn; i++) {
        D x; int p;
        tie(x, p) = q.top(); q.pop();
        P ap = add[p][addc[p]];
        addc[p]++;
        addres.push_back(PD(x, ap.second));
        d[p] += ap.first;
        if (addc[p] == (int)add[p].size()) continue;
        q.push(PD( (D)(add[p][addc[p]].first + d[p]) / d[p], p));
    }
    addsum[0] = 0;
    for (int i = 0; i < addn; i++) {
        addsum[i+1] = addsum[i] + addres[i].first;
    }
}

vector<int> res;
void solve() {
    addcalc();
    mulcalc();
    D r = -1;
    int ri = -1;
    for (int i = max(0, m-muln); i <= min(m, addn); i++) {
        if (r < addsum[i]+mulsum[m-i]) {
            r = addsum[i]+mulsum[m-i];
            ri = i;
        }
    }
    for (int i = 0; i < ri; i++) {
        res.push_back(addres[i].second);
    }
    for (int i = 0; i < m-ri; i++) {
        res.push_back(mul[i].second);
    }
}

P as[MK];
int type[MK];
int main() {
    fill_n(as, MK, P(-1, -1));
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < k; i++) {
        int dd;
        scanf("%d", &dd);
        d[i] = dd;
    }
    for (int i = 0; i < n; i++) {
        int pp, bb;
        scanf("%d %d %d", type+i, &pp, &bb); pp--;
        ll t = type[i], p = pp, b = bb;
        if (t == 1) {
            as[p] = max(as[p], P(b, i));
        } else if (t == 2) {
            add[p].push_back(P(b, i));
        } else {
            mul.push_back(P(b, i));
        }
    }
    for (int i = 0; i < k; i++) {
        if (as[i].first <= d[i]) continue;
        as[i].first -= d[i];
        add[i].push_back(as[i]);
    }
    n = 0;
    muln = mul.size();
    n += muln;
    sort(mul.begin(), mul.end(), greater<P>());
    for (int i = 0; i < k; i++) {
        addn += add[i].size();
        n += add[i].size();
        sort(add[i].begin(), add[i].end(), greater<P>());
    }
    m = min(m, n);
    solve();
    printf("%d\n", (int)res.size());
    vector<P> v;
    for (int d: res) {
        v.push_back(P(type[d], d+1));
    }
    sort(v.begin(), v.end());
    for (P d: v) {
        printf("%d ", d.second);
    }
    printf("\n");
    return 0;
}