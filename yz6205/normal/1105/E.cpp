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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second
 
const int N = 100005;
int n , m;
int ty[N] ;
string id[N];
int cnt;
 
map < string , int > mp;
void init() {
    scanf(II,&n,&m);
    rep (i,n) {
        scanf(I,&ty[i]);
        if (ty[i] == 2) {
            cin >> id[i];
            if (!mp.count(id[i])) mp[ id[i] ] = cnt++;
        }
    }
}
 
int mask[N];
int noBoth[N];
int idx[N];
void solve() {
    vector < int > pr;
    rep (i,n) if (ty[i] == 1) pr.push_back(i);
    pr.push_back(n);
    rep (i,(int)pr.size() - 1) for (int j = pr[i] + 1;j < pr[i + 1];j++) mask[i] |= (1LL << mp[id[j]]);
    rep (i,(int)pr.size() - 1) rep (j,m) if (mask[i] >> j & 1LL) noBoth[j] |= mask[i];
    rep (i,m) idx[i] = i;
    int times = 0.5e4;
    int ans = 0;
    while (times--) {
        int pmark = 0 , pans = 0;
        random_shuffle(idx , idx + m);
        rep (i,m) {
            if ( ( (pmark >> idx[i]) & 1LL) == 0 ) {
                pans ++;
                pmark |= noBoth[ idx[i] ];
            }
        } 
        ans = max(ans , pans);
    }
    printf(IN,ans);
}
 
 
#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}