#define ENABLE_LL
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef ENABLE_LL
#define int long long
#endif

#ifdef ENABLE_LL
#define I "%lld"
#define II "%lld%lld"
#define III "%lld%lld%lld"
#define IIII "%lld%lld%lld%lld"
#define IN "%lld\n"
#define IIN "%lld%lld\n"
#define IIIN "%lld%lld%lld\n"
#define IIIIN "%lld%lld%lld%lld\n"
#else
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define IIII "%d%d%d%d"
#define IN "%d\n"
#define IIN "%d%d\n"
#define IIIN "%d%d%d\n"
#define IIIIN "%d%d%d%d\n"
#endif

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#define ses(a) std::cout << #a << "=" << a << " " 
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#define ses(a)
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
#define repb(i,a,b) for (int i=a;i>=b;i--)
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
template <class T> inline bool checkMin(T& a , T b) { return (a > b ? a=b,1 : 0); }
template <class T> inline bool checkMax(T& a , T b) { return (a < b ? a=b,1 : 0); }

const int N = 200005;

struct FTree{
    int e[N];

    inline int lowbit(int x) { return x & (-x); }

    void modify(int u, int c) {
        u += 5;
        while (u < N) {
            e[u] += c;
            u += lowbit(u);
        }
    }

    int query(int u) {
        u += 5;
        int ans = 0;
        while (u) {
            ans += e[u];
            u -= lowbit(u);
        }
        return ans;
    }
};

FTree st;
int a[N];
int p[N];
int n;

void init() {
    scanf(I,&n);
    repa (i,n) scanf(I,&a[i]);
    repa (i,n) st.modify(i, i);
}

void solve() {
    repb (i,n,1) {
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            ses(m);see(st.query(m));
            if (st.query(m) > a[i]) r = m - 1;
            else l = m;
        }
        p[i] = l + 1;
        st.modify(l + 1, -l - 1);
    }
    repa (i,n) printf("%lld ",p[i]);
    puts("");
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}