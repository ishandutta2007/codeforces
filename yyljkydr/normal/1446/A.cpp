#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int>v;

int T,n,w,a[200001];

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&w);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int s=0,ok=0;
		vector<int>ans;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>w)
				continue;
			if(a[i]>=(w+1)/2)
			{
				printf("%d\n%lld\n",1,i);
				ok=1;
				break;
			}
			else
			{
				s+=a[i];
				ans.push_back(i);
				if(s>=(w+1)/2)
				{
					ok=1;
					printf("%d\n",ans.size());
					for(int i=0;i<ans.size();i++)
						printf("%lld%c",ans[i]," \n"[i+1==ans.size()]);
					break;
				}
			}
		}
		if(!ok)
			puts("-1");
	}
}