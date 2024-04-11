#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAN=1e3+3;
const int MAM=2e3+3;
LL a[MAN];
LL b[MAM];
LL b_l[MAM];
LL b_r[MAM];
LL n,k,p;
inline bool cheak(LL mid)
{
	int i,j;
	for(i=1;i<=k;i++){LL s=mid-abs(b[i]-p);b_l[i]=b[i]-s,b_r[i]=b[i]+s;}
	i=1;j=1;
	for(;i<=n&&j<=k;i++){for(;(a[i]<b_l[j]||a[i]>b_r[j])&&j<=k;j++);if(j>k)break;j++;}
	if(i>n)return true;
	return false;
}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=false;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=true,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
	int i,j;
	LL l=0,r=2e9;
	n=rin();k=rin();p=rin();
	for(i=1;i<=n;i++)a[i]=rin();
	for(i=1;i<=k;i++)b[i]=rin();
	
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	
	LL ans=r;
	for(;l<=r;)
	{
		LL mid=(l+r)>>1;
		if(cheak(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}