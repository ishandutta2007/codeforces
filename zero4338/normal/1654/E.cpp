#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5,B=400,maxm=1e8,bas=5e7;
int n,a[maxn];
int ans;
int cnt[maxm];
int main()
{
	generate_n(a+1,n=read(),read);
	for(int i=-B;i<=B;i++)
	{
		int mx=0;
		for(int j=1;j<=n;j++)
		{
			cnt[a[j]-i*j+bas]++;
			mx=max(mx,cnt[a[j]-i*j+bas]);
		}
		ans=max(ans,mx);
		for(int j=1;j<=n;j++)cnt[a[j]-i*j+bas]--;
	}
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=i+1;j<=min(n,i+2*B);j++)
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				cnt[(a[j]-a[i])/(j-i)+bas]++;
				mx=max(mx,cnt[(a[j]-a[i])/(j-i)+bas]);
			}
		}
		ans=max(ans,mx+1);
		for(int j=i+1;j<=min(n,i+2*B);j++)
			if((a[j]-a[i])%(j-i)==0)
				cnt[(a[j]-a[i])/(j-i)+bas]--;
	}
	printf("%d\n",n-ans);
	return 0;
}