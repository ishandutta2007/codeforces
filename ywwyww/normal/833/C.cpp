#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int f[10010];
int a[20];
int b[20];
ll l,r,ans;
int n;
int check(int x,int bl,int br)
{
	if(!bl&&!br)
		return 1;
	if(!x)
		return 1;
	int up=(br?b[x]:9);
	int down=(bl?a[x]:0);
	int flag;
	int i;
	for(i=down;i<=up;i++)
		if(f[i])
		{
			f[i]--;
			flag=check(x-1,bl&&i==down,br&&i==up);
			f[i]++;
			if(flag)
				return 1;
		}
	return 0;
}
void dfs(int x,int v)
{
	if(x==9)
	{
		f[x]=v;
		if(check(n,1,1))
			ans++;
		return;
	}
	int i;
	for(i=0;i<=v;i++)
	{
		f[x]=i;
		dfs(x+1,v-i);
	}
}
int main()
{
	scanf("%I64d%I64d",&l,&r);
	n=0;
	while(l)
	{
		a[++n]=l%10;
		l/=10;
	}
	n=0;
	while(r)
	{
		b[++n]=r%10;
		r/=10;
	}
	ans=0;
	dfs(0,n);
	printf("%I64d\n",ans);
	return 0;
}