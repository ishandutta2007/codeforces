#include <bits/stdc++.h>

using namespace std;

const int N=105;

int n,m;
int arr[N][N];

int get(int x,int y)
{
	vector<int> v;
	for(int i=0;i<m;i++)
	{
		v.push_back({arr[i][x]-arr[i][y]});
	}
	sort(v.rbegin(),v.rend());
	int sum=0;
	for(int i=0;i<v.size();i++)
	{
		if(sum+v[i]<0) return i;
		sum+=v[i];
	}
	return m;
}

void build(int x,int y)
{
	vector<pair<int,int> > v;
	for(int i=0;i<m;i++)
	{
		v.push_back({arr[i][x]-arr[i][y],i+1});
	}
	sort(v.rbegin(),v.rend());
	int sum=0,i;
	for(i=0;i<v.size();i++)
	{
		if(sum+v[i].first<0) break;
		sum+=v[i].first;
	}
	for(;i<v.size();i++)
	{
		printf("%d ",v[i].second);
	}
	puts("");
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int ans=0,ind=0;
	for(int i=0;i<n-1;i++)
	{
		int v=get(i,n-1);
		if(v>ans){ans=v; ind=i;}
	}
	printf("%d\n",m-ans);
	build(ind,n-1);
}