#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1001000
using namespace std;

int n,m,id[N],cnt,ans[N],t;
bool yx[N];
string str;
struct Node
{
	int type,a,b;
}node[N];

int dfs(int now)
{
	int p,q;
	if(node[now].type==3) return node[now].a;
	if(!node[now].type)
	{
		p=dfs(node[now].a);
		q=dfs(node[now].b);
		if(p==q&&p==1) return p&q;
		if(p==q)
		{
			yx[node[now].a]=yx[node[now].b]=0;
			return p&q;
		}
		if(p==1) yx[node[now].a]=0;
		else yx[node[now].b]=0;
		return p&q;
	}
	if(node[now].type==1)
	{
		p=dfs(node[now].a);
		q=dfs(node[now].b);
		if(p==q&&!p) return p|q;
		if(p==q)
		{
			yx[node[now].a]=yx[node[now].b]=0;
			return p|q;
		}
		if(p==1) yx[node[now].b]=0;
		else yx[node[now].a]=0;
		return p|q;
	}
	if(node[now].type==4)
	{
		return !dfs(node[now].a);
	}
	return dfs(node[now].a)^dfs(node[now].b);
}

void Dfs(int now,bool yxx)
{
	yxx&=yx[now];
	if(node[now].type==3)
	{
		if(yxx) ans[id[now]]=t^1;
		else ans[id[now]]=t;
		return;
	}
	Dfs(node[now].a,yxx);
	if(node[now].type!=4) Dfs(node[now].b,yxx);
}

int main()
{
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		yx[i]=1;
		cin>>str;
		if(str[0]=='A')
		{
			node[i].type=0;
			cin>>node[i].a>>node[i].b;
		}
		else if(str[0]=='O')
		{
			node[i].type=1;
			cin>>node[i].a>>node[i].b;
		}
		else if(str[0]=='X')
		{
			node[i].type=2;
			cin>>node[i].a>>node[i].b;
		}
		else if(str[0]=='I')
		{
			node[i].type=3;
			cin>>node[i].a;
			id[i]=++cnt;
		}
		else
		{
			node[i].type=4;
			cin>>node[i].a;
		}
	}
//	cout<<cnt<<" ";
	t=dfs(1);
	Dfs(1,1);
//	cout<<t<<endl;
	for(i=1;i<=cnt;i++) cout<<ans[i];
}