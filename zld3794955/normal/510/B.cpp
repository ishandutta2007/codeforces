#include<bits/stdc++.h>
using namespace std;
const int N=55,M=55,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,m;
char ch[N][M]={};
bool v[N][M]={};
bool dfs(int x,int y,int d)
{
	if(v[x][y])
		return true;
	v[x][y]=true;
	for(int k=0;k<4;++k)
	{
		int x1=x+x_[k],y1=y+y_[k];
		if((k^d)!=2 && ch[x][y]==ch[x1][y1] && dfs(x1,y1,k))
			return true;
	}
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!v[i][j] && dfs(i,j,4))
			{
				puts("Yes");
				return 0;
			}
	puts("No");
}