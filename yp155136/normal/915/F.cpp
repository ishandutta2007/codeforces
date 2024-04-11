#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define LL   long long
#define ld   long double
#define pii  pair<int,int>
#define pLL  pair<LL,LL>
#define vint vector<int>
#define vLL  vector<LL>
#define vpii vector<pii>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define MP make_pair
#define PB push_back

#define Si(x) scanf("%d",&(x));
#define Sii(x,y) scanf("%d %d",&(x),&(y));
#define Siii(x,y,z) scanf("%d %d %d",&(x),&(y),&(z));
#define Siiii(x,y,z,w) scanf("%d %d %d %d",&(x),&(y),&(z),&(w));
#define Siiiii(x,y,z,w,a) scanf("%d %d %d %d %d",&(x),&(y),&(z),&(w),&(a));
#define Siiiiii(x,y,z,w,a,b) scanf("%d %d %d %d %d %d",&(x),&(y),&(z),&(w),&(a),&(b));
#define SL(x) scanf("%lld",&(x));
#define SLL(x,y) scanf("%lld %lld",&(x),&(y));
#define SLLL(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z));
#define SLLLL(x,y,z,w) scanf("%lld %lld %lld %lld",&(x),&(y),&(z),&(w));
#define SLLLLL(x,y,z,w,a) scanf("%lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a));
#define SLLLLLL(x,y,z,w,a,b) scanf("%lld %lld %lld %lld %lld %lld",&(x),&(y),&(z),&(w),&(a),&(b));

#define Pi(x) printf("%d\n",(x));
#define Pii(x,y) printf("%d %d\n",(x),(y));
#define Piii(x,y,z) printf("%d %d %d\n",(x),(y),(z));
#define Piiii(x,y,z,w) printf("%d %d %d %d\n",(x),(y),(z),(w));
#define Piiiii(a,b,c,d,e) printf("%d %d %d %d %d\n",(a),(b),(c),(d),(e));
#define Piiiiii(a,b,c,d,e,f) printf("%d %d %d %d %d %d\n",(a),(b),(c),(d),(e),(f));
#define PL(x) printf("%lld\n",(x)*1LL);
#define PLL(x,y) printf("%lld %lld\n",(x)*1LL,(y)*1LL);
#define PLLL(x,y,z) printf("%lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL);
#define PLLLL(x,y,z,w) printf("%lld %lld %lld %lld\n",(x)*1LL,(y)*1LL,(z)*1LL,(w)*1LL);
#define PLLLLL(a,b,c,d,e) printf("%lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL);
#define PLLLLLL(a,b,c,d,e,f) printf("%lld %lld %lld %lld %lld %lld\n",(a)*1LL,(b)*1LL,(c)*1LL,(d)*1LL,(e)*1LL,(f)*1LL);

#define Pi1(x) printf("%d",  (x));
#define PL1(x) printf("%lld",(x));
#define Pspace putchar(' ');
#define Pendl  puts("");

#define MEM0(x) memset( (x), 0, sizeof( (x) ) )
#define MEM1(x) memset( (x),-1, sizeof( (x) ) )
#define REP1(i,n)  for (int i = 1; (n) >= i ; ++i)
#define REP0(i,n)  for (int i = 0; (n) >  i ; ++i)

int myRnd() {
    return abs(  ((rand()<<15) ^ rand()) );
}

int myRnd(int L,int R) {
    return abs(( (rand()<<15)^rand() ) ) % (R-L+1) + L;
}

void Parr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++) {
        printf("%d%c",arr[i]," \n"[i==R]);
    }
}

void Pvec(vint v) {
    for (int i=0;SZ(v)>i;i++) {
        printf("%d%c",v[i]," \n"[i==SZ(v)-1]);
    }
}

void Sarr(int *arr,int L,int R) {
    for (int i=L;R>=i;i++)
    {
        Si(arr[i]);
    }
}

const int N = 1e6 + 6;

int a[N];
int p[N];
vint G[N];

struct DisjointSet {
    static const int N = 1e6 + 6;
    int p[N];
    int sz[N];
    void init(int n)
    {
        for (int i=0;n>=i;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        return p[x] == x?x:p[x] = Find(p[x]);
    }
    void Union(int x,int y)
    {
        x=Find(x);
        y=Find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x,y);
        sz[y] += sz[x];
        p[x] = y;
    }
    int get_sz(int x)
    {
        return sz[Find(x)];
    }
} djs;

bool used[N];

int main () {
    srand(time(NULL));
    int n;
    Si(n);
    Sarr(a,1,n);
    REP1(i,n)
    {
        p[i] = i;
    }
    REP1(i,n-1)
    {
        int x,y;
        Sii(x,y);
        G[x].PB(y);
        G[y].PB(x);
    }
    sort(p+1,p+n+1,[](const int &x,const int &y){
         return a[x] < a[y];
    });
    LL ans=0;
    djs.init(n);
    //deal with max first
    for (int i=1;n>=i;i++)
    {
        int ii=i;
        i = p[i];
        used[i] = 1;
        vint v;
        LL cnt = 0;
        for (int j:G[i])
        {
            if (used[j])
            {
                int szz = djs.get_sz(j);
                v.push_back(szz);
                cnt += szz;
                djs.Union(i,j);
            }
        }
        LL tot = cnt;
        LL tmp = 0;
        for (int j:v)
        {
            tmp += j * 1LL * (tot - j);
        }
        tmp >>= 1;
        cnt += tmp;
        ans += a[i] * cnt;
        i = ii;
    }
    //deal with minimum
    MEM0(used);
    djs.init(n);
    for (int i=n;i>=1;i--)
    {
        int ii=i;
        i = p[i];
        used[i] = 1;
        vint v;
        LL cnt = 0;
        for (int j:G[i])
        {
            if (used[j])
            {
                int szz = djs.get_sz(j);
                v.push_back(szz);
                cnt += szz;
                djs.Union(i,j);
            }
        }
        LL tot = cnt;
        LL tmp = 0;
        for (int j:v)
        {
            tmp += j * 1LL * (tot - j);
        }
        tmp >>= 1;
        cnt += tmp;
        ans -= a[i] * cnt;
        i = ii;
    }
    PL(ans);
}