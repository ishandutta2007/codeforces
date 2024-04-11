#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
struct student
{
	int b,c,num;
	bool operator<(const student &s) const
	{
		return c>s.c;
	}
}t[101000]={};
struct bug
{
	int a,num;
}g[101000]={};
bool cmp_(student s1,student s2)
{
	return s1.b>s2.b;
}
bool cmp(bug x,bug y)
{
	return x.a>y.a;
}
int n,m,s,u[101000]={},b[101000]={},c[101000]={},f[101000]={},way[101000]={};
void init()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;++i)
		scanf("%d",&g[i].a),g[i].num=i;
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=n;++i)
		scanf("%d",&t[i].b);
	for(int i=1;i<=n;++i)
		scanf("%d",&t[i].c);
	for(int i=1;i<=n;++i)
		t[i].num=i;
	sort(t+1,t+n+1,cmp_);
}
bool check(int k)
{
	priority_queue<student>q;
	int pos=1,sum=0,l=1;
	while(l<=n && t[l].b>=g[pos].a)
		q.push(t[l++]);
	while(!q.empty())
	{
		student s1=q.top();
		q.pop();
		for(int i=pos;i<=min(pos+k,m);++i)
			f[g[i].num]=s1.num;
		pos+=k;
		sum+=s1.c;
		if(sum>s)
			return false;
		if(pos>m)
			return true;
		while(l<=n && t[l].b>=g[pos].a)
			q.push(t[l++]);
	}
	return false;
}
void work()
{
	int l=1,r=m+1;
	while(l!=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{	
			r=mid;
			for(int i=1;i<=m;++i)
				way[i]=f[i];
		}
		else
			l=mid+1;
	}
	if(l!=m+1)
	{	
		puts("YES");
		for(int i=1;i<=m;++i)
			cout<<way[i]<<' ';
		cout<<endl;
	}
	else
		puts("NO");
}	
int main()
{	
	init();
	work();
	return 0;
}