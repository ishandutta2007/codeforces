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

const int N = 400005;
int a[N];
int b[N];

int main(){
    int n , m , ta , tb , k;
    scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
    rep (i,n) scanf("%d",&a[i]);
    rep (i,m) scanf("%d",&b[i]);
    if (k >= n || k >= m) {
        puts("-1");
        return 0;   
    }
    sort(a , a + n);
    sort(b , b + m);
    int ans = 0;
    rep (i,k + 1) {
        int arrB = a[i] + ta;
        int indB = lower_bound(b , b + m , arrB) - b;
        int sprC = k - i;
        see(arrB);
        see(indB);
        see(b[indB]);
        if (sprC + indB >= m) {
            puts("-1");
            return 0;
        }
        ans = max(ans , b[sprC + indB] + tb);
    }
    printf("%d\n",ans);
    return 0;
}