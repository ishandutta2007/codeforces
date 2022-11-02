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
const int N=100010,root=0;
struct node
{
	int s[26],first_win;
}t[N]={};
int n,k,tot=root;
char ch[N]={};
void add(char *ch,int l)
{
	int p=root;
	for(int i=1;i<=l;++i)
	{
		if(t[p].s[ch[i]-'a']==0)
			t[p].s[ch[i]-'a']=++tot;
		p=t[p].s[ch[i]-'a'];
	}
}
void init()
{
	scanf("%d%d\n",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s\n",ch+1);
		add(ch,strlen(ch+1));
	}
}
void dfs1(int p)
{
	t[p].first_win=0;
	for(int i=0;i<26;++i)
		if(t[p].s[i])
		{
			dfs1(t[p].s[i]);
			if(t[t[p].s[i]].first_win==0)
				t[p].first_win=1;
		}
}
void dfs2(int p)
{
	bool flag=true;
	t[p].first_win=0; 
	for(int i=0;i<26;++i)
		if(t[p].s[i])
		{
			flag=false;
			dfs2(t[p].s[i]);
			if(t[t[p].s[i]].first_win==0)
				t[p].first_win=1;
		}
	if(flag)
		t[p].first_win=1;
}
void work()
{
	dfs1(root);
	if(t[root].first_win) //last round
	{
		dfs2(root);
		if(t[root].first_win)
			puts("First");
		else
			if(k%2)
				puts("First");
			else
				puts("Second");
	}
	else
		puts("Second");
}
int main()
{	
	init();
	work();
	return 0;
}