#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
#pragma GCC optimize(2)
using namespace std;
const int Rea=1e5+3;
struct Rin
{
    char c;
    inline char gc()
    {
        static char rea[Rea];
        static char *head,*tail;
        return head==tail&&(tail=(head=rea)+fread(rea,1,Rea,stdin),head==tail)?EOF:*head++;
    }
    inline Rin&operator >>(int &x)
    {
        x=0;
        bool tag=false;
        for(c=gc();c>'9'||c<'0';c=gc())if(c=='-'){c=gc();tag=true;break;}
        for(;c>='0'&&c<='9';c=gc())x=(x<<1)+(x<<3)+(c^'0');
        if(tag)x=-x;
        return *this;
    }
}rin;
const int N=1e4+3;
const int M=1e4+3;
const int INF=0x3f3f3f3f;
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline int lowbit(int x){return x&(-x);}
inline int lg(int x){int ans=0;for(;x;x>>=1)ans++;return ans;}

int nxt_cutt=1;
int f[1<<10];
int v[1<<10][M<<1];
struct gyq
{
    int to,nxt;
    gyq(int to_=0,int nxt_=0){to=to_;nxt=nxt_;}
}nxt[M<<1];
int hea[N];
inline void add(int x,int y,int v_)
{
    nxt[++nxt_cutt]=gyq(y,hea[x]);hea[x]=nxt_cutt;v[0][nxt_cutt]=v_;
    nxt[++nxt_cutt]=gyq(x,hea[y]);hea[y]=nxt_cutt;v[0][nxt_cutt]=0;
}

int n,m,k,q;
int h[N];
int w[N];
int d[N];
int tail;
int lst[N];
bool vit[N];
inline void init_high()
{
    for(int i=1;i<=n;i++)h[i]=INF;tail=h[n]=0;d[++tail]=n;
    for(int head=1;head<=tail;)
    {
        int now=d[head++];
        for(int i=hea[now];i;i=nxt[i].nxt)if(v[0][i^1]&&h[nxt[i].to]>h[now]+1)h[nxt[i].to]=h[now]+1,d[++tail]=nxt[i].to;
    }
    return;
}

inline void up(int x){if(x==1)return;if(h[d[x]]>h[d[x>>1]])jh(d[x],d[x>>1]),up(x>>1);return;}
inline void down(int x)
{
    if((x<<1)>tail)return;
    int nxt=x;if(h[d[x<<1]]>h[d[nxt]])nxt=x<<1;if(((x<<1)|1)<=tail&&h[d[(x<<1)|1]>h[d[nxt]]])nxt=(x<<1)|1;
    if(nxt!=x)jh(d[nxt],d[x]),down(nxt);return;
}
inline void push(int x){if(vit[x])return;vit[x]=true;d[++tail]=x;up(tail);return;}
inline int top(){return d[1];}
inline void pop(){vit[d[1]]=false;jh(d[1],d[tail]);tail--;down(1);return;}
inline void water(int S,int i,int v_){v[0][i]-=v_;v[0][i^1]+=v_;w[S]-=v_;w[nxt[i].to]+=v_;push(nxt[i].to);return;}
int cutt_h[N<<1];
inline void HLPP()
{
    init_high();
    if(h[1]==INF)return;
    tail=0;h[1]=n;vit[1]=vit[n]=true;
    for(int i=hea[1];i;i=nxt[i].nxt)if(v[0][i]&&h[nxt[i].to]!=INF)water(1,i,v[0][i]);
    for(int i=1;i<=n;i++)if(h[i]!=INF)cutt_h[h[i]]++;
    for(;tail;)
    {
        int now=top();pop();
        for(int i=hea[now];i&&w[now];i=nxt[i].nxt)
        {
            int to=nxt[i].to;
            if(h[now]!=h[to]+1||!v[0][i])continue;
            water(now,i,min(w[now],v[0][i]));
        }
        if(w[now])
        {
            cutt_h[h[now]]--;if(!cutt_h[h[now]])for(int i=2;i<n;i++)if(h[i]>h[now]&&h[i]<=n)h[i]=n+1,vit[i]=true;
            h[now]=INF;for(int i=hea[now];i;i=nxt[i].nxt)if(v[0][i])h[now]=min(h[now],h[nxt[i].to]+1);
            if(h[now]>n)vit[now]=true;else push(now),cutt_h[h[now]]++;
        }
    }
    f[0]=w[n];
    return;
}

inline bool bfs(int num)
{
    tail=0;d[++tail]=1;w[tail]=INF;lst[1]=0;
    for(int head=1;head<=tail;)
    {
        int now=d[head++];
        for(int i=hea[now];i;i=nxt[i].nxt)
        {
            if(!v[num][i]||w[nxt[i].to])continue;
            w[nxt[i].to]=min(w[now],v[num][i]);
            lst[nxt[i].to]=i;d[++tail]=nxt[i].to;
            if(nxt[i].to==n)break;
        }
        if(d[tail]==n)break;
    }
    for(int i=lst[n];i;i=lst[nxt[i^1].to])v[num][i]-=w[n],v[num][i^1]+=w[n];
    f[num]+=w[n];if(f[num]>INF)f[num]=INF;
    bool tag=(w[n]>0);
    for(int i=1;i<=tail;i++)w[d[i]]=lst[d[i]]=0;
    return tag;
}
inline void FF(int num){v[num][lg(lowbit(num))<<1]=25;for(;bfs(num););return;}

int val[N];
int g[1<<10];
int main()
{
    rin>>n>>m>>k>>q;
    for(int i=1;i<=m;i++){int x,y,v;rin>>x>>y>>v;add(x,y,v);}
    HLPP();memset(w,0,sizeof(w));
    for(int i=1;i<(1<<k);i++)
    {
        int lst=i-lowbit(i);
        for(int j=1;j<=nxt_cutt;j++)v[i][j]=v[lst][j];
        f[i]=f[lst];FF(i);
    }
    for(;q;q--)
    {
        g[0]=0;
        for(int i=1;i<=k;i++)rin>>val[i],g[0]+=val[i];int ans=f[0]+g[0];
        for(int i=1;i<(1<<k);i++)g[i]=g[i-lowbit(i)]-val[lg(lowbit(i))],ans=min(ans,f[i]+g[i]);
        printf("%d\n",ans);
    }
    return 0;
}

//vjudge 