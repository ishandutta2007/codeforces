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

int n,a,b,c,T,t[N],sum;

int main()
{
	int i,j;
	cin>>n>>a>>b>>c>>T;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		sum+=T-t[i];
	}
	cout<<max(a*n,sum*(c-b)+a*n);
}