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
    if(bj)s=-s;
    return s;
}

inline void work()
{
    int n=rin();
    int s_1=0,s_2=0;
    for(int i=1;i<=n;i++)
    {
        if(rin()==1)s_1++;
        else s_2++;
    }
    if((s_1+(s_2<<1))%2==1)puts("NO");
    else
    {
        int sum=s_1+(s_2<<1);
        sum>>=1;
        if(sum%2==0)puts("YES");
        else
        {
            if(s_1==0)puts("NO");
            else puts("YES");
        }
    }
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}