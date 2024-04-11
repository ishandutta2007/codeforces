#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=26,L=251;
char T,c;
int n,m,g[N][M],x,q[4][L],t[4],f[L][L][L];
string s;
void S(int x,int y,int z)
{
	f[x][y][z]=n+1;
	if(x)
		f[x][y][z]=min(f[x][y][z],g[f[x-1][y][z]+1][q[1][x]]);
	if(y)
		f[x][y][z]=min(f[x][y][z],g[f[x][y-1][z]+1][q[2][y]]);
	if(z)
		f[x][y][z]=min(f[x][y][z],g[f[x][y][z-1]+1][q[3][z]]);
}
int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<M;i++)
		g[n+1][i]=g[n+2][i]=n+2;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<M;j++)
			g[i][j]=g[i+1][j];
		g[i][s[i-1]-'a']=i;
	}
	while(m--&&cin>>T>>x)
	{
		if(T=='+'&&cin>>c)
		{
			q[x][++t[x]]=c-'a';
			for(int i=(x==1)*t[1];i<=t[1];i++)
				for(int j=(x==2)*t[2];j<=t[2];j++)
					for(int k=(x==3)*t[3];k<=t[3];k++)
						S(i,j,k);
		}
		else
			t[x]--;
		if(f[t[1]][t[2]][t[3]]<=n)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}