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

int main(){
#define int long long
    int a , b,  c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld ",(a + b) / c);
    int am = a % c;
    int bm = b % c;
    int gv = 0;
    if (am + bm >= c) gv = min(c - am , c - bm);
    printf("%lld\n",gv);
    return 0;
}