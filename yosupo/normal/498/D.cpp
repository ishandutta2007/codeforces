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

using namespace std;
typedef long long ll;

template <int S>
struct StarrySkyTree {
    typedef int D;
    static const int N = 1<<S;
    D seg[2*N][60];
    int sz[2*N];

    void init(int a[]) {
        for (int i = 2*N-1; i >= N; i--) {
            setdata(i, a[i-N]);
        }
        for (int i = N-1; i >= 0; i--) {
            update(i);
        }
        for (int i = 2*N-1; i >= N; i--) {
            sz[i] = 1;
        }
        for (int i = N-1; i >= 1; i--) {
            sz[i] = sz[i*2]+sz[i*2+1];
        }
    }
    void setdata(int k, D x) {
        for (int i = 0; i < 60; i++) {
            seg[k][i] = (i % x == 0) ? 2 : 1;
        }
    }
    void update(int k) {
        for (int i = 0; i < 60; i++) {
            seg[k][i] = seg[k*2][i]+seg[k*2+1][(i+seg[k*2][i])%60];
        }
    }
    void set(int k, D x) {
        k += N;
        setdata(k, x);
        while (k >= 2) {
            k /= 2;
            update(k);
        }
    }
    D get(int a, int b, int x, int k = 1) {
        //printf("get %d %d %d\n", a, b, x);
        if (sz[k] <= a || b <= 0) return 0;
        if (a <= 0 && sz[k] <= b) return seg[k][x];
        D dl = get(a, b, x, k*2);
        D dr = get(a-sz[k]/2, b-sz[k]/2, (x+dl)%60, k*2+1);
        return dl+dr;
    }
};

const int MS = 17;
const int MN = 1<<MS;
StarrySkyTree<MS> st;
int a[MN];
int main() {
    int n;
    cin >> n;
    fill_n(a, MN, 6);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    st.init(a);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char t;
        int x, y;
        scanf(" %c %d %d", &t, &x, &y);
        if (t == 'A') {
            x--; y--;
            printf("%d\n", st.get(x, y, 0));
        } else {
            x--;
            st.set(x, y);
        }
    }
}