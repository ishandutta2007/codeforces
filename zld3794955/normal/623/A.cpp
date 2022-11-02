#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N][N]={};
char ch[N]={};
bool v[N]={};
bool dfs(int s,char c)
{
	if(v[s])
		return true;
	v[s]=true;
	bool flag=false;
	ch[s]=c;
	for(int i=1;i<=n;++i)
	{
		if(s==i || a[s][i])
			continue;
		flag=true;
		if(!ch[i])
		{
			if(!dfs(i,(c=='a' ? 'c' : 'a')))
				return false;
		}
		else
			if(ch[s]==ch[i])
				return false;
	}
	if(!flag)
		ch[s]='b';
	return true;
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		a[u][v]=a[v][u]=1;
	}
	for(int i=1;i<=n;++i)
		if(!dfs(i,'a'))
		{
			puts("No");
			return 0;
		}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[i][j] && (abs(ch[i]-ch[j])==2))
			{
				puts("No");
				return 0;
			}
	puts("Yes");
	puts(ch+1);
	return 0;
}