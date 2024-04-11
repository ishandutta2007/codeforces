#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n,m,vis[xx];
multiset<int>s[xx];
int ans;
bool check(int x)
{
	ans-=vis[x];
	if(!s[x].size())vis[x]=1;
	else 
	{
		if(*--s[x].end()<x)vis[x]=1;
		else vis[x]=0;
	}
	ans+=vis[x];
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		s[a].insert(b);
		s[b].insert(a);
	}
	for(int i=1;i<=n;i++)check(i);
	int q=read();
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int a=read(),b=read();
			s[a].insert(b);
			s[b].insert(a);
			check(a);
			check(b);
		}
		if(op==2)
		{
			int a=read(),b=read();
			s[a].erase(s[a].find(b));
			s[b].erase(s[b].find(a));
			check(a);
			check(b);
		}
		if(op==3)cout<<ans<<'\n';
	}
	return 0;
}