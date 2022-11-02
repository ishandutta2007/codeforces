#include<bits/stdc++.h>
using namespace std;
const int L=200,N=1010,M=1010,Inf=1000000;
const int x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,m,dis[4][N][M]={},w[4][4]={};
bool v[4][N][M]={};
char buf[L]={},ch[N][M]={};
void init()
{
	gets(buf);
	sscanf(buf,"%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		gets(ch[i]+1);
	w[1][2]=w[2][1]=w[1][3]=w[3][1]=w[2][3]=w[3][2]=Inf;
}
void bfs(int d)
{
	queue<int> qx,qy;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			dis[d][i][j]=Inf;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(ch[i][j]-'0'==d)
			{
				qx.push(i),qy.push(j);
				dis[d][i][j]=0;
				v[d][i][j]=true;
			}
			if(ch[i][j]=='#')
				v[d][i][j]=true;
		}
	for(int i=0;i<=n+1;++i)
		v[d][i][0]=v[d][i][m+1]=true;
	for(int j=0;j<=m+1;++j)
		v[d][0][j]=v[d][n+1][j]=true;
	while(!qx.empty())
	{
		int x1=qx.front(),y1=qy.front();
		qx.pop(),qy.pop();
		for(int k=0;k<4;++k)
		{
			int x2=x1+x_[k],y2=y1+y_[k];
			if(!v[d][x2][y2])
			{
				v[d][x2][y2]=true;
				qx.push(x2);
				qy.push(y2);
				dis[d][x2][y2]=dis[d][x1][y1]+1;
				if(isdigit(ch[x2][y2]))
					w[d][ch[x2][y2]-'0']=min(w[d][ch[x2][y2]-'0'],dis[d][x2][y2]);
			}
		}
	}/*
	cout<<"d="<<d<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<dis[d][i][j]<<'\t';
		cout<<endl;
	}*/
}
void work()
{
	for(int d=1;d<=3;++d)
		bfs(d);
	int ans=w[1][2]+min(w[1][3],w[2][3]);
	ans=min(ans,w[1][3]+w[2][3]);
	//cout<<w[1][2]<<' '<<w[1][3]<<' '<<w[2][3]<<endl;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ans=min(ans,dis[1][i][j]+dis[2][i][j]+dis[3][i][j]);
	printf("%d\n",ans>=Inf ? -1 : ans-2);
}
int main()
{	
	init();
	work();
	return 0;
}