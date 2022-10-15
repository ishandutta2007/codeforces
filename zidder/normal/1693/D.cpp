#include <bits/stdc++.h>

using namespace std;

const int N = 200002;
struct A {
    int L;
    set<pair<int, int> > vals; // (val, l)
    multiset<int> ls;

    int ST[4*N+10];

    A(){
        for (int i=0;i<4*N;++i) ST[i] = N;
    }

    int get_l() {
        return *ls.begin();
    }

    void insrt(int val, int lf, int l=0, int r=N, int v=1){
        ST[v] = min(ST[v], lf);
        if (l + 1 == r) {
            return;
        }
        int m = (l + r) / 2;
        if (val < m) insrt(val, lf, l, m, 2*v);
        else insrt(val, lf, m, r, 2*v+1);
    }

    void clr(int l=0, int r=N, int v=1) {
        if (ST[v] == N) return;
        ST[v] = N;
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        clr(l, m, 2*v);
        clr(m, r, 2*v+1);
    }

    int get_range_min(int ql, int qr, int l=0, int r=N, int v=1) {
        if (l >= qr || r <= ql) return N;
        if (ql <= l && r <= qr) return ST[v];
        int m = (l + r) / 2;
        return min(get_range_min(ql, qr, l, m, 2*v), get_range_min(ql, qr, m, r, 2*v+1));
    }

    void insert(const int v, const int l) {
        vals.emplace(v, l);
        ls.insert(l);
        insrt(v, l);
    }

    void insert(const pair<int, int>& p){
        insert(p.first, p.second);
    }

    int low(int v) {
        return min(L, get_range_min(0, v));
        int l = L;
        for (auto &p: vals) if (p.first < v) l = min(l, p.second);
        return l;
    }

    int high(int v) {
        return min(L, get_range_min(v+1, N));
        int l = L;
        for (auto &p: vals) if (p.first > v) l = min(l, p.second);
        return l;
    }

    void clear() {
        clr();
        ls.clear();
        vals.clear();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i: p) scanf("%d", &i);
    vector<int> l(n, n);
    A pick, rem;
    pick.insert(-1, 0);
    rem.insert(-1, 0);
    l[0] = 0;
    pick.L = rem.L = 0;
    for (int i=1;i<n;++i) {
        l[i] = i;
        // rem rem
        if (p[i] < p[i-1]) {
            l[i] = min(l[i], rem.get_l());
        }
        // pick pick
        if (p[i] > p[i-1]) {
            l[i] = min(l[i], pick.get_l());
        }
        // rem pick
        int l1 = rem.low(p[i]);
        // pick rem
        int l2 = pick.high(p[i]);

        l[i] = min(l[i], min(l1, l2));

        if (p[i] < p[i-1]) {
            pick.clear();
            pick.L = i;
        } else {
            rem.clear();
            rem.L = i;
        }
        pick.insert(p[i-1], l1);
        rem.insert(p[i-1], l2);
    }

    long long ans = 0;
    for (int i=n-1;i>=0;--i) {
        ans += (i - l[i] + 1);
    }
    cout << ans << endl;
    return 0;
}