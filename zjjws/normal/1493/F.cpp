#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
inline int rin()
{
    int s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)return -s;
    return s;
}
inline void jh(int &x,int &y){if(x^y)x^=y^=x^=y;return;}
inline void jh(LL &x,LL &y){if(x^y)x^=y^=x^=y;return;}

const int N=1e5+3;
int n,m,nm;
bool tag;
int sk[N];
inline int find(int L,int R,int x){if(tag)printf("? %d %d %d %d %d %d\n",n,x,1,L,1,R);else printf("? %d %d %d %d %d %d\n",x,m,L,1,R,1);fflush(stdout);return rin();}
inline int que(int L,int R)
{
    if(L==2)return find(1,R+1,R);
    if(L==3)return find(1,R+1,R)&&find(1,(R<<1)+1,R);
    int mid=R*(L>>1);return find(1,mid+R+1,mid)&&find(1,mid+1,mid);
}
inline void def(LL ans){printf("! %lld\n",ans);fflush(stdout);return;}
inline void init()
{
    n=rin();m=rin();nm=max(n,m);
    for(int i=1;i<=nm;i++)sk[i]=i;
    for(int i=2;i<=nm;i++)for(int j=i<<1;j<=nm;j+=i)sk[j]=min(i,sk[j]);
    return;
}
inline void work()
{
    init();
    int n_R=n,m_R=m;
    int cutt_n=0,cutt_m=0;
    tag=false;for(int i=n;i>1;i/=sk[i])if(que(sk[i],n_R/sk[i]))n_R/=sk[i];
    tag=true;for(int i=m;i>1;i/=sk[i])if(que(sk[i],m_R/sk[i]))m_R/=sk[i];
    
    int n_L=n,m_L=m;n_L/=n_R;m_L/=m_R;
    for(int i=1;i<=n_L;i++)if(!(n_L%i))cutt_n++;
    for(int i=1;i<=m_L;i++)if(!(m_L%i))cutt_m++;
    def(1LL*cutt_n*cutt_m);
    return;
}
int main()
{
    work();
    return 0;
}