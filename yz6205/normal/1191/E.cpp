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

const int N = 100005;
char s[N];

int l[2] , r[2] , c[2];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    l[0] = l[1] = n;
    rep (i,n) {
        int x = s[i] - '0';
        l[x] = min(l[x] , i) ; r[x] = max(r[x] , i) ;
        c[x]++;
    }

    see(l[0]);
    see(l[1]);
    see(r[0]);
    see(r[1]);

    if (c[0] == 0 || c[1] == 0) puts("tokitsukaze");
    else if (r[0] - l[0] < k || r[1] - l[1] < k) puts("tokitsukaze");
    else if (r[0] - l[0] == k && r[1] - l[1] == k && n <= 2 * k) puts("quailty");
    else puts("once again");
    return 0;
}