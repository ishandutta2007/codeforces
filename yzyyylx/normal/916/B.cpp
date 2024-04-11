#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 100100
#define M
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_P
#define fi first
#define se second
using namespace std;

ll n,m,num[N],sum;

void get(ll u,ll pos)
{
	if(!u) return;
	get(u>>1,pos+1);
	if(u&1)
	{
		sum++;
		num[sum]=pos;
	}
}

inline void fj()
{
	num[sum]--;
	num[sum+1]=num[sum];
	sum++;
}

bool cmp(int u,int v)
{
	return u>v;
}

int main()
{
	ll i,j,tmp;
	cin>>n>>m;
	get(n,0);
	if(sum>m)
	{
		cout<<"No";
		return 0;
	}
	for(; sum<m;)
	{
		sort(num+1,num+sum+1,cmp);
		tmp=1;
		for(j=1; num[j]==num[j+1]&&j<sum; j++)
		{
			tmp++;
		}
		if(m-sum>=tmp)
		{
			for(i=1; i<=tmp; i++)
			{
				sum++;
				num[sum]=num[i]-1;
				num[i]--;
			}
		}
		else break;
	}
	sort(num+1,num+sum+1,cmp);
	for(; sum<m;)
	{
		fj();
	}
	puts("Yes");
	for(i=1; i<=sum; i++)
	{
		printf("%lld ",num[i]);
	}
	return 0;
}