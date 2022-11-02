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

const int N = 300005;
int s[N] , t[N];
pr st[N];
int n;

void init(){
    scanf("%lld",&n);
    rep (i,n) scanf("%lld",&s[i]);
    rep (i,n) scanf("%lld",&t[i]);
    rep (i,n) st[i] = pr(s[i] , i + 1);
    sort (st , st + n);
    sort (t  , t  + n);
    int ts = 0 , tt = 0;
    rep (i,n) ts += st[i].L;
    rep (i,n) tt += t[i];
    if (ts != tt) {
        puts("NO");
        exit(0);
    }
}

#undef int
int main(){
#define int long long
    init();
    vector < prr > ans;
    vector < pr > fw , bw;
    vector < int > fi , bi;
    rep (i,n) {
        if (st[i].L < t[i]) fw.push_back(st[i]) , fi.push_back(i);
        if (st[i].L > t[i]) bw.push_back(st[i]) , bi.push_back(i);
    }
    int l = 0 , r = 0;
    while (l < (int)fw.size() && r < (int)bw.size()) {
        int mf = t[fi[l]] - fw[l].L;
        int mb = bw[r].L - t[bi[r]];
        int mv = min(mf , mb);
        see(l);
        see(r);
        see(fw[l].L);
        see(bw[r].L);
        see(mv);
        if (mv * 2 > bw[r].L - fw[l].L) {
            puts("NO");
            exit(0);
        }
        ans.push_back( prr(  pr(fw[l].R , bw[r].R)  ,  mv) );
        fw[l].L += mv;
        bw[r].L -= mv;
        if (mf == mv) l++;
        if (mb == mv) r++;
    }
    puts("YES");
    printf("%lld\n",(int)ans.size());
    rep (i,(int)ans.size()) printf("%lld %lld %lld\n",ans[i].L.L , ans[i].L.R , ans[i].R);
    return 0;
}