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
int r[N];
int c[N];
int n,m;

void init() {
    scanf(II,&n,&m);
    rep (i,n) scanf(I,&r[i]);
    rep (i,n) scanf(I,&c[i]);
}

void solve() {
    set < pr > st;
    rep (i,n) st.insert( pr(c[i] , i) );
    rep (i,m) {
        int cn , cv; scanf(II,&cn,&cv); cn--;
        int ans = 0;
        int ch = min(cv , r[cn]);
        ans += ch * c[cn];
        cv -= ch; r[cn] -= ch; 
        if (r[cn] == 0) st.erase( pr(c[cn] , cn) );
        while (cv && !st.empty()) {
            int cid = st.begin()->R;
            int cnm = min(r[cid] , cv);
            ses(ans);ses(cid);see(cnm);
            cv -= cnm ; r[cid] -= cnm ;
            ans += cnm * c[cid];
            if (r[cid] == 0) st.erase( pr(c[cid] , cid) );
        }
        printf(IN,cv == 0 ? ans : 0);
    }
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}