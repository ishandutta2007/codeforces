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

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 500005;
pr p[N];
int n;

void init(){
    scanf("%d",&n);
    rep (i,n) scanf("%d%d",&p[i].L , &p[i].R);
}

vector < int > pt[N];

struct Fwt{
    int o[N + 100];
    int a[N + 100];

    Fwt() {
        memset(o , 0 ,sizeof(o));
        memset(a , 0 ,sizeof(a));
    }

    int lowbit(int x) { return x & (-x); }

    void modify(int p , int x) {
        p += 2;
        if (o[p]) return;
        o[p] = 1;
        for (;p<=N + 10;p += lowbit(p)) a[p] += x;
    }

    int query(int p) {
        p += 2;
        int res = 0;
        for (;p>0;p -= lowbit(p)) res += a[p];
        return res;
    }
};

inline long long calc (long long x) {
    return x * (x + 1) / 2;
}

void solve() {
    vector < int > ls;
    rep (i,n) {
        ls.push_back(p[i].L);
        ls.push_back(p[i].R);
    }
    sort(ls.begin() , ls.end()) ;
    rep (i,n) {
        p[i].L = lower_bound(ls.begin() , ls.end() , p[i].L) - ls.begin() + 1;
        p[i].R = lower_bound(ls.begin() , ls.end() , p[i].R) - ls.begin() + 1;
    }

    rep (i,n) pt[ p[i].R ].push_back( p[i].L );
    rep (i,N) sort (pt[i].begin() , pt[i].end()) ;

    Fwt st;

    long long ans = 0;
    for (int i = N - 1;i >= 0;i--) {
        if (pt[i].size() == 0) continue;
        foreach(j,pt[i]) st.modify(pt[i][j] , 1);
        see(st.query(N));
        ans += calc( st.query(N) );
        see(ans);
        repa (j,(int)(pt[i].size()) - 1) ans -= calc( st.query(pt[i][j] - 1) - st.query(pt[i][j - 1]) );
        ans -= calc( st.query(pt[i][0] - 1) );
        see(ans);
        ans -= calc( st.query(N) - st.query( pt[i][ (int)(pt[i].size()) - 1]) );
        see(ans);
    }
    printf("%lld\n",ans);
}

int main(){
    init();
    solve();
    return 0;
}