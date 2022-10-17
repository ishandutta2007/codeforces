#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,num[5],nn;
bool p[5][10],now[5];

bool find(int u)
{
	bool res=0;
	int i;
	if(u==nn+1) return 1;
	for(i=1;i<=3;i++)
	{
		if(!now[i]&&p[i][num[u]])
		{
			now[i]=1;
			res|=find(u+1);
			now[i]=0;
		}
	}
	return res;
}

bool pd(int u)
{
	int i,j;
	nn=0;
	while(u)
	{
		nn++;
		num[nn]=u%10;
		u/=10;
	}
	memset(now,0,sizeof(now));
	return find(1);
}

int main()
{
	int i,j,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=6;j++)
		{
			scanf("%d",&q);
			p[i][q]=1;
		}
	}
	for(i=1;i<=1000;i++)
	{
		if(!pd(i)) break;
	}
	cout<<i-1;
}