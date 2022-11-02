#include<bits/stdc++.h>
using namespace std;
const int N=210,V=505,K=1010,mod=1000000007;
int n,v,s=0,p=0,a[N+N]={},b[N+N]={};
long long f[2][N/2][K];
void init()
{
	cin>>n>>v;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		a[i]-=a[n];
	for(int i=1;i<=n+n;++i)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<=n/2;++i)
		if(b[i]-(b[i+i]-b[i])<=v)
			s=b[i];
	a[0]=2000;
	//cout<<"s="<<s<<" s0="<<b[n/2]<<endl;
}
void work()
{
	int now=0,pre=1;
	f[now][0][0]=1;
	for(int i=1;i<=n;++i)
	{
		swap(now,pre);
		for(int j=min(i,n-i);j>=0;--j)
		{
			int c1=(j-1)*(a[i-1]-a[i]);
			int c2=j*(a[i-1]-a[i]);
			int c3=(j+1)*(a[i-1]-a[i]);
			for(int k=0;k<=v;++k)
				f[now][j][k]=0;
			if(j>=1)
				for(int k=c1;k<=v;++k)
					f[now][j][k]+=f[pre][j-1][k-c1];
			for(int k=c2;k<=v;++k)
				f[now][j][k]+=(j+1)*f[pre][j][k-c2];
			for(int k=c3;k<=v;++k)
				f[now][j][k]+=(j+1)*f[pre][j+1][k-c3];
			for(int k=0;k<=v;++k)
				f[now][j][k]%=mod;
		}
	}
	long long ans=0;
	for(int i=0;i<=v;++i)
		ans+=f[now][0][i];
	cerr<<"clock()="<<clock()<<endl;
	cout<<ans%mod<<endl;
}
int main()
{
	srand(time(0));
	init();
	work();
	return 0;
}