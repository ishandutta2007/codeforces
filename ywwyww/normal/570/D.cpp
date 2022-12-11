#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
struct p
{
	int h;
	int v;
	int id;
	p(int a=0,int b=0,int c=0)
	{
		h=a;
		v=b;
		id=c;
	}
};
list<p> a[500010];
list<int> l[500010];
int ans[500010];
int b[500010];
char s[500010];
void dfs(int x,int dep)
{
	for(auto &v:a[x])
		v.v=b[v.h];
	b[dep]^=1<<(s[x]-'a');
	for(auto v:l[x])
		dfs(v,dep+1);
	for(auto v:a[x])
		ans[v.id]=v.v^b[v.h];
}
int bitcount(int x)
{
	int s=0;
	for(;x;x-=x&-x)
		s++;
	return s;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,x;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		l[x].push_back(i);
	}
	int hh,vv;
	scanf("%s",s+1);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&vv,&hh);
		a[vv].push_back(p(hh,0,i));
	}
	dfs(1,1);
	for(i=1;i<=m;i++)
		if(bitcount(ans[i])<=1)
			printf("Yes\n");
		else
			printf("No\n");
	return 0;
}