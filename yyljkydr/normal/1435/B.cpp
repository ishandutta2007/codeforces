#include<bits/stdc++.h>
using namespace std;

const int N=511;

int T,n,m,p[N*N];

vector<int>v[N];

bool cmp(vector<int> &a,vector<int> &b)
{
	return p[a[0]]<p[b[0]];
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		set<int>s;
		for(int i=1;i<=n;i++)
		{
			v[i].resize(m);
			for(int j=0;j<m;j++)
				scanf("%d",&v[i][j]);
			s.insert(v[i][0]);
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x;
				scanf("%d",&x);
				if(!s.count(x))
					continue;
				p[x]=j;
			}
		}
		sort(v+1,v+n+1,cmp);
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)
				printf("%d%c",v[i][j]," \n"[j+1==m]);
	}
}