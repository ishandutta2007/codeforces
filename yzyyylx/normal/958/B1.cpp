#include<iostream>
#include<cstdio>
#define N 1010
using namespace std;

int ds[N],n,ans;

int main()
{
	int i,j,p,q;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&p,&q);
		ds[p]++,ds[q]++;
		if(ds[p]==2) ans++;
		if(ds[q]==2) ans++;
	}
	cout<<n-ans;
}