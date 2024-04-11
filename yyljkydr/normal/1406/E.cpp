#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,M=100;

int n,p[N],ptot,vis[N];

void pre()
{
	int n=100000;
	vis[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			p[++ptot]=i;
		for(int j=1;j<=ptot&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
}

int op(int x,int y)
{
	printf("%c %d\n",x-1+'A',y);
	fflush(stdout);
	if(x!=3)
	{
		int ret;
		scanf("%d",&ret);
		return ret;
	}
	return -1;
}

int main()
{
	scanf("%d",&n);
	pre();
	int S=sqrt(n);
	int last=n;
	int fac=1;
	for(int i=S+1,j;i<=n;i=j)
	{
		j=i;
		vector<int>v;
		int s=0;
		while(j<=n&&v.size()<M)
		{
			if(!vis[j])
				v.push_back(j),s+=n/j;
			j++;
		}
		for(auto x:v)
			op(2,x);
		int nw=op(1,1);
		if(last-nw!=s)
		{
			for(auto x:v)
				if(op(1,x))
				{
					fac=x;
					break;
				}
			break;
		}
		last=nw;
	}
	for(int i=S;i>=2;i--)
	{
		int nmx=n/fac;
		if(vis[i])
			continue;
		int x=1;
		while(x*i<=nmx)
			x*=i;
		if(x==1)
			continue;
		op(2,i);
		while(x!=1)
		{
			if(op(1,x))
			{
				fac*=x;
				break;
			}
			x/=i;
		}
	}
	op(3,fac);
}