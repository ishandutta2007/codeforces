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
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

const int N = 100005;
vector < int > ei[N];
int ev[N] , ew[N];
int n , m;
int cnt;

void init() {
    scanf("%d%d",&n,&m);
    rep (i,m) {
        int u , v , w; scanf("%d%d%d",&u,&v,&w);
        u--; v--;
        ev[cnt] = v ; ew[cnt] = w;
        ei[u].push_back(cnt++);
    }
}

int ind[N];
int ord[N];
bool judge(int w) {
    memset(ind,0,sizeof(ind));
    rep (i,m) if (ew[i] > w) ind[ ev[i] ]++;
    queue < int > que;
    rep (i,n) if ( ind[i] == 0 ) que.push(i);
    vector < int > topic;
    while (!que.empty()) {
        int u = que.front() ; que.pop();
        topic.push_back(u);
        foreach (_i , ei[u]) {
            int i = ei[u][_i];
            int _v = ev[i] , _w = ew[i];
            if (_w <= w) continue;
            ind[_v]--;
            if (ind[_v] == 0) que.push(_v);
        } 
    }
    if ((int)topic.size() != n) return 0;
    rep (i,n) ord[ topic[i] ]=i;
    return 1;
}

void solve() {
    int l = 0 , r = 0;
    rep (i,m) r = max(r , ew[i]);
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    judge(l);
    printf("%d ",l);
    vector < int > aid;
    rep (u,n) foreach(_i,ei[u]){
        int i = ei[u][_i] , v = ev[i] , w = ew[i];
        if (w > l) continue;
        if (ord[v] < ord[u]) aid.push_back(i + 1);
    }
    printf("%d\n",(int)aid.size());
    sort (aid.begin() , aid.end());
    rep (i,(int)aid.size()) printf("%d ",aid[i]);
}


#ifdef ENABLE_LL
#undef int
#endif
int main(){
    init();
    solve();
    return 0;
}