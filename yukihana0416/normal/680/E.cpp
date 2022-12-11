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

vi G[505][505];

char s[505][505];
bool vis[505][505];
bool vt[505][505];
queue<pii> qv;
int block,tot,ans;
int n,m;
int sum[505][505];
int sz[505*505];

int dir[5][2]={
    {1,0},{-1,0},{0,1},{0,-1},{0,0}
};
bool check(int x,int y) { return 1<=x && x<=n && 1<=y && y<=n; }
void dfs(pii x)
{
    vis[x.fi][x.se]=1; tot++;
//    cout <<x.fi <<" " <<x.se <<" " <<tot <<endl;
    int nx,ny;
    for(int i=0;i<5;i++)
    {
        nx=x.fi+dir[i][0], ny=x.se+dir[i][1];
        if(!check(nx,ny)) continue;
        if(!vt[nx][ny]) qv.push(mk(nx,ny)), vt[nx][ny]=1, G[nx][ny].pb(block);
    }
    for(int i=0;i<4;i++)
    {
        nx=x.fi+dir[i][0], ny=x.se+dir[i][1];
        if(!check(nx,ny)) continue;
        if(s[nx][ny]=='X' || vis[nx][ny]) continue;
        dfs(mk(nx,ny));
    }
}

struct treap
{
    struct node
    {
        int val,cnt,r;
        node *ch[2];
        int cmp(int x) {return x==val ? -1 : x>val; }
    }*rt;
    inline void init() {rt=0; srand(time(NULL));}
    inline node *nn()
    {
        node *res=(node *)malloc(sizeof(node));
        res->cnt=0; res->r=rand();
        res->ch[0]=res->ch[1]=0;
        return res;
    }

    void ro(node *&o,int d)
    {
        node *p=o->ch[!d]; o->ch[!d]=p->ch[d]; p->ch[d]=o; o=p;
    }

    inline void ins(int x,int v) {ins(rt,x,v);}
    void ins(node *&o,int x,int v)
    {
        if(!o)
        {
            o=nn();
            o->val=x; o->cnt+=v;
            return ;
        }
        int d=o->cmp(x);
        if(d==-1) {o->cnt+=v; return ;}
        ins(o->ch[d],x,v);
        if(o->ch[d]->r > o->r) ro(o,!d);
    }

    inline int que(int x) {return que(rt,x);}
    int que(node *o,int x)
    {
        if(!o) return 0;
        int d=o->cmp(x);
        if(d==-1) return o->cnt;
        return que(o->ch[d],x);
    }
};
//treap tp;

int mp[505*505];

inline int get_sum(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

void work()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
//        for(int i=1;i<=n;i++) puts(s[i]+1);

        memset(vis,0,sizeof(vis));
        memset(vt,0,sizeof(vt));
        memset(sum,0,sizeof(sum));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                G[i][j].clear();
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='X');
            }
        block=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(s[i][j]=='.' && !vis[i][j])
                {
                    block++; tot=0;
                    dfs(mk(i,j));
                    while(!qv.empty()) vt[qv.front().fi][qv.front().se]=0, qv.pop();
                    sz[block]=tot;
                }

//        for(int i=1;i<=n;i++)
//            for(int j=1;j<=n;j++)
//            {
//                cout <<"i&j : " <<i <<" " << j <<" : ";
//                int ss=G[i][j].size();
//                for(int w=0;w<ss;w++) cout <<G[i][j][w] <<" "; cout <<endl;
//            }
//        cout <<block <<endl;
//        for(int i=1;i<=block;i++) cout <<sz[i] <<endl;

