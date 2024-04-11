#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=2e5+10;
const int MOD=998244353;
struct milk
{
	int x;//
	int y;// 
}a[MAX];
inline bool myru(milk x,milk y){return x.y>y.y;}
inline bool mryu(milk x,milk y){return x.x<y.x;}
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
    int n,k;
    n=rin(),k=rin();
    for(i=1;i<=n;i++)a[i].x=i,a[i].y=rin();
    sort(a+1,a+n+1,myru);
    
    LL sum=0;
    for(i=1;i<=k;i++)sum+=a[i].y;
    
    sort(a+1,a+k+1,mryu);
    //for(i=1;i<=k;i++)printf("%d,",a[i].x);printf("\n");
    LL ans=1;
    for(i=1;i<k;i++)ans*=(a[i+1].x-a[i].x),ans%=MOD;
    printf("%lld %lld",sum,ans);
    
    return 0;
}