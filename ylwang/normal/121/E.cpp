#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int a[100010],f[100010],sum[100010],n,m;

void get(int now)
{
	if(now*10+7<=10000)
	{
		f[now*10+7]=1;
		get(now*10+7);
	}
	if(now*10+4<=10000)
	{
		f[now*10+4]=1;
		get(now*10+4);
	}
}

int lowbit(int x)
{
	return (-x)&x;
}

void add(int i,int val)
{
	while(i<=n)
	{
		sum[i]+=val;
		i+=lowbit(i);
	}
}

int count(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=sum[i];
		i-=lowbit(i);
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	get(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(f[a[i]])
		{
			add(i,1);
		}
	}
	char c[10];
	int l,r,val;
	while(m--)
	{
		scanf("\n%s",c);
		if(c[0]=='c')
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",count(r)-count(l-1));
		}
		else
		{
			scanf("%d%d%d",&l,&r,&val);
			for(int i=l;i<=r;i++)
			{
				if(f[a[i]])
				{
					add(i,-1);
				}
				a[i]+=val;
				if(f[a[i]])
				{
					add(i,1);
				}
			}
		}
	}
}