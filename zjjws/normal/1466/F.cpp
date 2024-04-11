#include <algorithm>
#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int N=1e6+3;
const int M=1e9+7;
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
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int n,m;

int d[N];
int tail;

int f[N];
inline int find(int x){return (f[x]==x)?(x):(f[x]=find(f[x]));}

bool vit[N];
int cutt[N];

int sl[N];
int sr[N];

int main()
{
    int i,j;
    n=rin();m=rin();
    
    sl[0]=sr[0]=1;for(i=1;i<=m;i++)sl[i]=prpr(sl[i-1],i);
    sr[m]=ksm(sl[m],M-2);for(i=m-1;i>=1;i--)sr[i]=prpr(sr[i+1],i+1);

    for(i=m+1;i>=1;i--)f[i]=i;
    for(i=1;i<=n;i++)
    {
        int k=rin();
        int x,y;
        x=rin();y=((k==2)?(rin()):(m+1));
        if(find(x)==find(y))continue;
        f[find(x)]=find(y);
        d[++tail]=i;
    }

    for(i=1;i<=m;i++)cutt[find(i)]++;

    memset(vit,0,sizeof(vit));
    // if(find(m+1)!=m+1) 
    // {
    //     puts("El Psy Congroo");
    //     return 0;
    // }
    int s_1=ksm(2,cutt[find(m+1)]);vit[find(m+1)]=true;
    for(i=1;i<=m;i++)
    {
        if(vit[find(i)])continue;
        vit[find(i)]=true;
        int now=cutt[find(i)];
        LL sum=0;
        for(int j=0;j<=now;j+=2)sum+=prpr(sl[now],prpr(sr[j],sr[now-j])),sum%=M;
        sum=sum%M;
        s_1=prpr(s_1,sum);
    }
    printf("%d %d\n",s_1,tail);
    sort(d+1,d+tail+1);
    for(i=1;i<=tail;i++)printf("%d ",d[i]);printf("\n");
    return 0;
}