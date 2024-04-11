#include <stdio.h>
#include <algorithm>
#define LL long long
using namespace std;
const int N=2e5+3;
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
inline int max(int x,int y){return x>y?x:y;}

int a[N];
inline void work()
{
    int n=rin();
    for(int i=1;i<=n;i++)a[i]=rin();
    sort(a+1,a+n+1);
    LL s_1=0,s_2=0;
    for(int i=n;i>=1;i--)
    {
        if((n-i)&1){if(a[i]&1)s_2+=a[i];}
        else {if(!(a[i]&1))s_1+=a[i];}
    }
    if(s_1==s_2)puts("Tie");
    if(s_1>s_2)puts("Alice");
    if(s_1<s_2)puts("Bob");
    return;
}
int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}