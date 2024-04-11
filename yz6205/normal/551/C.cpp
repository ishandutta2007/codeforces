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
typedef pair < int , int > Point;

const int N = 100005;
vector < int > a;
int n , m;

void init(){
    scanf("%lld%lld",&n,&m);
    a.resize(n);
    rep (i,n) scanf("%lld",&a[i]);
    while (a[n - 1] == 0) { a.pop_back() ; --n ; }
}

bool jury(int t) {
    see(t);
    vector < int > c = a;
    rep (i,m) {
        int le = t - (int)c.size();
        while (c.size() && (le > 0)) {
            int disc = min(le , c[c.size() - 1]);
            le -= disc;
            c[c.size() - 1] -= disc;
            if (c[c.size() - 1] == 0) c.pop_back();
        }
        while (c.size() && c[c.size() - 1] == 0) c.pop_back();
        if (c.empty()) return 1;
    }
    return 0;
}

void solve() {
    int l = 1 , r = 2e16;
    while (l < r) {
        int mid = (l + r) / 2;
        if (jury(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n",l);
}

#undef int
int main(){
    init();
    solve();
    return 0;
}