#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

char s[N];

int T,n;

set<int>p,pa,pb;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		p.clear(),pa.clear(),pb.clear();
		for(int i=1;i<=n;i++)
		{
			p.insert(i);
			if(s[i]=='A')
				pa.insert(i);
			else
				pb.insert(i);
		}
		int ans=0;
		while(pa.size())
		{
			int x=*pa.rbegin();
			auto it=p.upper_bound(x);
			if(it==p.end()||s[*it]=='A')
			{
				pa.erase(x);
				ans++;
			}
			else
			{
				pa.erase(x);
				p.erase(x);
				p.erase(*it);
				pb.erase(*it);
			}
		}
		while(pb.size())
		{
			int x=*pb.begin();
			auto it=p.upper_bound(x);
			if(it==p.end()||s[*it]=='A')
				pb.erase(x),ans++;
			else
				pb.erase(x),p.erase(x),pb.erase(*it),p.erase(*it);
		}
		printf("%d\n",ans);
	}
}