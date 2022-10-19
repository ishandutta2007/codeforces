#include<cstdio>
#include<iostream>
#include<fstream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define Set(a) memset(a,0,sizeof(a))
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
typedef long long ll;
typedef unsigned long long ull;
template<typename T> inline T rd(T& x)
{
    T f=1;x=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(T)(c-'0');
    x*=f;
    return x;
}
ll rd(){ll x;rd(x);return x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int inf=1<<30;

int t[200005],c[200005];
int n,q;
int main()
{
    q=rd();
    while(q--)
    {
        n=rd();
        F(i,1,n) rd(t[i]);
        bool flg1=false,flg2=false;
        int x;
        t[n+1]=t[1];
        F(i,1,n) if(t[i]==t[i+1]) flg1=true,x=i;else flg2=true;
        if(!flg2)
        {
            puts("1");
            F(i,1,n) printf("1 ");puts("");
        }
        else
        {
            if(!(n&1))
            {
                puts("2");
                F(i,1,n) printf("%d ",(i&1)+1);puts("");
            }
            else if(flg1)
            {
                puts("2");
                F(i,1,n) c[(x+i-1)%n+1]=i&1;
                F(i,1,n) printf("%d ",c[i]+1);
                puts("");
            }
            else
            {
                puts("3");
                F(i,1,n-1) printf("%d ",(i&1)+1);
                puts("3");
            }
        }
    }
    return 0;
}