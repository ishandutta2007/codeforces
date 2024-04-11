#include<bits/stdc++.h>
using namespace std;
const int L=1000010,K=2020,N=210;
//const long long mod=100000000000007ll,Base=233;
char p[L]={},q[N]={},ans[K]={},ch[K]={};
int n,l,k,cnt,now=0,v[K][N]={};
void init()
{
	gets(p+1);
	gets(q+1);
	n=strlen(p+1);
	l=strlen(q+1);
	cin>>k;
}
bool dfs(int x,int y)
{
	if(y>cnt)
	{
		for(int i=x;i<=k;++i)
			ch[i]='0';
		return true;
	}
	if(x>k || v[x][y]==now)
		return false;
	v[x][y]=now;
	if(dfs(x+1,y))
	{
		ch[x]='0';
		return true;
	}
	else
	{
		int p1=x,p2=y;
		while(p1<=n && p2<=l)
		{
			if(p[p1]!=q[p2])
				return false;
			p1+=k,p2+=cnt;
		}
		if(p1<=n || p2<=l || !dfs(x+1,y+1))
			return false;
		ch[x]='1';
		v[x][y]=now;
		return true;
	}
}
void work()
{
	int a=(n+k-1)/k,b=n/k;
	ans[1]='z';
	for(cnt=1;cnt<=l;++cnt)
	{
		if(cnt*b>l || cnt*a<l)
			continue;
		++now;
		if(dfs(1,1) && strcmp(ch+1,ans+1)<0)
			copy(ch+1,ch+k+1,ans+1);
	}
	puts(ans[1]=='z' ? "0" : ans+1);
}
int main()
{	
	init();
	work();
	return 0;
}