#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,l,r;

int a[N],cnt[N];

vector<int>v[2][2];

int s[2][2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		for(int i=1;i<=n;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i<=l)
				cnt[a[i]]++;
			else
				cnt[a[i]]--;
		}
		int l1=0,r1=0,l2=0,r2=0,ans=0;
		for(int i=1;i<=n;i++)
			if(cnt[i]>0)
				l2+=cnt[i]/2,l1+=cnt[i]&1;
			else
				r2+=(-cnt[i])/2,r1+=(-cnt[i])&1;
		ans+=(l1+r1)>>1;
		ans+=l2+r2;
		int val;
		if(l1<r1)
			val=(r1-(l1+2*l2))/2;
		else
			val=(l1-(r1+2*r2))/2;
		if(val>0)
			ans+=val;
		printf("%d\n",ans);
	}
}