//        tp.init();
        int now=0,ans=0,ss,temp;
        vi &vv=G[0][0];
        for(int i=1;i+m-1<=n;i++)
        {
            if(i&1)
            {
                if(i==1)
                {
                    for(int p=1;p<=m;p++)
                        for(int q=1;q<=m;q++)
                        {
                            vv=G[p][q];
                            ss=vv.size();
                            for(int w=0;w<ss;w++)
                            {
                                int b=vv[w];
                                if(mp[b]==0) now+=sz[b];
                                mp[b]++;
//                                if(tp.que(b)==0) now+=sz[b];
//                                tp.ins(b,1);
                            }
                        }
                }
                else
                {
                    for(int p=1;p<=m;p++)
                    {
                        vv=G[i+m-1][p];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            if(mp[b]==0) now+=sz[b];
                            mp[b]++;
//                            if(tp.que(b)==0) now+=sz[b];
//                            tp.ins(b,1);
                        }
                        vv=G[i-1][p];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            mp[b]--;
                            if(mp[b]==0) now-=sz[b];
//                            tp.ins(b,-1);
//                            if(tp.que(b)==0) now-=sz[b];
                        }
                    }
                }
                Max(ans,now+get_sum(i,1,i+m-1,m));
//                cout <<"i&j : " <<i <<" " <<1 <<"  : ";
//                for(int p=1;p<=block;p++) cout <<tp.que(p) <<" "; cout <<endl;

                for(int j=2;j+m-1<=n;j++)
                {
                    for(int p=i;p<=i+m-1;p++)
                    {
                        vv=G[p][j+m-1];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            if(mp[b]==0) now+=sz[b];
                            mp[b]++;
//                            if(tp.que(b)==0) now+=sz[b];
//                            tp.ins(b,1);
                        }
                        vv=G[p][j-1];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            mp[b]--;
                            if(mp[b]==0) now-=sz[b];
//                            tp.ins(b,-1);
//                            if(tp.que(b)==0) now-=sz[b];
                        }
                    }
                    Max(ans,now+get_sum(i,j,i+m-1,j+m-1));
//                    cout <<"i&j : " <<i <<" " <<j <<"  : ";
//                    for(int p=1;p<=block;p++) cout <<tp.que(p) <<" "; cout <<endl;
                }
            }
            else
            {
                for(int p=n-m+1;p<=n;p++)
                {
                    vv=G[i+m-1][p];
                    ss=vv.size();
                    for(int w=0;w<ss;w++)
                    {
                        int b=vv[w];
                        if(mp[b]==0) now+=sz[b];
                        mp[b]++;
//                        if(tp.que(b)==0) now+=sz[b];
//                        tp.ins(b,1);
                    }
                    vv=G[i-1][p];
                    ss=vv.size();
                    for(int w=0;w<ss;w++)
                    {
                        int b=vv[w];
                        mp[b]--;
                        if(mp[b]==0) now-=sz[b];
//                        tp.ins(b,-1);
//                        if(tp.que(b)==0) now-=sz[b];
                    }
                }
                Max(ans,now+get_sum(i,n-m+1,i+m-1,n));
//                cout <<"i&j : " <<i <<" " <<n-m+1 <<"  : ";
//                for(int p=1;p<=block;p++) cout <<tp.que(p) <<" "; cout <<endl;

                for(int j=n-m;j>=1;j--)
                {
                    for(int p=i;p<=i+m-1;p++)
                    {
                        vv=G[p][j];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            if(mp[b]==0) now+=sz[b];
                            mp[b]++;
//                            if(tp.que(b)==0) now+=sz[b];
//                            tp.ins(b,1);
                        }
                        vv=G[p][j+m];
                        ss=vv.size();
                        for(int w=0;w<ss;w++)
                        {
                            int b=vv[w];
                            mp[b]--;
                            if(mp[b]==0) now-=sz[b];
//                            tp.ins(b,-1);
//                            if(tp.que(b)==0) now-=sz[b];
                        }
                    }
                    Max(ans,now+get_sum(i,j,i+m-1,j+m-1));
//                    cout <<"i&j : " <<i <<" " <<j <<"  : ";
//                    for(int p=1;p<=block;p++) cout <<tp.que(p) <<" "; cout <<endl;
                }
            }
        }
        printf("%d\n",ans);
    }
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