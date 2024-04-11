#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define N 1010
using namespace std;

int n,m,s,t,first[N],bb,d1[N],d2[N],len,ans;
bool in[N],mm[N][N];
struct Bn
{
	int to,next;
}bn[N<<1];
queue<int>que;

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

int main()
{
	memset(first,-1,sizeof(first));
	memset(d1,0x3f,sizeof(d1));
	memset(d2,0x3f,sizeof(d2));
	int i,j,p,q;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q),add(q,p);
		mm[p][q]=mm[q][p]=1;
	}
	que.push(s);
	d1[s]=0;
	for(;!que.empty();)
	{
		q=que.front();
		que.pop();
		in[q]=0;
		for(p=first[q];p!=-1;p=bn[p].next)
		{
			if(d1[bn[p].to]>d1[q]+1)
			{
				d1[bn[p].to]=d1[q]+1;
				if(!in[bn[p].to])
				{
					in[bn[p].to]=1;
					que.push(bn[p].to);
				}
			}
		}
	}
//	for(i=1;i<=n;i++) cout<<d1[i]<<" "; return 0;
	
	que.push(t);
	d2[t]=0;
	for(;!que.empty();)
	{
		q=que.front();
		que.pop();
		in[q]=0;
		for(p=first[q];p!=-1;p=bn[p].next)
		{
			if(d2[bn[p].to]>d2[q]+1)
			{
				d2[bn[p].to]=d2[q]+1;
				if(!in[bn[p].to])
				{
					in[bn[p].to]=1;
					que.push(bn[p].to);
				}
			}
		}
	}
//	for(i=1;i<=n;i++) cout<<d2[i]<<" "; return 0;
	len=d1[t];
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(!(d1[i]+d2[j]+1<len||d1[j]+d2[i]+1<len||mm[i][j])) ans++;
		}
	}
	cout<<ans;
}