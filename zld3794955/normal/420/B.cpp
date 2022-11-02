#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,Any=0,On=1,Off=2;
int n,m,p[N]={},state[N]={};
bool may1[N]={},may2[N]={};
char ch[N]={};
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%c %d\n",&ch[i],&p[i]);
	for(int i=1;i<=m;++i)
	{
		if(ch[i]=='+' && state[p[i]]==Any)
			state[p[i]]=Off;
		if(ch[i]=='-' && state[p[i]]==Any)
			state[p[i]]=On;
	}
}
void work1()
{
	set<int>s,may;
	for(int i=1;i<=n;++i)
		if(state[i]!=Off)
		{
			s.insert(i);
			may.insert(i);
		}
	if(may.empty())
		for(int i=1;i<=n;++i)
			may.insert(i);
	for(int i=1;i<=m;++i)
	{
		if(ch[i]=='+')
		{
			if(s.empty())
			{
				int t=may.count(p[i]);
				may.clear();
				if(t)
					may.insert(p[i]);
			}
			else
				if(may.count(p[i]))
					may.erase(p[i]);
			s.insert(p[i]);
		}
		else
		{
			s.erase(p[i]);
			if(!s.empty() && may.count(p[i]))
				may.erase(p[i]);
		}
	}
	for(set<int>::iterator it=may.begin();it!=may.end();++it)
		may1[*it]=true;
}
void work2()
{
	set<int>s,may;
	for(int i=1;i<=n;++i)
		if(state[i]==On)
		{
			s.insert(i);
			may.insert(i);
		}
	if(may.empty())
		for(int i=1;i<=n;++i)
			may.insert(i);
	for(int i=1;i<=m;++i)
	{
		if(ch[i]=='+')
		{
			if(s.empty())
			{
				int t=may.count(p[i]);
				may.clear();
				if(t)
					may.insert(p[i]);
			}
			else
				if(may.count(p[i]))
					may.erase(p[i]);
			s.insert(p[i]);
		}
		else
		{
			s.erase(p[i]);
			if(!s.empty() && may.count(p[i]))
				may.erase(p[i]);
		}
	}
	for(set<int>::iterator it=may.begin();it!=may.end();++it)
		may2[*it]=true;
}
void get_ans()
{
	int tot=0;
	for(int i=1;i<=n;++i)
		tot+=may1[i]|may2[i];
	printf("%d\n",tot);
	for(int i=1;i<=n;++i)
		if(may1[i] || may2[i])
			printf("%d ",i);
	printf("\n");
}
int main()
{	
	init();
	work1();
	work2();
	get_ans();
	return 0;
}