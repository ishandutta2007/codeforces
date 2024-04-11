#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+5;
const int inf=0x3f3f3f3f;
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

LL n[4];
LL a[4][N];
LL b[4];
LL sum,ans;
LL SUM[4];
int main()
{
	for (int i=1;i<=3;i++)n[i]=rin();
	b[1]=b[2]=b[3]=inf;
	for (int j=1;j<=3;j++) 
    for (int i=1;i<=n[j];i++) 
	{
        a[j][i]=rin();
		b[j]=min(b[j],a[j][i]);
        sum+=a[j][i];SUM[j]+=a[j][i];
	}
	for (int i=1;i<=3;i++) sort(a[i]+1,a[i]+n[i]+1);
	sort(b+1,b+4);
	ans=sum-2*b[1]-2*b[2];
	ans=max(ans,sum-SUM[1]*2);
	ans=max(ans,sum-SUM[2]*2);
	ans=max(ans,sum-SUM[3]*2);
	cout<<ans<<endl;
    return 0;
}