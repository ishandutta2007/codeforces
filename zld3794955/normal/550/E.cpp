#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,a[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
void work()
{
	if(a[n]==1)
	{
		puts("NO");
		return;
	}
	if(n==1)
	{
		puts("YES");
		cout<<a[n]<<endl;
		return;
	}
	if(a[n-1]==1)
	{
		puts("YES");
		for(int i=1;i<n;++i)
			cout<<a[i]<<"->";
		cout<<a[n]<<endl;
		return;
	}
	if(n==2)
	{
		puts("NO");
		return;
	}
	if(a[n-2]==0)
	{
		puts("YES");
		for(int i=1;i<n-2;++i)
			cout<<a[i]<<"->";
		cout<<"("<<a[n-2]<<"->"<<a[n-1]<<")->"<<a[n]<<endl;
		return;
	}
	for(int i=n-3;i>=1;--i)
	{
		if(a[i]==0)
		{
			puts("YES");
			for(int j=1;j<i;++j)
				cout<<a[j]<<"->";
			cout<<"("<<a[i]<<"->(";
			for(int j=i+1;j<n-1;++j)
				cout<<a[j]<<"->";
			cout<<a[n-1]<<"))->"<<a[n]<<endl;
			return;
		}
	}
	puts("NO");
}
int main()
{	
	init();
	work();
	return 0;
}