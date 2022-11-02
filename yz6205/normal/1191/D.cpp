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

const int N = 100005;
int a[N];
int n;

void init(){
    scanf("%lld",&n);
    rep (i,n) scanf("%lld",&a[i]);
}

int numSame() {
    int ans = 0;
    rep (i,n - 1) ans += a[i] == a[i + 1];
    return ans;
}

void fw() {
    puts("sjfnb");
    exit(0);
}

void sw() {
    puts("cslnb");
    exit(0);
}

void solve() {
    sort(a , a + n);
    int same = numSame();
    if (same > 1) sw();
    rep (i,n - 1) if (a[i] == a[i + 1]) if ( (i > 0 && a[i - 1] + 1 == a[i]) || a[i] == 0) sw();
    int sum = 0;
    rep (i,n) sum += a[i];
    sum -= n * (n - 1) / 2;
    if (sum % 2 == 0) sw();
    else fw();
}

#undef int
int main(){
    init();
    solve();
    return 0;
}