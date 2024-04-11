#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 100100;
const int INF = TEN(9)+TEN(8);
int n;
ll ans[MN];
multiset<int> st, ed;
ll gc = 0;
void calc(ll kei) {
    int sn = (int)st.size();
    int en = (int)ed.size();
    gc += sn+en;
    int si = 0, ei = 0;
    int nc = 0, ba = -INF;
    auto sit = st.begin(), eit = ed.begin();
    while (sit != st.end() or eit != ed.end()) {
        int sx = (sit == st.end()) ? INF : *sit;
        int ex = (eit == ed.end()) ? INF : *eit;
        ans[nc] += kei*(min(sx, ex)-ba);
        ba = min(sx, ex);
        if (sx <= ex) {
            nc++; sit++;
        } else {
            nc--; eit++;
        }
    }
}


using T = tuple<int, int, int>;
int x[MN];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<T> ev;
    for (int i = 0; i < n; i++) {
        int y;
        scanf("%d %d", x+i, &y);
        ev.push_back(T(y, i, 0));
        ev.push_back(T(y+k, i, 1));
    }
    sort(ev.begin(), ev.end());
    int m = (int)ev.size();
    int ba = -INF;
    for (T e: ev) {
        int ny, id, ty;
        tie(ny, id, ty) = e;
        if (ba != -INF and ny != ba) {
            calc(ny-ba);
        }
        ba = ny;
        if (ty == 0) {
            st.insert(x[id]);
            ed.insert(x[id]+k);
        } else {
            st.erase(st.find(x[id]));
            ed.erase(ed.find(x[id]+k));
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
    return 0;
}