#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m,a[maxn],b[maxn],sta,stb;
bool check(int x)
{
	static int lima[maxn],limb[maxn];
	lima[0]=m;limb[0]=n;
	ll mx0=0,mx1=0,now=0;
	for(int i=1;i<=n;i++)
	{
		lima[i]=lima[i-1];
		while(lima[i]&&a[i]+b[lima[i]]>x)lima[i]--;
	}
	for(int i=1;i<=m;i++)
	{
		limb[i]=limb[i-1];
		while(limb[i]&&b[i]+a[limb[i]]>x)limb[i]--;
		now+=limb[i];
	}
	mx0=mx1=now;
	for(int i=n,j=m;i>=1;i--)
	{
		now-=min(j,lima[i]);
		now+=m-max(j,lima[i]);
		mx0=max(mx0,now);
		mx1=max(mx1,now-(i<=sta&&j<stb));
		while(j&&n>=limb[j]+i-1)
		{
			now+=n-(limb[j]+i-1);
			j--;
			mx0=max(mx0,now);
			mx1=max(mx1,now-(i<=sta&&j<stb));
		}
	}
	return mx0==mx1;
}
int main()
{
	n=read();m=read();
	generate_n(a+1,n,read);
	generate_n(b+1,m,read);
	sta=a[1];stb=b[1];
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	sta=lower_bound(a+1,a+n+1,sta)-a;
	stb=lower_bound(b+1,b+m+1,stb)-b;
	int l=0,r=a[sta]+b[stb];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}