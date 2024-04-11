#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int N=3e5+3;
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


int n;
int a[N];
vector<int>b[N];
int c[N];
inline void work()
{
    int ans=0;
    n=rin();
    for(int i=1;i<=n;i++)a[i]=rin(),c[a[i]]++;
    int ed=0,z=0,y=0;
    for(int i=n;i>=1;i--)b[a[i]].push_back(i);
    for(int i=1;i<=n;i++)
    {
        int nowy=0x3f3f3f3f,nowz=0x3f3f3f3f;
        if(y==a[i])nowy=2e9;else if(!b[y].empty())nowy=b[y].back();
        if(z==a[i])nowz=2e9;else if(!b[z].empty())nowz=b[z].back();
        if(nowy<=nowz)ans+=(nowy!=2e9),y=a[i];
        else ans+=(nowz!=2e9),z=a[i];
        b[a[i]].pop_back();
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    work();
    return 0;
}