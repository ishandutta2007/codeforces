#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>
#include <deque>
using namespace std;

typedef long long ll;

struct Pi {
    int x, y;
    Pi() {}
    Pi(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator<(const Pi &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator>(const Pi &r) const {
        if (x != r.x) return x > r.x;
        return y > r.y;
    }
};

struct Ti {
    int x, y, z;
    Ti() {}
    Ti(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
};
const int MN = 121000;
const int BS = 290;
const int BN = MN/BS;
deque<int> d[BN];
int h[BN][MN];

void rot(int l, int r) {
    if (l == r) return;
    int lb = l/BS, rb = r/BS;
    int u = d[rb][r%BS];
    h[rb][u]--;
    h[lb][u]++;
    d[rb].erase(d[rb].begin()+(r%BS));
    d[lb].insert(d[lb].begin()+(l%BS), u);
    for (int i = lb; i < rb; i++) {
        int u = d[i].back();
        h[i][u]--;
        h[i+1][u]++;
        d[i].pop_back();
        d[i+1].push_front(u); 
    }    
}

int cal(int l, int r, int k) {
    int lb = l/BS, rb = r/BS;
    if (lb == rb) {
        int res = 0;
        for (int i = l%BS; i <= r%BS; i++) {
            if (d[lb][i] == k) res++;
        }
        return res;
    }
    int res = 0;
    while (l%BS != 0) {
        if (d[l/BS][l%BS] == k) res++;
        l++;
    }
    while (r%BS != BS-1) {
        if (d[r/BS][r%BS] == k) res++;
        r--;
    }
    for (int i = l/BS; i < (r+1)/BS; i++) {
        res += h[i][k];
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        int b = i/BS;
        d[b].push_back(a);
        h[b][a]++;
    }
    int q;
    cin >> q;
    int la = 0;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r;
            scanf("%d %d", &l, &r); l--; r--;
            l = (l+la)%n; r = (r+la)%n;
            if (l > r) swap(l, r);
            rot(l, r);
        } else {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k); l--; r--;
            l = (l+la)%n; r = (r+la)%n; k = (k+la-1)%n+1;
            if (l > r) swap(l, r);
            la = cal(l, r, k);
            printf("%d\n", la);
        }
    }
    return 0;
}