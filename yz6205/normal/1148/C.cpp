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
int a[N];
int l[N];

vector < pr > ans;

inline void swp(int x , int y) {
    if (x > y) swap(x , y);
    ans.push_back( pr(x,y) );
    swap(a[x] , a[y]);
    l[a[x]] = x;
    l[a[y]] = y;
}

int main(){
    int n;
    scanf("%d",&n);
    repa (i,n) scanf("%d",&a[i]);
    repa (i,n) l[a[i]] = i;
    int pn = n;
    n /= 2;
    repa (i,pn) {
        int lo = l[i] , go = i;
        see(lo);
        see(go);
        if (lo <= go) continue;
        if (lo - go >= n) swp(lo , go);
        else if (lo <= n && go <= n){
            swp(lo , 2 * n);
            swp(go , 2 * n);
        } else if (lo > n  && go <= n) {
            swp(lo , 1);
            swp(1 , 2 * n);
            swp(lo , 1);
            swp(2 * n , go);
        } else { // lo > n && go > n
            swp(lo , 1);
            swp(1 , go);
            swp(lo , 1);
        }
    }
    printf("%d\n",(int)ans.size());
    rep (i,(int)ans.size()) {
        printf("%d %d\n",ans[i].L , ans[i].R);
    }
    return 0;
}