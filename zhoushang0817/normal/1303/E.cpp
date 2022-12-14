#include<bits/stdc++.h>
using namespace std;
const int N=401,I=1e9;
bool v;
int T,g[N][N],f[N][N];
string a,b;
int main()
{
	cin>>T;
	while(T--&&cin>>a>>b)
	{
		for(int i=0;i<a.size();i++)
			for(int j=0;j<26;j++)
			{
				g[i][j]=I;
				for(int k=a.size()-1;k>=i;k--)
					if(a[k]==j+'a')
						g[i][j]=k;
			}
		v=false;
		for(int i=0;i<=b.size();i++)
		{
			for(int j=0;j<=i;j++)
				for(int k=0;k<=b.size()-i;k++)
					f[j][k]=I;
			f[0][0]=-1;
			for(int j=1;j<=i;j++)
				if(f[j-1][0]<(int)a.size()-1&&g[f[j-1][0]+1][b[j-1]-'a']!=I)
					f[j][0]=g[f[j-1][0]+1][b[j-1]-'a'];
			for(int j=1;j<=b.size()-i;j++)
				if(f[0][j-1]<(int)a.size()-1&&g[f[0][j-1]+1][b[i+j-1]-'a']!=I)
					f[0][j]=g[f[0][j-1]+1][b[i+j-1]-'a'];
			for(int j=1;j<=i;j++)
				for(int k=1;k<=b.size()-i;k++)
				{
					if(f[j-1][k]<(int)a.size()-1)
						f[j][k]=min(f[j][k],g[f[j-1][k]+1][b[j-1]-'a']);
					if(f[j][k-1]<(int)a.size()-1)
						f[j][k]=min(f[j][k],g[f[j][k-1]+1][b[k+i-1]-'a']);
				}
			if(f[i][b.size()-i]!=I)
				v=true;
		}
		if(v)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}