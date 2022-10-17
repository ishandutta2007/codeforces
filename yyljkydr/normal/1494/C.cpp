#include<bits/stdc++.h>
using namespace std;

int n,m,T;

int solve(vector<int>a,vector<int>b)
{
	if(!a.size()||!b.size())
		return 0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	vector<int>vis;
	vis.resize(b.size());
	int ret=0,tot=0;
	for(int i=0;i<a.size();i++)
	{
		int p=lower_bound(b.begin(),b.end(),a[i])-b.begin();
		if(p<b.size()&&b[p]==a[i])
			tot++,vis[p]=1;
	}
	ret=tot;
	for(int i=0,j=0,k=0;i<b.size();i++)
	{
		if(b[i]<a[0])
			continue;
		int p=b[i];
		while(j+1<a.size()&&a[j+1]<=p+(j+1))
			j++;
		while(k<b.size()&&b[k]<=p+(j))
			tot-=vis[k],k++;
		//[p,p+j]
		int L=lower_bound(b.begin(),b.end(),p)-b.begin();
		int R=upper_bound(b.begin(),b.end(),p+j)-b.begin()-1;
		ret=max(ret,tot+R-L+1);
	}
	return ret;
}


vector<int>u[2],v[2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<2;i++)
			u[i].clear(),v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x>0)
				u[0].push_back(x);
			else
				u[1].push_back(-x);
		}
		for(int i=1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			if(x>0)
				v[0].push_back(x);
			else
				v[1].push_back(-x);
		}
		printf("%d\n",solve(u[0],v[0])+solve(u[1],v[1]));
	}
}