#include<cstdio>
#include<algorithm>

using namespace std;

int a[2000000];
bool cnt[5000000];int nxt[5000000],pre[5000000];

const int N=4e6;

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		cnt[a[i]-a[1]]=1;
	}
	nxt[N]=N;for(int i=N-1;i>=0;i--)if(cnt[i])nxt[i]=i;else nxt[i]=nxt[i+1];
	pre[0]=-1;for(int i=1;i<=N;i++)if(cnt[i])pre[i]=i;else pre[i]=pre[i-1];
	for(long long i=1;i<=a[n];i++)
	{
		if(i*(i+1)<a[1])continue;
		int lb=0,rb=i;if(a[1]>i*i)lb=a[1]-i*i;
		int l=0,r=i;
		for(int j=i;;j++)
		{
			if(pre[r]>=l)rb=min(rb,r-pre[r]);
			l+=2*j+1;
			if(nxt[r+1]<l)lb=max(lb,l-nxt[r+1]);
			r+=2*j+2;
			if(l>a[n]-a[1])break;
		}
		if(lb<=rb)
		{
			printf("%lld",i*i+lb-a[1]);
			break;
		}
	}
}