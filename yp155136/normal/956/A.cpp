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
typedef pair<int,int>  pii;
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

const int N = 50 + 6;
const int INF = 0x3f3f3f3f;
const int mod = 1000000000 + 7;

int a[N];

string mp[N];

struct DisjointSet
{
    int p[N];
    void init(int n)
    {
        for (int i=0;N>i;i++) p[i] = i;
    }
    int Find(int x)
    {
        return p[x]==x?x:p[x]=Find(p[x]);
    }
    void Union(int x,int y)
    {
        p[Find(x) ] = Find(y);
        //p[Find(x) ] = Find(y);
    }
} r,c;

int main () {
    srand(time(NULL));
    int n,m;
    cin >>n >>m;
    for(int i=1;n>=i;i++)
    {
        string s;
        cin >>s;
        s=" "+s;
        mp[i] = s;
    }
    c.init(1);
    r.init(1);
    for (int i=1;n>=i;i++)
    {
        vector<int> v;
        for (int j=1;m>=j;j++)
        {
            if (mp[i][j] == '#') v.push_back(j);
        }
        for (int j:v)
        {
            c.Union(v[0],j);
        }
    }
    for (int j=1;m>=j;j++)
    {
        vector<int> v;
        for (int i=1;n>=i;i++)
        {
            if (mp[i][j] == '#') v.push_back(i);
        }
        for (int i:v)
        {
            r.Union(v[0],i);
        }
    }
    #define s mp
    for (int i=1;n>=i;i++)
    {
        for (int j=1;m>=j;j++)
        {
            if (s[i][j] == '#')
            {
                vector<int> rr,cc;
                for (int k=1;n>=k;k++)
                {
                    if (r.Find(i) == r.Find(k)) rr.push_back(k);
                }
                for (int k=1;m>=k;k++)
                {
                    if (c.Find(j) == c.Find(k)) cc.push_back(k);
                }
                for (int i:rr)
                {
                    for (int j:cc)
                    {
                        if (s[i][j] != '#')
                        {
                            puts("No");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    puts("Yes");
    return 0;
}