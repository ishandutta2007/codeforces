#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={},last[N]={},next[N*4]={},end[N*4]={};
set<int> s[N]={};
bool used[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<=n+n;++i)
	{
		scanf("%d%d",&a,&b);
		s[a].insert(b);
		s[b].insert(a);
	}
}
void tryy(int t)
{
	if(t>n)
	{
		a[n+1]=a[1],a[n+2]=a[2];
		bool flag=true;
		for(int i=1;i<=n && flag;++i)
		{
			flag&=s[a[i]].count(a[i+1]) && s[a[i+1]].count(a[i]);
			flag&=s[a[i]].count(a[i+2]) && s[a[i+2]].count(a[i]);
		}
		if(!flag)
			return;
		for(int i=1;i<=n;++i)
			printf("%d ",a[i]);
		printf("\n");
		exit(0);
	}
	for(auto v:s[a[t-1]])
		if(!used[v] && s[a[t-2]].count(v))
		{
			used[v]=true;
			a[t]=v;
			tryy(t+1);
			used[v]=false;
		}
}
void work()
{
	for(int i=1;i<=n;++i)
		if((int)s[i].size()!=4)
		{
			puts("-1");
			return;
		}
	//cout<<"aoffigjaogmsd"<<endl;
	a[1]=1;
	used[1]=true;
	for(auto v1:s[1])
	{
		a[2]=v1;
		used[v1]=true;
		tryy(3);
		used[v1]=false;
	}
	puts("-1");
}
int main()
{
	init();
	work();
	return 0;
}