#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N=2e5+3;
int n,m,k;
inline void jh(int &x,int &y){x^=y^=x^=y;return;}
inline int min(int x,int y){return x<y?x:y;}
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}

vector<int>a[N];
vector<int>b[N];
int p[N];

int d[N];
int num[N];
int dis[N];
int tail;
inline void jjh(int &x,int &y){jh(d[x],d[y]);jh(x,y);return;}
inline void up(int x)
{
    if(x==1)return;
    if(dis[d[x]]<dis[d[x>>1]])jjh(num[d[x]],num[d[x>>1]]),up(x>>1);
    return;
}
inline void down(int x)
{
    if((x<<1)>tail)return;
    int next=x;
    if(dis[d[x<<1]]<dis[d[next]])next=(x<<1);
    if(((x<<1)|1)<=tail&&dis[d[(x<<1)|1]]<dis[d[next]])next=(x<<1)|1;
    if(next!=x)jjh(num[d[x]],num[d[next]]),down(next);
    return;
}
inline void delete_(){jjh(num[d[1]],num[d[tail]]);tail--;down(1);return;}
inline void pop_()
{
    int now=d[1];delete_();
    for(int i=b[now].size()-1;i>=0;i--)
    {
        int to=b[now][i];
        if(dis[to]>dis[now]+1)dis[to]=dis[now]+1,up(num[to]);
    }
    return;
}
inline void Dji()
{
    memset(dis,0x3f,sizeof(dis));
    dis[p[k]]=0;
    d[++tail]=p[k];
    for(int i=1;i<=n;i++)if(i!=p[k])d[++tail]=i;
    for(int i=1;i<=tail;i++)num[d[i]]=i;
    for(;tail;)pop_();
    return;
}
int main()
{
    int i,j;
    n=rin();m=rin();
    for(i=1;i<=m;i++)
    {
        int x=rin(),y=rin();
        a[x].push_back(y);
        b[y].push_back(x);
    }
    k=rin();
    for(i=1;i<=k;i++)p[i]=rin();
    Dji();
    int ans_min=0,ans_max=0;
    for(i=1;i<k;i++)
    {
        int x=p[i],y=p[i+1];
        int minl=0x3f3f3f3f;
        int cutt=0;
        for(j=a[x].size()-1;j>=0;j--)
        {
            int to=a[x][j];
            if(minl>dis[to])minl=dis[to],cutt=0;
            if(minl==dis[to])cutt++;
        }
        if(dis[y]>minl)ans_min++,ans_max++;
        else
        {
            if(cutt==1)continue;
            ans_max++;
        }
    }
    printf("%d %d\n",ans_min,ans_max);
    return 0;
}