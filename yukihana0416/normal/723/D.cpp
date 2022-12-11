#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define LL __int64

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T > inline void read(T &res) {
    T x=0; bool f=0; char ch=getchar();
    while(ch<48 || ch>57) {if(ch=='-')f=!f; ch=getchar();}
    while(ch>=48 && ch<=57) {x=x*10+ch-48; ch=getchar();}
    if(f) res=-x; else res=x;
}
char __stack[25],__top;
template< typename T > inline void write(T num) {
    if(num) {
        if(num<0) putchar('-'), num=-num;
        __top=0;
        while(num) __stack[++__top]=num%10, num/=10;
        while(__top) putchar(48+__stack[__top--]);
    }
    else putchar(48);
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline void Swap(T &a,T &b) {T c=a; a=b; b=c;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+20;
const int maxm=(int) 2e5+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

int n,m,k;
priority_queue<pair<int,pii> > pq;
char mp[55][55];
int vis[55][55];

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
inline bool check(pii now)
{
    return 1<=now.fi && now.fi<=n && 1<=now.se && now.se<=m;
}

void print_mp()
{
    for(int i=1;i<=n;i++) puts(mp[i]+1);
}

int vv[55][55];
int Tag;
void change_l(pii st)
{
    if(mp[st.fi][st.se]=='*') return ;
    queue<pii> Q;
    Q.push(st);
    mp[st.fi][st.se]='*';
    vv[st.fi][st.se]=Tag;
    while(!Q.empty())
    {
        pii u=Q.front(),v; Q.pop();
        for(int i=0;i<4;i++)
        {
            v=mk(u.fi+dir[i][0],u.se+dir[i][1]);
            if(!check(v)) continue;
            if(mp[v.fi][v.se]=='.')
            {
                mp[v.fi][v.se]='*';
                vv[v.fi][v.se]=Tag;
                Q.push(v);
            }
        }
    }
//    print_mp();
}

int dfs(pii u)
{
    int res=1;
    vis[u.fi][u.se]=1;
    for(int i=0;i<4;i++)
    {
        pii v=mk(u.fi+dir[i][0],u.se+dir[i][1]);
        if(!check(v)) continue;
        if(mp[v.fi][v.se]=='.' && vis[v.fi][v.se]==0) res+=dfs(v);
    }
    return res;
}

void work()
{
    read(n), read(m); read(k);
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            vv[i][j]=0;

    Tag=1;
    for(int i=1;i<=n;i++) change_l(mk(i,1));
    for(int i=1;i<=n;i++) change_l(mk(i,m));
    for(int i=1;i<=m;i++) change_l(mk(1,i));
    for(int i=1;i<=m;i++) change_l(mk(n,i));
    Tag=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            vis[i][j]=0;

    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='.' && vis[i][j]==0)
            {
                int c=-dfs(mk(i,j));
                pq.push(mk(c,mk(i,j)));
                cnt++;
            }
        }
//    print_mp();
    int ans=0;
    while(k!=cnt)
    {
        pair<int,pii> u=pq.top(); pq.pop();
        ans+=u.first;
        change_l(u.second);
        cnt--;
    }
    printf("%d\n",-ans);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vv[i][j]) mp[i][j]='.';
    print_mp();
}

//--------------end--------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}