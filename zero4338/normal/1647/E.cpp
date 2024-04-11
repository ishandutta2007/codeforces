#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n,m,p[maxn],a[maxn];
bool vis[maxn];
int to[30][maxn],id[maxn];
int ans[maxn];
vector<int>ch[maxn];
int main()
{
	n=read();generate_n(p+1,n,read);generate_n(a+1,n,read);
	int cnt=0;
	for(int i=1;i<=n;i++)vis[p[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i])cnt++;
	m=(*max_element(a+1,a+n+1)-n)/cnt;
	for(int i=1;i<=n;i++)to[0][i]=p[i];
	iota(id+1,id+n+1,1);
	if(m&1)for(int i=1;i<=n;i++)id[i]=to[0][id[i]];
	for(int i=1;i<30;i++)
	{
		for(int j=1;j<=n;j++)to[i][j]=to[i-1][to[i-1][j]];
		if((m>>i)&1)for(int j=1;j<=n;j++)id[j]=to[i][id[j]];
	}
	for(int i=1;i<=n;i++)
		ch[a[id[i]]].push_back(i);
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=n;i++)
	{
		if(!ch[i].empty())
		{
			sort(ch[i].begin(),ch[i].end());
			for(int j=1;j<ch[i].size();j++)q.push(ch[i][j]);
			ans[ch[i][0]]=i;
		}
		else{ans[q.top()]=i;q.pop();}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);putchar('\n');
	return 0;
}