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

char buf[1000005];

void out (vii v) {
    for (int i = 0; i < v.size(); ++i)
        cout << v[i].first << "-" << v[i].second << " ";
    cout << endl;
}

int main() {
    int n, m;
    scanf("%d", &n);
    vector<vvi> sc(n, vvi(26));
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        int l = strlen(buf);
        for (int it = 0; it < l; ++it)
            sc[i][buf[it] - 'a'].push_back(it);
    }
    scanf("%d", &m);
    vi ind(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &ind[i]);
        --ind[i];
    }
    vvi fsc(26, vi(m + 1));
    for (int i = 0; i < 26; ++i) for (int j = m; j >= 0; --j) {
        if (j == m || !sc[ind[j]][i].empty())
            fsc[i][j] = j;
        else fsc[i][j] = fsc[i][j + 1];
    }
    char s[2005];
    scanf("%s", s);
    int l = strlen(s);
    vii res(l + 1, pii(m, 0));
    res[0] = pii(0, -1);
    for (int i = 0; i < l; ++i) {
        int a = s[i] - 'a';
        for (int len = l - 1; len >= 0; --len) if (res[len].first < m) {
            int cur = res[len].first;
            vi & tf = sc[ind[cur]][a];
            int it = lower_bound(tf.begin(), tf.end(), res[len].second + 1) - tf.begin();
            if (it < tf.size()) {
                res[len + 1] = min(res[len + 1], pii(cur, tf[it]));
            } else {
                cur = fsc[a][cur + 1];
                if (cur < m) {
                    vi & tf1 = sc[ind[cur]][a];
                    int it = lower_bound(tf1.begin(), tf1.end(), 0) - tf1.begin();
                    if (it < tf1.size()) {
                        res[len + 1] = min(res[len + 1], pii(cur, tf1[it]));
                    }
                }
            }
        }
//        out(res);
    }
    for (int i = l; i >= 0; --i) if (res[i].first < m) {
        cout << i << endl;
        break;
    }
    return 0;
}