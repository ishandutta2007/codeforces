#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,w[N],n,x;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);	
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		sort(w+1,w+n+1);
		int s=0;
		for(int i=1;i<=n;i++)
			s+=w[i];
		if(s==x)
		{
			puts("NO");
			continue;
		}
		s=0;
		bool vn=0;
		vector<int>ans;
		for(int i=1;i<=n;i++)
		{
			if(i==n&&vn)
				continue;
			s+=w[i];
			if(s==x)
			{
				s-=w[i];
				s+=w[n];
				s+=w[i];
				ans.push_back(w[n]);
				ans.push_back(w[i]);
				vn=1;
			}
			else
				ans.push_back(w[i]);
		}
		puts("YES");
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}