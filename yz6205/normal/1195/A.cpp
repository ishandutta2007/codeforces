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
int a[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    m = (n + 1) / 2;
    int r ; 
    rep (i,n) {
        scanf("%d",&r);
        a[r]++;
    }
    int no = 0;
    rep (i,N) no += (a[i] & 1);
    int re = (n - no) / 2;
    printf("%d\n",min(n , min(re , m) * 2 + max(0 , m - re))); 
    return 0;
}