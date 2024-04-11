#include<bits/stdc++.h>
using namespace std;
const int N=50050;
const long long Inf=1ll<<60;
struct event
{
	int s,v,p,num;
}t[N]={};
int n;
long long m,ans[N]={},st=0;
set<pair<long long,long long> > s;
void erase(long long l,long long r)
{
	s.erase({l,r});
	if(r<=t[n].s || m<=l)
		return;
	else if(l>=t[n].s && r<=m)
		st-=r-l;
	else if(t[n].s>=l && m<=r)
		st-=m-t[n].s;
	else if(l>=t[n].s)
		st-=m-l;
	else
		st-=r-t[n].s;
}
void insert(long long l,long long r)
{
	s.insert({l,r});
	if(r<=t[n].s || m<=l)
		return;
	else if(l>=t[n].s && r<=m)
		st+=r-l;
	else if(t[n].s>=l && m<=r)
		st+=m-t[n].s;
	else if(l>=t[n].s)
		st+=m-l;
	else
		st+=r-t[n].s;
}
void del_seg(int i)
{
	long long last=t[i].s,v=t[i].v;
	while(v)
	{
		auto it=--s.lower_bound({last,0});
		if(it->second>last)
		{
			long long d=it->second-last;
			if(d<=v)
			{
				v-=d;
				auto p=make_pair(it->first,last);
				last=it->second;
				erase(it->first,it->second);
				insert(p.first,p.second);
			}
			else
			{
				auto p1=make_pair(it->first,last);
				auto p2=make_pair(last+v,it->second);
				erase(it->first,it->second);
				insert(p1.first,p1.second);
				insert(p2.first,p2.second);
				last=last+v;
				v=0;
			}
		}
		else
		{
			++it;
			long long d=it->second-it->first;
			if(d<=v)
			{
				v-=d;
				last=it->second;
				erase(it->first,it->second);
			}
			else
			{
				last=it->first+v;
				auto p=make_pair(last,it->second);
				erase(it->first,it->second);
				insert(p.first,p.second);
				v=0;
			}
		}
	}
	ans[t[i].num]=last;
}
int main()
{	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&t[i].s,&t[i].v,&t[i].p);
		t[i].num=i;
	}
	scanf("%I64d",&m);
	sort(t+1,t+n+1,[](const event &e1,const event &e2){return e1.p>e2.p;});
	
	s.insert({-Inf,Inf});
	
	st=m-t[n].s;
	if(st==t[n].v)
	{
		del_seg(n);
		t[n].p=t[1].p+1;
	}
	for(int i=1;i<n;++i)
	{
		del_seg(i);
		if(st==t[n].v)
		{
			del_seg(n);
			t[n].p=t[i].p-1;
		}
	}
	printf("%d\n",t[n].p);
	for(int i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}