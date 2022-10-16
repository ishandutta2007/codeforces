#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

const int T=1e7;

const int B=100,S=1100;

int cnt[2*T+200000];

int a[200000];

int main()
{
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int c=-B;c<=B;c++)
	{
		for(int j=1;j<=n;j++){cnt[a[j]+j*c+T]++;ans=max(ans,cnt[a[j]+j*c+T]);}
		for(int j=1;j<=n;j++){cnt[a[j]+j*c+T]=0;}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+S&&j<=n;j++)
		{
			if((a[i]-a[j])%(j-i)==0){cnt[(a[i]-a[j])/(j-i)+T]++;ans=max(ans,1+cnt[(a[i]-a[j])/(j-i)+T]);}
		}
		for(int j=i+1;j<=i+S&&j<=n;j++)
		{
			if((a[i]-a[j])%(j-i)==0){cnt[(a[i]-a[j])/(j-i)+T]=0;}
		}
	}
	printf("%d\n",n-ans);
}