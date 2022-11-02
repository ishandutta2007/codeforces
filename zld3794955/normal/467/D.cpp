#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cctype>
#include<map>
using namespace std;
const long long Base=135,mod=11100033377719ll;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int T=100010,M=100010,P=300030,E=100020,None=-1;
struct node
{
	int len,rtot;
	long long h;
};
inline node get_string()
{
	char ch;
	while(!isalpha(ch=getchar())) ;
	node tmp={1,tolower(ch)=='r',tolower(ch)};
	while(isalpha(ch=getchar()))
	{
		++tmp.len;
		tmp.rtot+=tolower(ch)=='r';
		tmp.h=(tmp.h*Base+tolower(ch))%mod;
	}
	return tmp;
}
map<long long,int> num;
map<int,node> table;
int tot_word,n,m,a[T]={},last[P]={},next[E]={},end[E]={},total_edge=0;
int dfn[P]={},low[P]={},tot_dfn=0,st[P]={},top=0,color[P]={},tot_color=0;
bool checked[P]={},in_stack[P]={};
pair<int,int> value[P];
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
inline int get_num(const node &t)
{
	if(num[t.h]==0)
	{
		num[t.h]=++n;
		table[n]=t;
	}
	return num[t.h];
}
void init()
{
	tot_word=getint();
	int x,y;
	for(int i=1;i<=tot_word;++i)
		a[i]=get_num(get_string());
	m=getint();
	for(int i=1;i<=m;++i)
	{
		x=get_num(get_string());
		y=get_num(get_string());
		add_edge(x,y);
	}
}
void Tarjan(int s)
{
	//cout<<"s="<<s<<endl;
	checked[s]=true;
	in_stack[s]=true;
	st[++top]=s;
	dfn[s]=low[s]=++tot_dfn;
	for(int i=last[s];i;i=next[i])
	{
		int j=end[i];
		//cout<<"j="<<j<<endl;
		if(in_stack[j])
			low[s]=min(low[s],dfn[j]);
		else
			if(!checked[j])
			{
				Tarjan(j);
				low[s]=min(low[s],low[j]);
			}
	}
	if(dfn[s]==low[s])
	{
		++tot_color;
		//cout<<"tot_color="<<tot_color<<endl;
		pair<int,int> tmp(1<<30,1<<30);
		int p=top;
		while(st[p]!=s)
			--p;
		for(int now=p;now<=top;++now)
			color[st[now]]=tot_color;
		for(int now=p;now<=top;++now)
		{
			//cout<<"r="<<table[st[now]].rtot<<" l="<<table[st[now]].len<<endl;
			tmp=min(tmp,make_pair(table[st[now]].rtot,table[st[now]].len));
			in_stack[st[now]]=false;
			//cout<<"p="<<st[now]<<endl;
			for(int i=last[st[now]];i;i=next[i])
				if(color[end[i]]!=tot_color)
					tmp=min(tmp,value[color[end[i]]]);
		}
		value[tot_color]=tmp;
		//cout<<value[tot_color].first<<' '<<value[tot_color].second<<endl;
		top=p-1;
	}
}
void work()
{
	for(int i=1;i<=n;++i)
		if(!checked[i])
			Tarjan(i);
	//cout<<"n="<<n<<endl;
	//for(int i=1;i<=n;++i)
	//	cout<<"i="<<i<<" word="<<table[i].h<<" c="<<color[i]<<endl;
	//for(int i=1;i<=tot_color;++i)
	//	cout<<value[i].first<<' '<<value[i].second<<endl;
	long long ans1=0,ans2=0;
	for(int i=1;i<=tot_word;++i)
	{
		//cout<<"i="<<a[i]<<endl;
		ans1+=value[color[a[i]]].first;
		ans2+=value[color[a[i]]].second;
		//cout<<"ans1="<<ans1<<" ans2="<<ans2<<endl;
	}
	cout<<ans1<<' '<<ans2<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}