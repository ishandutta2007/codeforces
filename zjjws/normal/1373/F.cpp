#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e6+3;
struct milk
{
	int l,r;
};
milk x[MAX];
int a[MAX];
int b[MAX];
int n;
inline int cheak(int x)
{
	int l,r;
	r=x;
	for(int i=2;i<=n;i++)
	{
		l=min(a[i],b[i-1]-r);r=a[i]-l;
		if(r>b[i])return 3;
//		printf("i:%d,l:%d,r:%d\n",i,l,r);
	}
	if(r+(a[1]-x)<=b[n])return 1;
	else return 2;
}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	else return s;
}
int main()
{
	int i,j;
	for(int t=rin();t>0;t--)
	{
		n=rin();
		int minx,maxx;
		int ans;
		for(i=1;i<=n;i++)a[i]=rin();
		for(i=1;i<=n;i++)b[i]=rin();
		int l=max(0,a[1]-b[n]),r=min(a[1],b[1]);
		//int l=0,r=min(a[1],b[1]);
		ans=0;
		for(;l<=r;)
		{
			int mid=(l+r)>>1;
			ans=cheak(mid);
//			printf("l:%d,r:%d,mid:%d,ans:%d\n",l,r,mid,ans);
			if(ans==1)break;
			if(ans==2)l=mid+1;
			if(ans==3)r=mid-1;
		}
		if(ans==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}