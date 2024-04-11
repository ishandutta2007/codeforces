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
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long      LL;
typedef long double    ld;
typedef pair<LL,LL>  pii;
typedef pair<LL,LL>    pLL;
typedef vector<int>    vint;
typedef vector<LL>     vLL;
typedef vector<pii>    vpii;
typedef vector<pLL>    vpLL;

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

#define IOS ios::sync_with_stdio(0); cin.tie(0);

int myRnd() {
    return abs(  ((rand()<<14) ^ rand()) );
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

const int N = 2e5 + 6;
const int INF = 0x3f3f3f3f;

int mods[10] = {1000000861,1000004329,1000025261,1000075057,1000099999,1123465789,1123564987,1123586479,
1124396857,1124638579};

pLL operator-(const pLL &p1,const pLL &p2)
{
    return MP(p1.F-p2.F,p1.S-p2.S);
}

LL operator^(const pLL &p1,const pLL &p2)
{
    return p1.F*p2.S-p1.S*p2.F;
}

LL Val(LL x)
{
    if (x>0) return 1;
    else if (x == 0) return 0;
    else if (x<0) return -1;
}

void make_tobou(vector<pii> &v)
{
    sort(v.begin(),v.end());
    vector<pii> dd;
    for (pii p:v)
    {
        if(SZ(dd)<2) dd.push_back(p);
        else
        {
            while (SZ(dd)>=2 && Val((p-dd[ SZ(dd)-2 ])^( dd[ SZ(dd)-1 ] -dd[ SZ(dd)-2 ])) >= 0) dd.pop_back();
            dd.push_back(p);
        }
    }
    reverse(v.begin(),v.end());
    vector<pii> uu;
    for (pii p:v)
    {
        if (SZ(uu)<2) uu.push_back(p);
        else
        {
            while (SZ(uu)>=2 && Val( (p- uu[ SZ(uu)-2 ] )^( uu[ SZ(uu)-1 ]-uu[ SZ(uu)-2 ] ) ) >= 0) uu.pop_back();
            uu.push_back(p);
        }
    }
    vector<pii> vv;
    for (pii p:dd) vv.push_back(p);
    vv.pop_back();
    for (pii p:uu) vv.push_back(p);
    vv.pop_back();
    v = vv;
}

LL get_area(vector<pii> all)
{
    LL ans=0;
    for (int i=1;SZ(all)-1>i;i++)
    {
        ans += ((all[i]-all[0])^(all[ i+1 ]-all[0]) );
    }
    ans = abs(ans);
    return ans;
}

int n,m;



LL ppow[N];
LL pre1[N],pre2[N];

int xx[5] = {880301,106111601,991,47017,10430579};

pii c1=MP(0,0),c2=MP(0,0);

LL get_dis(LL x1,LL y1,LL x2,LL y2,LL mod)
{
    LL x = ((abs(x1-x2) )%mod + mod) % mod;
    LL y = (( abs(y1-y2) )%mod + mod) % mod;
    return (x*x+y*y)%mod;
}

bool solve(vector<pii> v1,vector<pii> v2,LL X,LL mod1,LL mod2)
{
    ppow[0] = 1;
    REP1(i,N-1)
    {
        ppow[i] = (ppow[i-1]*X) % mod2;
    }
    LL hash1=0,hash2=0;
    int n=SZ(v1);
    v1.push_back(v1.front());
    for (int i=1;n>=i;i++)
    {
        hash1 += ((get_dis( v1[i].F,v1[i].S,v1[i-1].F,v1[i-1].S,mod1 ))*ppow[i] );
        hash1 %= mod2;
        hash2 += ((get_dis( c1.F,c1.S,v1[i-1].F,v1[i-1].S,mod1 ))*ppow[i] );
        hash2 %= mod2;
    }
    for (int i=0;n>i;i++)
    {
        v2.push_back(v2[i]);
    }
    v2.push_back(v2.front());
    for (int i=1;2*n>=i;i++)
    {
        pre1[i] = pre1[i-1] + ((get_dis( v2[i].F,v2[i].S,v2[i-1].F,v2[i-1].S,mod1 ))*ppow[i] );
        pre1[i] %= mod2;
        pre2[i] = pre2[i-1] + ((get_dis( c2.F,c2.S,v2[i-1].F,v2[i-1].S,mod1 ))*ppow[i] );
        pre2[i] %= mod2;
    }
    for (int i=1;n>=i;i++)
    {
        int L=i,R=i+n-1;
        LL mod= mod2;
        if (((pre1[R]-pre1[L-1]+mod)%mod)*ppow[ N-R ] % mod2 == hash1*ppow[N-n]%mod2)
        {
            if (((pre2[R]-pre2[L-1]+mod)%mod)*ppow[ N-R ] % mod2 == hash2*ppow[N-n]%mod2) return true;
        }
    }
    return false;
}

int main () {
    srand(clock());
    vector<pLL> v1,v2;
    Sii(n,m);
    REP1(i,n)
    {
        LL x,y;
        SLL(x,y);
        v1.PB(MP(x,y));
    }
    REP1(i,m)
    {
        LL x,y;
        SLL(x,y);
        v2.PB(MP(x,y));
    }
    make_tobou(v1);
    make_tobou(v2);
    if (SZ(v1) != SZ(v2))
    {
        puts("NO");
        return 0;
    }
    if (get_area(v1) != get_area(v2))
    {
        puts("NO");
        return 0;
    }
    int nn = SZ(v1);
    for (pii &p:v1)
    {
        p.F *= nn;
        p.S *= nn;
        c1.F += p.F;
        c1.S += p.S;
    }
    c1.F /= nn;
    c1.S /= nn;
    for (pii &p:v2)
    {
        p.F *= nn;
        p.S *= nn;
        c2.F += p.F;
        c2.S += p.S;
    }
    c2.F /= nn;
    c2.S /= nn;
    int ff[5] = {0,1,2,3,4},gg[5] = {0,1,2,3,4},hh[5] = {0,1,2,3,4};
    random_shuffle(ff,ff+5);
    random_shuffle(gg,gg+5);
    random_shuffle(hh,hh+5);
    for (int i=0;5>i;i++)
    {
        if (solve(v1,v2,xx[ ff[i] ],mods[ gg[i] ],mods[ hh[i]+5 ]) == false)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}