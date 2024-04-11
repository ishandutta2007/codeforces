#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int N=1e3+3;
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
inline char gc(){char c=getchar();for(;c!='a'&&c!='b'&&c!='*';c=getchar());return c;}
inline void jh(int &x,int &y){if(x!=y)x^=y^=x^=y;}
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
inline LL min(LL x,LL y){return x<y?x:y;}
inline LL max(LL x,LL y){return x>y?x:y;}
struct Hash
{
    int M;
    int K;
    inline void init(int M_=0,int K_=0){M=M_;K=K_;return;}
    inline int prpr(int x,int y){return 1LL*x*y%M;}
    inline void Hash_line(int *a,int *b,int L){b[0]=0;for(int i=1;i<=L;i++)b[i]=(prpr(b[i-1],K)+a[i])%M;return;}
    inline int Hash_num(int *a,int L){int ans=0;for(int i=1;i<=L;i++)ans=(prpr(ans,K)+a[i])%M;return ans;}
}MA,MB,MC,MD;
namespace fac
{
    const int M=998244353;
    inline int prpr(int x,int y){return 1LL*x*y%M;}
    inline int ksm(int x,int y){int ans=1;for(;y;y>>=1){if(y&1)ans=prpr(ans,x);x=prpr(x,x);}return ans;}
    int sl[N];
    int sr[N];
    inline void init()
    {
        sl[0]=sr[0]=1;
        for(int i=1;i<N;i++)sl[i]=prpr(sl[i-1],i);
        sr[N-1]=ksm(sl[N-1],M-2);for(int i=N-2;i;i--)sr[i]=prpr(sr[i+1],i+1);
        return;
    }
}
inline void Hash_init(){MA.init(25384013,31);MB.init(16360361,37);MC.init(19260817,41);MD.init(19437413,43);return;}

int a[N][N];
int ans[N<<2];
inline void work()
{
    int n=rin(),m=rin();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=(gc()=='a');
    if(m==1){puts("YES");puts("1 2");return;}
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i!=j&&a[i][j]==a[j][i])
    {
        puts("YES");
        for(int _=0;_<=m;_++)printf("%d ",(_&1)?(i):(j));printf("\n");
        return;
    }
    if(m&1)
    {
        puts("YES");
        int i=1,j=2;
        for(int _=0;_<=m;_++)printf("%d ",(_&1)?(i):(j));printf("\n");
        return;
    }
    if(n==2){puts("NO");return;}
    if((m>>1)&1)
    {
        int x,y,z;
        if(a[1][2]==a[2][3])x=1,y=2,z=3;
        if(a[2][3]==a[3][1])x=2,y=3,z=1;
        if(a[3][1]==a[1][2])x=3,y=1,z=2;
        puts("YES");
        for(int _=0;_<=m;_++)
        {
            int now=_%4;
            if(now==0)printf("%d ",x);
            if(now==1||now==3)printf("%d ",y);
            if(now==2)printf("%d ",z);
        }
        printf("\n");
        return;
    }
    else
    {
        int x,y,z;
        if(a[1][2]==a[2][3])x=1,y=2,z=3;
        if(a[2][3]==a[3][1])x=2,y=3,z=1;
        if(a[3][1]==a[1][2])x=3,y=1,z=2;
        ans[m>>1]=y;
        for(int i=(m>>1)-1;i>=0;i--)
        {
            if(ans[i+1]==y)ans[i]=x;
            if(ans[i+1]==x)ans[i]=z;
            if(ans[i+1]==z)ans[i]=y;
        }
        for(int i=(m>>1)+1;i<=m;i++)
        {
            if(ans[i-1]==y)ans[i]=z;
            if(ans[i-1]==z)ans[i]=x;
            if(ans[i-1]==x)ans[i]=y;
        }
        puts("YES");
        for(int i=0;i<=m;i++)printf("%d ",ans[i]);printf("\n");
    }
    
    return;
}
int main()
{
    // Hash_init();
    for(int T=rin();T;T--)work();
    return 0;
}