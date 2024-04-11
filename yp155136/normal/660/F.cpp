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

const int N = 2e5 + 6;

LL a[N];
LL pre[N];
LL pre2[N];

#define __float128 LL

typedef __float128 Kirino;

struct L
{
    LL m,b;
    L(){}
    L(__float128 _m,__float128 _b) : m(_m),b(_b){}
    Kirino get_val(Kirino x)
    {
        __float128 y=1;
        return m*y*x + b;
    }
    void show()
    {
        cout << "m = "<<m<<" , b = "<<b<<" ";
    }
};

bool operator<(const L &l1,const L &l2)
{
    return (l1.m < l2.m) || (l1.m == l2.m) && (l1.b < l2.b);
}

LL f(LL i)
{
    return pre2[i];
}

LL g(LL j)
{
    __float128 q=1;
    return -pre2[j] + j*q*pre[j];
}

LL h(LL i)
{
    return -pre[i];
}

LL t(LL j)
{
    return j;
}


bool check(L a,L b,L c)
{
    //a is second old line
    return (a.b - b.b)*(a.m - c.m) < (a.b - c.b) * (a.m - b.m);
}


typedef long double ld;
const double eps = 1e-9;

/*
bool check(L a,L b,L c)
{
    //a is second old line
//    ld =
    return log(a.b - b.b) + log(a.m - c.m) + eps < log(a.b - c.b) + log(a.m - c.m);
}
*/


LL dp[N];

typedef pair<pLL,LL> pLLL;

bool used[N];

void cdq(int LL,int RR)
{
    //consider [L , R]
    //cout << "LL = "<<LL<<" , RR = "<<RR<<endl;
    if (LL==RR) return;
    int mid=(LL+RR)>>1;
    cdq(LL,mid);
    cdq(mid+1,RR);
    //influence on  [L , mid) to [mid , R]
    vector<L> v;
    for (int i=LL;mid>=i;i++)
    {
        v.push_back(L(t(i),g(i)));
    }
    sort(ALL(v));
    if (SZ(v) == 0) return;
    deque<L> dq;
    for (L l:v)
    {
        while (SZ(dq)>=2 && check(dq[ SZ(dq)-2 ] , dq[ SZ(dq)-1 ], l)) dq.pop_back();
        dq.push_back(l);
    }
    //cout <<"LL = "<<LL<<" , RR = "<<RR<<" , lines = "<<LL<<","<<mid<<" , updates = "<<mid+1<<","<<RR<<endl;
    vector<pLLL> vv;
    for (int i=mid+1;RR>=i;i++)
    {
        vv.push_back(MP( MP( h(i),f(i) ),i ));
    }
    sort(ALL(vv));
    for (pLLL q:vv)
    {
        int i=q.S;
        while (SZ(dq) >= 2 && dq[0].get_val(h(i)) < dq[1].get_val(h(i))) dq.pop_front();
        //cout <<"use "; dq[0].show();cout<<" to update "<<i<<endl;
        dp[i] = max(dp[i],(long long)(dq[0].get_val(h(i)) + f(i)) );
    }
}


int main () {
    srand(time(NULL));
    int n;
    //cout << log(-12)<<endl;
    Si(n);
    //multiset<LL> st;

    //n^2 version

    /*

    REP1(i,n)
    {
        SL(a[i]);
        pre[i] = pre[i-1] + a[i];
        pre2[i] = pre2[i-1] + i*a[i];
    }
    LL ans=0;
    REP1(i,n)
    {
        REP1(j,i-1)
        {
            ans=  max(ans,f(i)+g(j)+h(i)*t(j));
        }
    }
    PL(ans);
    */


    REP1(i,n)
    {
        SL(a[i]);
        pre[i] = pre[i-1] + a[i];
        pre2[i] = pre2[i-1] + i*a[i];
    };

    /*
    REP1(i,n)
    {
        cout << "f = "<<f(i)<<" , g = "<<g(i)<<" , h = "<<h(i)<<" , t = "<<t(i) << endl;
    }
    */

    cdq(0,n);
    PL(*max_element(dp+1,dp+n+1));

}