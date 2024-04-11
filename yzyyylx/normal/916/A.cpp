#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 
#define M 
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_P
#define fi first
#define se second
using namespace std;

int k,n,m;

bool pd(int u,int v)
{
	for(;u;)
	{
		if(u%10==7)
		{
			return 1;
		}
		u/=10;
	}
	for(;v;)
	{
		if(v%10==7) return 1;
		v/=10;
	}
	return 0;
}

int main()
{
	int i,j,ans=0;
	cin>>k>>n>>m;
	for(;!pd(n,m);)
	{
		m-=k;
		if(m<0)
		{
			m+=60;
			n--;
			if(n<0)
			{
				n+=24;
			}
		}
		ans++;
	}
	cout<<ans;
	return 0;
}