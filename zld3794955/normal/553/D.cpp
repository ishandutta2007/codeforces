#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct Fraction
{
	int a,b;
}f[N+N]={};
bool Fraction_cmp(const Fraction &F1,const Fraction &F2)
{
	return (long long)F1.a*F2.b<(long long)F1.b*F2.a;
}
set<int> s[N];
int n,m,k,a[N]={},t[N]={},tot=0,now=0,del[N]={};
bool is[N]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&a[i]);
		is[a[i]]=true;
	}
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		s[u].insert(v);
		s[v].insert(u);
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<(int)s[i].size();++j)
			f[++tot]={j,s[i].size()};
	sort(f+1,f+tot+1,Fraction_cmp);
}
bool check(int mid)
{
	++now;
	fill(t+1,t+n+1,0);
	queue<int> q;
	for(int i=1;i<=k;++i)
	{
		q.push(a[i]);
		del[a[i]]=now;
	}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(auto j: s[p])
		{
			++t[j];
			if(del[j]!=now && Fraction_cmp({s[j].size()-t[j],s[j].size()},f[mid]))
			{
				del[j]=now;
				q.push(j);
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(del[i]!=now)
			return true;
	return false;
}
void work()
{
	int l=1,r=tot;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	check(l);
	vector<int> ans;
	for(int i=1;i<=n;++i)
		if(del[i]!=now)
			ans.push_back(i);
	printf("%u\n",ans.size());
	for(auto p:ans)
		printf("%d ",p);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}