#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int L=200,N=2000020,K=56,Inf=1<<30;
int n,k,a[K][K]={},match[K]={},nx[K]={},ny[K]={},vx[K]={},vy[K]={},now=0,d=0;
char buf[L]={},ch[N]={},ch2[N]={};
void init()
{
	gets(buf);
	sscanf(buf,"%d%d",&n,&k);
	gets(ch);
	gets(ch2);
	for(int i=0;i<n;++i)
	{
		int v1=tolower(ch[i])-'a'+(isupper(ch[i]) ? 26 : 0);
		int v2=tolower(ch2[i])-'a'+(isupper(ch2[i]) ? 26 : 0);
		++a[v1][v2];
	}
	for(int i=0;i<k;++i)
		vx[i]=*max_element(a[i],a[i]+k) , vy[i]=0;
}
int dfs(int s)
{
	if(nx[s]==now)
		return 0;
	nx[s]=now;
	for(int i=0;i<k;++i)
		if(vx[s]+vy[i]==a[s][i])
		{
			if(match[i]==-1 || dfs(match[i]))
			{
				match[i]=s;
				return 1;
			}
			ny[i]=now;
		}
		else
			d=min(d,vx[s]+vy[i]-a[s][i]);
	return 0;
}
void work()
{
	fill(match,match+k,-1);
	for(int i=0;i<k;++i)
	{
		d=Inf;
		++now;
		while(!dfs(i))
		{
			for(int i=0;i<k;++i)
				if(nx[i]==now)
					vx[i]-=d;
			for(int i=0;i<k;++i)
				if(ny[i]==now)
					vy[i]+=d;
			++now;
		}
	}
	int ans=0;
	for(int s=0;s<k;++s)
		ans+=a[match[s]][s];
	cout<<ans<<endl;
	char ch[K]={};
	for(int s=0;s<k;++s)
		ch[match[s]]=s>=26 ? toupper('a'+s-26) : 'a'+s;
	puts(ch);
}
int main()
{	
	init();
	work();
	return 0;
}