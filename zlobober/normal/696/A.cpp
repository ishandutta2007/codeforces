#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


typedef long long llong;

map<llong, llong> M;


vector<llong> fromRoot(llong x) {
    vector<llong> ans;
    while (x > 0) {
        ans.push_back(x);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        llong u, v, w;
        if (t == 1) {
            scanf("%lld %lld %lld", &u, &v, &w);
        } else {
            scanf("%lld %lld", &u, &v);
        }
        auto pu = fromRoot(u);
        auto pv = fromRoot(v);
        int c = 0;
        while (c < (int)pu.size() && c < (int)pv.size() && pu[c] == pv[c])
            c++;
        if (t == 1) {
            for (int i = c; i < (int)pu.size(); i++)
                M[pu[i]] += w;
            for (int i = c; i < (int)pv.size(); i++)
                M[pv[i]] += w;
        } else {
            llong ans = 0;
            for (int i = c; i < (int)pu.size(); i++)
                ans += M[pu[i]];
            for (int i = c; i < (int)pv.size(); i++)
                ans += M[pv[i]];
            printf("%lld\n", ans);
        }
    }
}