#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n;

char s[N];

int vis[N][N][2][2],f[N][N][2][2];

int dfs(int zz,int zo,int m,int rev)
{
	if(zz==0&&zo==0&&m==1)
		return 0;
	if(vis[zz][zo][m][rev])
		return f[zz][zo][m][rev];
	vis[zz][zo][m][rev]=1;
	int &ret=f[zz][zo][m][rev];
	ret=1e9;
	if(zz)
		ret=min(ret,1-dfs(zz-1,zo+1,m,0));
	if(zo)
		ret=min(ret,1-dfs(zz,zo-1,m,0));
	if(zo&&!rev)
		ret=min(ret,-dfs(zz,zo,m,1));
	if(m==0)
		ret=min(ret,1-dfs(zz,zo,1,0));
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int zz=0,zo=0,m=1;
		for(int i=1;i<=n/2;i++)
			if(s[i]=='0'&&s[n-i+1]=='0')
				zz++;
			else if((s[i]-'0')^(s[n-i+1]-'0'))
				zo++;
		if(n%2==1&&s[n/2+1]=='0')
			m=0;
		int ans=dfs(zz,zo,m,0);
		if(ans<0)
			puts("ALICE");
		else if(ans>0)
			puts("BOB");
		else
			puts("DRAW");
	}
}