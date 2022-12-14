#include<bits/stdc++.h>
using namespace std;
const int N=502;
bool v;
int n,m,q,a[N][N],x,y,X,Y,p,s[N][N][N],A,l,r;
string S[N];
bool C(int p)
{
	X-=2*p,Y-=2*p;
	if(x>X||y>Y)
	{
		X+=2*p,Y+=2*p;
		return false;
	}
	if(s[p][X][Y]-s[p][x-1][Y]-s[p][X][y-1]+s[p][x-1][y-1]>0)
	{
		X+=2*p,Y+=2*p;
		return true;
	}
	X+=2*p,Y+=2*p;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>S[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(S[i][j-1]=='R')
				a[i][j]=1;
			else if(S[i][j-1]=='G')
				a[i][j]=2;
			else if(S[i][j-1]=='Y')
				a[i][j]=3;
			else
				a[i][j]=4;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			x=i,y=j,p=1;
			while(1<=x&&x+2*p-1<=n&&1<=y&&y+2*p-1<=m)
			{
				v=false;
				for(int k=x;k<=x+p-1;k++)
					for(int l=y;l<=y+p-1;l++)
						if(a[k][l]!=1)
							v=true;
				for(int k=x;k<=x+p-1;k++)
					for(int l=y+p;l<=y+2*p-1;l++)
						if(a[k][l]!=2)
							v=true;
				for(int k=x+p;k<=x+2*p-1;k++)
					for(int l=y;l<=y+p-1;l++)
						if(a[k][l]!=3)
							v=true;
				for(int k=x+p;k<=x+2*p-1;k++)
					for(int l=y+p;l<=y+2*p-1;l++)
						if(a[k][l]!=4)
							v=true;
				if(v)
					break;
				s[p][x][y]=1,x--,y--,p++;
			}
		}
	for(int i=1;i<N;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				s[i][j][k]+=s[i][j-1][k]+s[i][j][k-1]-s[i][j-1][k-1];
	while(q--&&cin>>x>>y>>X>>Y)
	{
		X++,Y++,l=0,r=N;
		while(l<r)
			if(C((l+r+1)/2))
				l=(l+r+1)/2;
			else
				r=(l+r-1)/2;
		cout<<4*l*l<<'\n';
	}
	return 0;
}