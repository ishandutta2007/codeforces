#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,a[N];

int tot;

vector<int>v[N],nv[2],nxv[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),v[1].push_back(a[i]);
	tot=1;
	long long ans=0;
	int c=0;
	for(int i=29;i>=0;i--)
	{
		long long ans1=0,ans2=0;
		int nt=0;
		for(int j=1;j<=tot;j++)
		{
			nv[0].clear(),nv[1].clear();
			for(auto x:v[j])
			{
				nv[(x>>i)&1].push_back(x);
				if((x>>i)&1)
					ans2+=nv[0].size();
				else
					ans1+=nv[1].size();
			}
			if(nv[0].size())
				nxv[++nt]=nv[0];
			if(nv[1].size())
				nxv[++nt]=nv[1];
		}
		if(ans1<=ans2)
			ans+=ans1;
		else
			c|=1<<i,ans+=ans2;
		for(int i=1;i<=nt;i++)
			v[i]=nxv[i];
		tot=nt;
	}
	printf("%lld %d\n",ans,c);
}