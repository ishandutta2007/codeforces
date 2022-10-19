#include<iostream>
#include<cstdio>
#define N 300100
using namespace std;

int n,tt,num[N],nm[N];
struct Node
{
	int son[2],cnt;
	Node()
	{
		cnt=0;
		son[0]=son[1]=-1;
	}
}node[9000000];

inline int gb(int u,int v)
{
	return (u>>(v-1))&1;
}

void in(int pos,int now,int u)
{
	node[now].cnt++;
	if(!pos) return;
	int t=gb(u,pos);
	if(node[now].son[t]==-1) node[now].son[t]=++tt;
	in(pos-1,node[now].son[t],u);
}

void del(int pos,int now,int u)
{
	if(!pos) return;
	int t=gb(u,pos);
	node[node[now].son[t]].cnt--;
	if(!node[node[now].son[t]].cnt)
	{
		node[now].son[t]=-1;
		return;
	}
	del(pos-1,node[now].son[t],u);
}

int ask(int pos,int now,int u)
{
	if(!pos) return 0;
	int t=gb(u,pos);
	if(node[now].son[t]!=-1)
	{
		return ask(pos-1,node[now].son[t],u);
	}
	return ask(pos-1,node[now].son[t^1],u)|(1 << (pos-1));
}

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		in(31,0,p);
	}
	for(i=1;i<=n;i++)
	{
		p=ask(31,0,num[i]);
		del(31,0,p^num[i]);
		printf("%d ",p);
	}
}