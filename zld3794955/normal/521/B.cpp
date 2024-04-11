#include<bits/stdc++.h>
using namespace std;
const int M=100100,mod=1000000009;
int m;
map<pair<int,int>,int> num;
pair<int,int> p[M];
set<int> s;
void init()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&p[i].first,&p[i].second);
		num[p[i]]=i;
	}
}
int calc(int x,int y)
{
	if(y==0)
		return 3;
	if(!num.count({x,y}))
		return 3;
	int s=0;
	for(int k=-1;k<=1;++k)
		s+=num.count({x+k,y-1});
	return s;
}
bool check(int num)
{
	for(int k=-1;k<=1;++k)
		if(calc(p[num].first+k,p[num].second+1)==1)
			return false;
	return true;
}
void get_heap()
{
	for(int i=1;i<=m;++i)
		if(check(i))
			s.insert(i);
}
void update(int v)
{
	s.erase(v);
	num.erase(p[v]);
	int x=p[v].first,y=p[v].second;
	for(int x1=x-3;x1<=x+3;++x1)
		for(int y1=y-3;y1<=y+3;++y1)	
		{
			auto it=num.find({x1,y1});
			if(it!=num.end())
			{
				if(check(it->second))
					s.insert(it->second);
				else
					s.erase(it->second);
			}
		}
}
void work()
{
	get_heap();
	long long ans=0;
	for(int i=1;i<=m;++i)
	{
		int v=(i&1) ? *s.rbegin() : *s.begin();
		update(v);
		ans=(ans*m+v-1)%mod;
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}