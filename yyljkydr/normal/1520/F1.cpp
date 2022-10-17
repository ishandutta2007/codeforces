#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,T;

int c[N];

void add(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=x&-x;
	}
}

int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}

// map<pair<int,int>, int>sum;

int sum[N];

int k;

int chk(int x)
{
	if(sum[x]!=-1)
		return x-(sum[x]+query(x))>=k;
	printf("? %d %d\n",1,x);
	fflush(stdout);
	int s;
	scanf("%d",&s);
	sum[x]=s-query(x);
	return x-s>=k;
}

int main()
{
	memset(sum,-1,sizeof(sum));
	scanf("%d%d",&n,&T);
	while(T--)
	{
		scanf("%d",&k);
		int l=0,r=n;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if(chk(mid))
				r=mid;
			else
				l=mid;
		}
		printf("! %d\n",r);
		fflush(stdout);
		add(r,1);
	}
}