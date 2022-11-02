#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007,N=5050;
char ch[N]={};
int n,f[N][N]={},s[N][N]={},p[N]={},rp[N]={},com[N]={};
int d[N][N]={};
bool cmp(int x,int y)
{
	int p=0;
	while(ch[x+p]==ch[y+p])
		++p;
	return ch[x+p]<ch[y+p];
}
void init()
{
	scanf("%d\n%s",&n,ch+1);
	for(int i=1;i<=n;++i)
		p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i)
		rp[p[i]]=i;
	for(int i=1;i<n;++i)
		while(ch[p[i]+com[i]]==ch[p[i+1]+com[i]])
			++com[i];
	for(int i=1;i<=n;++i)
	{
		d[p[i]][p[i]]=1<<30;
		for(int j=i+1;j<=n;++j)
			d[p[i]][p[j]]=min(d[p[i]][p[j-1]],com[j-1]);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			d[i][j]=d[j][i]=max(d[i][j],d[j][i]);
}
bool ok(int x,int y,int l)
{
	return rp[x]<rp[y] && d[x][y]<l;
}
void work()
{
	for(int i=n;i>=1;--i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(ch[j]=='0')
				continue;
			f[i][j-i]+=s[j][j-i+1];
			if(ok(i,j,j-i))
				(f[i][j-i]+=f[j][j-i])%=mod;
		}
		f[i][n-i+1]=1;
		for(int j=n;j>=1;--j)
			s[i][j]=(f[i][j]+s[i][j+1])%mod;
	}
	cout<<s[1][1]<<endl;
	//if ch[1]=='0' cout<<f[1][1]<<endl;
}
int main()
{
	init();
	work();
	return 0;
}