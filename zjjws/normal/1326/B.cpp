#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=2e5+10;
int b[MAX];
int a[MAX];
int x[MAX];
LL rin()
{
    LL s=0;
    bool bj=0;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')bj=1,c=getchar();
    while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    int n=rin();
    for(i=1;i<=n;i++)b[i]=rin();
    x[2]=a[1]=b[1];
    for(i=2;i<=n;i++)a[i]=b[i]+x[i],x[i+1]=max(x[i],a[i]);
    for(i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}