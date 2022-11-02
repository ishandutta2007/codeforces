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

const int N = 500005;
const int S = 755;
int a[N];
int t[S][S];

void init() {

}

void solve() {
    int T; scanf(I,&T);
    while (T--) {
        int opt, x, y;
        scanf(III,&opt,&x,&y);
        if (opt == 1) {
            a[x] += y;
            //repa (i,S-1) t[i][x % i] += y;
            int i = 1;
            for (;i + 16 < S;i += 16) {
                t[i + 0][x % (i + 0)] += y;
                t[i + 1][x % (i + 1)] += y;
                t[i + 2][x % (i + 2)] += y;
                t[i + 3][x % (i + 3)] += y;
                t[i + 4][x % (i + 4)] += y;
                t[i + 5][x % (i + 5)] += y;
                t[i + 6][x % (i + 6)] += y;
                t[i + 7][x % (i + 7)] += y;
                t[i + 8][x % (i + 8)] += y;
                t[i + 9][x % (i + 9)] += y;
                t[i +10][x % (i +10)] += y;
                t[i +11][x % (i +11)] += y;
                t[i +12][x % (i +12)] += y;
                t[i +13][x % (i +13)] += y;
                t[i +14][x % (i +14)] += y;
                t[i +15][x % (i +15)] += y;
            }
            for (;i<S;i++) {
                t[i][x % i] += y;
            }
        } else {
            if (x < S) printf(IN, t[x][y]);
            else {
                int res = 0;
                //for (int i=y;i<N;i+=x) res += a[i];
                int i = y;
                for (;i + x*16 < N;i += x*16) {
                    res += a[i + 0 * x];
                    res += a[i + 1 * x];
                    res += a[i + 2 * x];
                    res += a[i + 3 * x];
                    res += a[i + 4 * x];
                    res += a[i + 5 * x];
                    res += a[i + 6 * x];
                    res += a[i + 7 * x];
                    res += a[i + 8 * x];
                    res += a[i + 9 * x];
                    res += a[i +10 * x];
                    res += a[i +11 * x];
                    res += a[i +12 * x];
                    res += a[i +13 * x];
                    res += a[i +14 * x];
                    res += a[i +15 * x];
                }
                for (;i<N;i+=x) {
                    res += a[i];
                }
                printf(IN,res);
            }
        }
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