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

const int N = 300005;
int a[N] , b[N];

bool cmp(prr a , prr b) {
    return a.L.R > b.L.R;
}   

int main(){
    int n;
    scanf("%d",&n);
    rep (i,n) scanf("%d%d",&a[i],&b[i]);
    vector < pr > p , q;
    vector < int > ip , iq;
    rep (i,n) {
        if (a[i] < b[i]) p.push_back( pr(a[i],b[i]) ) , ip.push_back(i);
        if (a[i] > b[i]) q.push_back( pr(b[i],a[i]) ) , iq.push_back(i);
    }
    
    bool hasRv = 0;
    vector < prr > f;
    if (p.size() < q.size()) {
        swap (p,q);
        swap (ip,iq);
        hasRv = 1;
    }
    
    rep (i,(int)p.size()) f.push_back( prr(p[i] , ip[i]) );
    sort (f.begin() , f.end() , cmp);
    if (hasRv) reverse (f.begin() , f.end());

    printf("%d\n",f.size());
    rep (i,(int)f.size()) printf("%d ",f[i].R + 1);
    puts("");
    return 0;
}