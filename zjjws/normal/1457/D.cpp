#include <stdio.h>
#define LL long long
using namespace std;
const int N=1e5+3;
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

int a[N];
int add[N];
int cutt[33];
int main()
{
    int i,j,k;
    int n=rin();
    for(i=1,j=0;i<=n;i++)
    {
        a[i]=rin();
        add[i]=add[i-1]^a[i];
        for(;a[i]>=(1LL<<j+1);j++);cutt[j]++;
        if(cutt[j]>2){puts("1");return 0;}
    }
    for(i=3;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            int les=i-j;
            for(k=n-les;k>=j;k--)if((add[k]^add[k-j])>(add[k+les]^add[k])){printf("%d\n",i-2);return 0;}
        }
    }
    puts("-1");
    return 0;
}