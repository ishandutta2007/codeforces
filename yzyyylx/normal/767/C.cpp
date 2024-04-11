#include<bits/stdc++.h>
#define N 1000000
using namespace std;

int n,num[N+5],l,first[N+5],bb,sum,pd,m,gen;

struct bian
{
	int next,to;
}bn[N];

void add(int p,int q)
{
	bb++;
	bn[bb].to=q;
	bn[bb].next=first[p];
	first[p]=bb;
}

void dfs(int p)
{
	int q;
	q=p;
	p=first[p];
	while(p!=-1)
	{
		dfs(bn[p].to);
		num[q]+=num[bn[p].to];
		p=bn[p].next;
	}
	if(num[q]==sum&&q!=gen)
	{
		if(pd==0)
		{
			pd++;
			num[q]=0;
			m=q;
		}
		else
		{
			pd++;
			printf("%d %d",m,q);
			exit(0);
		}
	}
}

int main()
{
	int i,j,k,m;
	cin>>n;
	memset(first,-1,sizeof(first));
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&num[i]);
		if(l!=0)
		add(l,i);
		if(l==0)
		gen=i;
		sum+=num[i];
	}
	if(sum%3==0)
	{
		sum=sum/3;
	}
	else
	{
		cout<<-1;
		return 0; 
	}
	
	dfs(gen);
	if(pd!=2)
	{
		cout<<-1;
	}
}