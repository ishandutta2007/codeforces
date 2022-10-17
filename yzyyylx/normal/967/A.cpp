#include<iostream>
#include<cstdio>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 1010
using namespace std;

int n,num[N],s;

int main()
{
	int i,j,p,q;
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&p,&q);
		num[i]=p*60+q;
	}
	num[0]=-s-1;
	for(i=1;i<=n;i++)
	{
		if(num[i]-num[i-1]>2*s+1)
		{
			p=num[i-1]+s+1;
			printf("%d %d",p/60,p%60);
			return 0;
		}
	}
	p=num[n]+s+1;
	printf("%d %d",p/60,p%60);
}