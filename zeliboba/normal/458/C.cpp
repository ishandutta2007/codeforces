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
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

void out(vi v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << ' ';
    cerr << endl;
}

int main() {
    int n;
    cin >> n;
    vvl c(100001);
    vvl s(100001);
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        c[a].push_back(b);
    }
    if (c[0].empty()) {
        c[0].push_back(0);
        ++n;
        for (int i = 1; i < c.size(); ++i) if (!c[i].empty()) {
            c[i].push_back((ll)2e9);
            ++n;
        }
    }
    vector<pair<int, vl> > ts(c.size() - 1);
    for (int i = 1; i < c.size(); ++i) {
        ts[i-1] = make_pair((int)c[i].size(), c[i]);
    }
    sort(ts.rbegin(), ts.rend());
    int cur = c[0].size();
    ll curres = 0;
    int buy = 0;
    multiset<ll> cheap;
    vi it(c.size());
    for (int i = 1; i < c.size(); ++i) {
        c[i] = ts[i-1].second;
        if (c[i].empty()) break;
        sort(c[i].begin(), c[i].end());
//        out(c[i]);
        s[i].resize(c[i].size() + 1);
        for (int j = 0; j < c[i].size(); ++j)
            s[i][j+1] = s[i][j] + c[i][j];
        if (c[i].size() >= cur) {
            it[i] = c[i].size() - cur + 1;
            curres += s[i][it[i]];
            buy += it[i];
        }
        for (int j = it[i]; j < c[i].size(); ++j) cheap.insert(c[i][j]);
//        cerr << i << ' ' << it[i] << endl;
    }
    ll res = curres;
    multiset<ll> taken;
    for (; cur < n; ++cur) {
//        cerr << cur + 1 << ' ' << buy << ' ' << curres << endl;
        for (int i = 1; i < c.size(); ++i) {
            if (it[i] == 0) break;
            --it[i];
            curres -= c[i][it[i]];
//            cerr << c[i][it[i]] << endl;
            cheap.insert(c[i][it[i]]);
            --buy;
        }
//        cerr << cur + 1 << ' ' << curres << endl;
        while (!taken.empty() && !cheap.empty()) {
            auto b = cheap.begin();
            auto e = taken.end();
            --e;
            ll ma = *e, mi = *b;
            if (ma > mi) {
                cheap.erase(b);
                taken.erase(e);
                cheap.insert(ma);
                taken.insert(mi);
                curres -= ma-mi;
            } else break;
        }
//        cerr << cur + 1 << ' ' << curres << endl;
        while (buy + c[0].size() <= cur) {
//            assert(!cheap.empty());
            ++buy;
            auto b = cheap.begin();
            curres += *b;
            taken.insert(*b);
            cheap.erase(b);
        }
        res = min(res, curres);
    }
    cout << res << endl;
    return 0;
}