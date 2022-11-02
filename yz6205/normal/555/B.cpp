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

#define int long long
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

const int N = 200005;
pr il[N];
pr b[N];
int n,m;

void init() {
    scanf("%lld%lld",&n,&m);
    rep (i,n) scanf("%lld%lld",&il[i].L , &il[i].R);
    rep (i,m) scanf("%lld",&b[i].L);
    rep (i,m) b[i].R = i;
    sort (b , b + m);
}

void noAns() {
    puts("No");
    exit (0);
}

prr nd[N];
int ans[N];
void solve() {
    n--;
    rep (i,n) {
        int s = il[i + 1].L - il[i].R;
        int l = il[i + 1].R - il[i].L;
        if (s > b[m - 1].L || l < b[0].L) noAns();
        nd[i].L.R = lower_bound(b , b + m , pr(s,0)) - b;
        nd[i].L.L = upper_bound(b , b + m , pr(l,N)) - b - 1;
        nd[i].R = i;
    }
    sort (nd , nd + n);
    set < pr > st;
    rep (i,m) st.insert(b[i]);
    rep (i,n) {
        int le = b[ nd[i].L.R ].L;
        set < pr > :: iterator it = st.lower_bound( pr(le,0) );
        if (it->L > b[ nd[i].L.L ].L) noAns();
        ans [nd[i].R] = it->R;
        st.erase(it);
    }
    puts("Yes");
    rep (i,n) printf("%lld ",ans[i] + 1);
    puts("");
}

#undef int
int main(){
    init();
    solve(); 
    return 0;
}