#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,m,a[N][N];

vector<pair<int,int> >v;

vector<int>t;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		v.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]),v.push_back(make_pair(a[i][j],i));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=0;
		sort(v.begin(),v.end());
		t.clear();
		t.resize(n+1);
		int last=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(v[j-1].second==i)
					a[i][++last]=v[j-1].first;
			}
		for(int i=1;i<=n;i++)
			t[i]=1;
		for(int j=m;j<n*m;j++)
		{
			int x=v[j].second;
			while(a[x][t[x]])
				t[x]++;
			a[x][t[x]]=v[j].first;
		}
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=m;j++,putchar(' '))
				printf("%d",a[i][j]);
	}
}