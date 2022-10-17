#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int m=-1,mn=n;
		for(int i=2;i<=n;i++)
		{
			int x=i,y=n;
			int tot=0;
			while(x!=1&&y!=1)
			{
				if(y>x)
					y=(y+x-1)/x,tot++;
				else
					x=(x+y-1)/y,tot++;
			}
			if(x*y!=2)
				continue;
			if(tot<mn)
				mn=tot,m=i;
		}
		vector<pair<int,int> >v;
		for(int i=2;i<m;i++)
			v.push_back(make_pair(i,i+1));
		for(int i=m+1;i<n;i++)
			v.push_back(make_pair(i,i+1));
		int x=m,y=n;
		while(x*y!=2)
		{
			if(x>y)
				v.push_back(make_pair(m,n)),x=(x+y-1)/y;
			else 
				v.push_back(make_pair(n,m)),y=(y+x-1)/x;
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++)
			printf("%d %d\n",v[i].first,v[i].second);
	}
}