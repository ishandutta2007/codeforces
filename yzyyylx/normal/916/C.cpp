#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define INF 100000000
#define N 
#define M 
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_P
#define fi first
#define se second
using namespace std;

int n,m;

bool pri(int u)
{
	int i,j;
	if(u<=1) return 0;
	for(i=2;i<=sqrt(u);i++)
	{
		if(u%i) continue;
		return 0;
	}
	return 1;
}

int main()
{
	int i,j;
	cin>>n>>m;
	for(i=n-1;!pri(i);i++);
	cout<<i<<' '<<i<<endl<<1<<" "<<2<<" "<<i-n+2<<endl;
	for(i=2;i<n;i++)
	{
		printf("%d %d %d\n",i,i+1,1);
	}
	i=1,j=3;
	for(;m!=n-1;m--)
	{
		printf("%d %d %d\n",i,j,INF);
		j++;
		if(j>n)
		{
			i++;
			j=i+2;
		}
	}
	return 0;
}