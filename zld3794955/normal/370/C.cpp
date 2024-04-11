#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5050,M=110;
int n,m,l[N]={},ans[N+N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",l+i);
	sort(l+1,l+n+1);
	copy(l+1,l+n+1,ans+1);
	copy(ans+1,ans+n+1,ans+n+1);
}
void work()
{
	int sum=0,pos=0;
	for(int i=1;i<=n;++i)
	{
		int s=0;
		for(int j=1;j<=n;++j)
			s+=l[j]!=ans[i+j];
		if(s>sum)
			pos=i,sum=s;
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;++i)
		cout<<l[i]<<' '<<ans[i+pos]<<endl;
}
int main()
{
	init();
	work();
	return 0;
}