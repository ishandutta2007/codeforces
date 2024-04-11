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
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

char nxt[256];
int code[256];
char mp[4][1005][1005];
int dis[4][1005][1005];

int dir[5][2]={0,1,0,-1,1,0,-1,0,0,0};

void work()
{
    nxt['+']='+'; code['+']=8|4|2|1;
    nxt['-']='|'; code['-']=2|1;
    nxt['|']='-'; code['|']=8|4;
    nxt['^']='>'; code['^']=8;
    nxt['>']='v'; code['>']=1;
    nxt['v']='<'; code['v']=4;
    nxt['<']='^'; code['<']=2;
    nxt['L']='U'; code['L']=8|4|1;
    nxt['U']='R'; code['U']=4|2|1;
    nxt['R']='D'; code['R']=8|4|2;
    nxt['D']='L'; code['D']=8|2|1;

    memset(mp,0,sizeof(mp));

    int n,m;
    cin >>n >>m;
    for(int i=1;i<=n;i++) scanf("%s",mp[0][i]+1);
    for(int k=1;k<4;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                mp[k][i][j]=nxt[mp[k-1][i][j]];

//    for(int i=0;i<4;i++)
//    {
//        for(int j=1;j<=n;j++) puts(mp[i][j]+1);
//        cout <<endl;
//    }

    pii st,ed;
    cin >>st.fi >>st.se;
    cin >>ed.fi >>ed.se;
    memset(dis,0x3f,sizeof(dis));
    queue<pair<int,pair<int,int> > > q;
    dis[0][st.fi][st.se]=0;
    q.push(mk(0,st));
    while(!q.empty())
    {
        pair<int,pair<int,int> > temp=q.front(); q.pop();
        int d=temp.fi;
        pii now=temp.se;
        for(int i=0;i<5;i++)
        {
            int nx,ny;
            nx=now.fi+dir[i][0], ny=now.se+dir[i][1];
            if(1<=nx && nx<=n && 1<=ny && ny<=m)
            {
                if(i==4)
                {
                    if(dis[(d+1)%4][nx][ny]!=INF) continue;
                }
                else
                {
                    if(dis[d][nx][ny]!=INF) continue;
                }

                if(i==0)
                {
                    if(!(code[mp[d][now.fi][now.se]]&1) || !(code[mp[d][nx][ny]]&2)) continue;
                }
                else if(i==1)
                {
                    if(!(code[mp[d][now.fi][now.se]]&2) || !(code[mp[d][nx][ny]]&1)) continue;
                }
                else if(i==2)
                {
                    if(!(code[mp[d][now.fi][now.se]]&4) || !(code[mp[d][nx][ny]]&8)) continue;
                }
                else if(i==3)
                {
                    if(!(code[mp[d][now.fi][now.se]]&8) || !(code[mp[d][nx][ny]]&4)) continue;
                }

                if(i==4)
                {
                    dis[(d+1)%4][nx][ny]=dis[d][now.fi][now.se]+1;
                    q.push(mk((d+1)%4,mk(nx,ny)));
                }
                else
                {
                    dis[d][nx][ny]=dis[d][now.fi][now.se]+1;
                    q.push(mk(d,mk(nx,ny)));
                }
            }
        }
    }

//    for(int i=0;i<4;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            for(int k=1;k<=m;k++) cout <<(dis[i][j][k]==INF ? -1 : dis[i][j][k]) <<" ";
//            cout <<endl;
//        }
//        cout <<endl;
//    }

    int ans;
    ans=INF;
    for(int i=0;i<4;i++) if(dis[i][ed.fi][ed.se]<ans)
    {
        ans=dis[i][ed.fi][ed.se];
    }
    if(ans==INF) ans=-1;
    cout <<ans <<endl;
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