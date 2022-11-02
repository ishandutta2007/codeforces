#include<bits/stdc++.h>
using namespace std;
const int N=1010,B=10;
int n,a[N]={},l[B]={},r[B]={};
bool check()
{
	for(int i=1;i<=n;++i)
		if(a[i]!=i)
			return false;
	return true;
}
void dfs(int t)
{
	if(check())
	{
		cout<<t-1<<endl;
		for(int i=t-1;i>=1;--i)
			cout<<l[i]<<' '<<r[i]<<endl;
		exit(0);
	}
	if(t==4)
		return;
	for(int i=1;i<=n;++i)
		if(a[i]!=i && (abs(a[i]-a[i-1])!=1 || abs(a[i]-a[i+1])!=1))
			for(int j=i+1;j<=n;++j)
				if(a[j]!=j && (abs(a[j]-a[j+1])!=1 || abs(a[j]-a[j-1])!=1))
				{
					reverse(a+i,a+j+1);
					l[t]=i,r[t]=j;
					dfs(t+1);
					reverse(a+i,a+j+1);
				}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[0]=a[n+1]=-1;
	dfs(1);
	return 0;
}