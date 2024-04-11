#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
#define xxx 1010
#define yyy 20233
#define inf 5202333333
using namespace std;
struct R{
	ll to,val,nex,pos;
}r[yyy];
struct E{
	int from,to,waste,pos;
}e[yyy];
ll n,m,l,st,en,cnt=1,hea[xxx];

queue<ll>q;
ll d[xxx],in[xxx],pre[xxx],prp[xxx];
void S(int ss)
{
	memset(d,38,sizeof(d));
	d[ss]=0;
	while (!q.empty()) q.pop();
	q.push(ss);
	memset(in,0,sizeof(in));
	ll x,y;
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		in[x]=0;
		for (int i=hea[x];i>0;i=r[i].nex)
		{
			y=r[i].to;
			if (d[y]>d[x]+r[i].val)
			{
				d[y]=d[x]+r[i].val;
				pre[y]=x;prp[y]=i;
				if (!in[y])
				{
					in[y]=1;
					q.push(y);
				}
			}
		}
	}
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&l,&st,&en);
	st++;en++;
	for (int i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&e[i].from,&e[i].to,&e[i].waste);
		e[i].from++;e[i].to++;
		r[++cnt]=(R){e[i].to,e[i].waste,hea[e[i].from],i};
		hea[e[i].from]=cnt;
		r[++cnt]=(R){e[i].from,e[i].waste,hea[e[i].to],i};
		hea[e[i].to]=cnt;
		e[i].pos=cnt;
	}
	//0->inf
	for (int i=1;i<=m;i++)
	{
		if (e[i].waste==0)
		{
			r[e[i].pos].val=inf;
			r[e[i].pos^1].val=inf;
		}
	}
	S(st);
	if (d[en]<l)
	{
		printf("NO\n");
		return 0;
	}
	if (d[en]==l)
	{
		printf("YES\n");
		for (int i=1;i<=m;i++)
			printf("%I64d %I64d %I64d\n",(ll)(e[i].from-1),(ll)(e[i].to-1),(ll)r[e[i].pos].val);
		return 0;
	}
	
	//0->1
	for (int i=1;i<=m;i++)
	{
		if (e[i].waste==0)
		{
			r[e[i].pos].val=1;
			r[e[i].pos^1].val=1;
		}
	}
	S(st);
	if (d[en]>l)
	{
		printf("NO\n");
		return 0;
	}
	
	int t,p,las,cg;
	while (d[en]<l)
	{
		t=en;
		while (t!=st)
		{
			p=prp[t];
			if (e[r[p].pos].waste==0)
			{
				r[p].val+=l-d[en];
				r[p^1].val+=l-d[en];
				break;
			}
			t=pre[t];
		}
		S(st);
	}
	
	printf("YES\n");
	for (int i=1;i<=m;i++)
		printf("%I64d %I64d %I64d\n",(ll)(e[i].from-1),(ll)(e[i].to-1),(ll)r[e[i].pos].val);
	return 0;
}