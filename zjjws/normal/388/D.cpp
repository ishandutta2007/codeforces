#include <stdio.h>
#define LL long long
using namespace std;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
const int N=33;
const int M=1e9+7;
inline int lowbit(int x){return x&(-x);}
inline void add(int &x,int y){x=(x+y)%M;return;}
inline int prpr(int x,int y){return 1LL*x*y%M;}
inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}

int lg;
int sl[N];
int sr[N];
int pw[N];
int sw[N];
inline int C(int a,int b){return (a<b)?(0):(prpr(sl[a],prpr(sr[b],sr[a-b])));}

inline void init(int n)
{
    lg=32;
    sl[0]=1;for(int i=1;i<=lg;i++)sl[i]=prpr(sl[i-1],i);sr[lg]=ksm(sl[lg],M-2);
    sr[0]=1;for(int i=lg-1;i>=1;i--)sr[i]=prpr(sr[i+1],i+1);
    pw[0]=1;for(int i=1;i<=lg;i++)pw[i]=(pw[i-1]<<1)%M;
    sw[0]=1;for(int i=1;i<=lg;i++)for(int j=0;j<=i;j+=2)add(sw[i],C(i,j));
    for(lg=0;(1<<lg+1)<=n;lg++);
    return;
}

int f[N][N][2];
int main()
{
    int n=rin();init(n);
    if(n==0){puts("1");return 0;}
    f[lg][0][1]=f[lg][1][0]=1;
    for(int i=lg;i>0;i--)
    {
        for(int j=lg-i+1;j>=0;j--)
        {
            //
            add(f[i-1][j+1][1],f[i][j][1]);if(n&(1<<i-1))add(f[i-1][j+1][0],f[i][j][0]);
            //
            if(n&(1<<i-1))add(f[i-1][j][1],prpr(f[i][j][0],sw[j])),add(f[i-1][j][0],prpr(f[i][j][0],(pw[j]-sw[j]+M)%M));
            else add(f[i-1][j][0],prpr(f[i][j][0],sw[j]));
            add(f[i-1][j][1],prpr(f[i][j][1],pw[j]));
        }
    }
    LL ans=0;
    for(int i=lg+1;i>=0;i--)ans+=f[0][i][0]+f[0][i][1];ans%=M;
    printf("%lld\n",ans);
    return 0;
}

//vjudge 