#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110;
int n,m,a[N][M]={};
char ch[M]={};
vector<int> v[6];
void record(int x0,int y0,int x1,int y1,int x2,int y2)
{
	v[0].push_back(x0),v[1].push_back(y0);
	a[x0][y0]=!a[x0][y0];
	v[2].push_back(x1),v[3].push_back(y1);
	a[x1][y1]=!a[x1][y1];
	v[4].push_back(x2),v[5].push_back(y2);
	a[x2][y2]=!a[x2][y2];
	/*
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;*/
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<6;++i)
			v[i].clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("\n%s",ch+1);
			for(int j=1;j<=m;++j)
				a[i][j]=ch[j]-'0';
		}
		for(int i=1;i<=n-2;++i)
		{
			for(int j=1;j<=m-1;++j)
			{
				if(a[i][j])
				{
					int x1=i+1,y1=j,x2=i+1,y2=j+1;
					if(a[i][j+1])
						x2=i;
					record(i,j,x1,y1,x2,y2);
				}
			}
			if(a[i][m])
				record(i,m,i+1,m-1,i+1,m);
		}
		for(int j=1;j<=m-1;++j)
		{
			if(a[n-1][j] || a[n][j])
			{
				int x0=n-1,y0=j;
				int x1=n,y1=j;
				int x2=n-1,y2=j+1;
				if(!a[x0][y0])
					x0=n,y0=j+1;
				if(!a[x1][y1])
					x1=n,y1=j+1;
				record(x0,y0,x1,y1,x2,y2);
			}
		}
		if(a[n-1][m] && a[n][m])
		{
			record(n-1,m,n-1,m-1,n,m-1);
			record(n-1,m-1,n,m-1,n,m);
		}
		else if(a[n-1][m])
		{
			record(n-1,m-1,n,m-1,n-1,m);
			record(n-1,m-1,n-1,m,n,m);
			record(n-1,m,n,m-1,n,m);
		}
		else if(a[n][m])
		{
			record(n-1,m-1,n-1,m,n,m);
			record(n-1,m-1,n,m-1,n,m);
			record(n-1,m,n,m-1,n,m);
		}
		int ans=v[0].size();
		printf("%d\n",ans);
		for(int i=0;i<ans;++i)
			printf("%d %d %d %d %d %d\n",v[0][i],v[1][i],v[2][i],v[3][i],v[4][i],v[5][i]);
	}
}