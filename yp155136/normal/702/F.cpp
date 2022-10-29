#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define F first
#define S second
const int N = 200006;
const int P = 31;

int a[P][N];
int a_level[N];
int w[N];
int tmp[N];
int level[N];
int ans[N];
vector<int> qs[P][N];

int get_level(int x) {
    int ret = 0;
    while (x) {
        ++ret;
        x >>= 1;
    }
    return ret - 1;
}

int main () {
    int n; scanf("%d", &n);
    vector<pii> v;
    for (int i = 1; i <= n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        v.push_back({-y, x});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i) {
        int val = v[i - 1].S;
        int l = get_level(val);
        a_level[i] = l;
        for (int j = l; j < P; ++j) {
            a[j][i] = val;
        }
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &w[i]);
        level[i] = get_level(w[i]);
        qs[ level[i] ][1].push_back(i);
    }
    for (int i = P - 1; i >= 0; --i) {
        ll tag = 0;
        int pre = 0;
        set<pii> st;
        for (int j = 1; j <= n; ++j) {
            for (int qid: qs[i][j]) {
                st.insert({w[qid] + tag, qid});
                tmp[qid] = pre;
            }
            if (a_level[j] > i) continue;
            else if (a_level[j] == i) {
                while (!st.empty() && (*prev(st.end())).F - tag >= a[i][j]) {
                    pii p = *(prev(st.end()));
                    st.erase(*prev(st.end()));
                    int qid = p.S;
                    ans[qid] += pre - tmp[qid] + 1;
                    w[qid] = p.F - tag - a[i][j];
                    level[qid] = get_level(w[qid]);
                    if (w[qid] == 0) {
                        continue;
                    }
                    qs[ level[qid] ][j + 1].push_back(qid);
                }
            }
            else {
                ++pre;
                tag += a[i][j];
                while (!st.empty() && st.begin()->F - tag < (1 << i)) {
                    pii p = *st.begin();
                    st.erase(st.begin());
                    int qid = p.S;
                    ans[qid] += pre - tmp[qid];
                    w[qid] = p.F - tag;
                    level[qid] = get_level(w[qid]);
                    qs[ level[qid] ][j + 1].push_back(qid);
                }
            }
        }
        for (pii p: st) {
            int qid = p.S;
            ans[qid] += pre - tmp[qid];
        }
    }
    for (int i = 1; i <= q; ++i) {
        printf("%d%c", ans[i], " \n"[i == q]);
    }
}