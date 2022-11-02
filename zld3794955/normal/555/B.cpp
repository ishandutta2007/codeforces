#include<bits/stdc++.h>
using namespace std;
const int N=200020,M=200020;
struct event
{
	long long x,y;
	int num,type;
}t[N+M]={};
int n,m,q,ans[N]={};
long long l[N]={},r[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%I64d%I64d",l+i,r+i);
	for(int i=1;i<n;++i)
	{
		long long x=l[i+1]-r[i];
		long long y=r[i+1]-l[i];
		t[++q]={x,y,i,0};
	}
	for(int i=1;i<=m;++i)
	{
		long long x=0;
		scanf("%I64d",&x);
		t[++q]={0,x,i,1};
	}
	sort(t+1,t+q+1,[](const event &n1,const event &n2)
					{return n1.y<n2.y || (n1.y==n2.y && n1.type>n2.type);});
}
void work()
{
	set<pair<long long,int> > s;
	for(int i=1;i<=q;++i)
	{
		if(t[i].type==0)
		{
			auto it=s.lower_bound({t[i].x,0});
			if(it==s.end())
			{
				puts("No");
				return;
			}
			ans[t[i].num]=it->second;
			s.erase(it);
		}
		else
			s.insert({t[i].y,t[i].num});
	}
	puts("Yes");
	for(int i=1;i<n;++i)
		printf("%d ",ans[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}