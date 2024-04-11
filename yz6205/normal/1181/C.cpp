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

const int N = 1005;
char a[N][N];
int n , m;

void init(){
    scanf("%d%d",&n,&m);
    rep (i,n) scanf("%s",a[i]);
}

int down[N][N];

void makeDown() {
    rep (j,m) down[n - 1][j] = n - 1;
    for (int i = n - 2;i>=0;i--) {
        rep (j,m) down[i][j] = (a[i][j] == a[i + 1][j]) ? down[i + 1][j] : i;
    }
}

int check(int x0 , int y) {
    int x1 = down[x0][y] + 1;
    if (x1 >= n) return -1;
    int x2 = down[x1][y] + 1;
    if (x2 >= n) return -1;
    int x3 = down[x2][y] + 1;
    if (x1 - x0 == x2 - x1 && x2 - x1 <= x3 - x2) return x2 + x2 - x1;
    else return -1;
}

void solve() {
    long long ans = 0;
    rep (i,n) {
        int idx = 0;
        int dep = 0;
        char ca , cb , cc;
        rep (j,m) {
            int r = check(i,j);
             //cout << r << ' ' << idx << ' ' <<dep << ' ' << ca << ' ' << cb << ' ' << cc << endl;
            if (r == -1) {
                ans += (long long)idx * (idx + 1) / 2;
                idx = 0;
            } else {
                int nep = r - i;
                int x1 = i + nep / 3;
                int x2 = i + nep / 3 * 2;
                if ( (nep == dep && ca == a[i][j] && cb == a[x1][j] && cc == a[x2][j]) ||
                      idx == 0    ) {
                    idx++;
                    dep = nep ; ca = a[i][j] ; cb = a[x1][j] ; cc = a[x2][j];
                } else {
                    ans += idx* (idx + 1) / 2;
                    idx = 1;
                    dep = nep ; ca = a[i][j] ; cb = a[x1][j] ; cc = a[x2][j];
                }
            }
        }
        ans += (long long)idx * (idx + 1) / 2;
    }
    printf("%lld\n",ans);
}

int main(){
    init();
    makeDown();
    solve();
    return 0;
}