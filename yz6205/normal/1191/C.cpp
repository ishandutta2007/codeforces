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

#define int long long
const int N = 100005;
int p[N];
int n,m,k;

void init(){
    scanf("%lld%lld%lld",&n,&m,&k);
    rep (i,m) scanf("%lld",&p[i]);
    p[m] = (int)2e18;
}

void solve() {
    int del = 0;
    int fst = 0;
    int ans = 0;
    while (fst < m) {
        int lst = ( (p[fst] - del + k - 1) / k ) * k + del;
        int lsti = upper_bound(p , p + m + 1 , lst) - p;
        see(del);
        see(fst);
        see(lst);
        see(lsti);
        see("-------------");
        ans ++;
        del += lsti - fst;
        fst = lsti;
    }
    printf("%lld\n",ans);
}

#undef int
int main(){
    init();
    solve();
    return 0;
}