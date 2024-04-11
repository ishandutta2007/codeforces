#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int t1[400000];
int t2[400000];

void build (const vi &a, int v, int tl, int tr, int t[]) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm, t);
		build (a, v*2+1, tm+1, tr, t);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r, int t[]) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm), t)
		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r, t);
}

void update (int v, int tl, int tr, int pos, int new_val, int t[]) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val, t);
		else
			update (v*2+1, tm+1, tr, pos, new_val, t);
		t[v] = t[v*2] + t[v*2+1];
	}
}

ll solve(ll n, ll k, vii a) {
    sort(a.begin(), a.end());
    vi v(n);
    int cur = 0;
    v[a[0].second] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first != a[i - 1].first)
            ++cur;
        v[a[i].second] = cur;
    }
    vi was(n + 1, 0);
    vi was_b(n + 1, 0);
    build(was_b, 1, 0, n, t2);
    build(was, 1, 0, n, t1);
    ll cursum = 0;
    for (int i = n - 1; i >= 1; --i) {
        ++was[v[i]];
        update(1, 0, n, v[i], was[v[i]], t1);
        cursum += sum(1, 0, n, 0, v[i] - 1, t1);
    }
//    cerr << cursum << endl;
    ll res = 0;
    cur = 1;
//    cerr << "here\n";
    for (int i = 0; i + 1 < n; ++i) {
        was_b[v[i]]++;
        update(1, 0, n, v[i], was_b[v[i]], t2);
        cursum += sum(1, 0, n, 0, v[i] - 1, t1);
        cursum += sum(1, 0, n, v[i] + 1, n, t2);
//        cerr << cur << " " << cursum << " " << v[i] << endl;
        while ((cursum > k || cur == i) && cur < n) {
            was[v[cur]]--;
            update(1, 0, n, v[cur], was[v[cur]], t1);
            cursum -= sum(1, 0, n, v[cur] + 1, n, t2);
            cursum -= sum(1, 0, n, 0, v[cur] - 1, t1);
            ++cur;
        }
        if (cur >= n)
            break;
        res += n - cur;
//        cerr << res << endl;
    }
    return res;
}

ll solve_stress(int n, int k, vii a) {
    int res = 0;
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        int cnt = 0;
        vi b;
        for (int i1 = 0; i1 <= i; ++i1)
            b.push_back(a[i].first);
        for (int j1 = j; j1 < n; ++j1)
            b.push_back(a[j].first);
        for (int l = 0; l < b.size(); ++l) for (int l1 = l + 1; l1 < b.size(); ++l1) if (b[l] > b[l1])
            ++cnt;
        if (cnt <= k)
            ++res;
    }
    return res;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vii a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    cout << solve(n, k, a) << endl;
    return 0;
}