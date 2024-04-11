#include<bits/stdc++.h>
using namespace std;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int N=50050,D=40,mod=1000000007;
int n,a[N]={};
long long k,ans=0;
long long calc(int l1,int r1,int l2,int r2)
{
	long long tot[D][2]={},sum=0;
	for(int i=l1;i<=r1;++i)
		for(int d=0;d<=30;++d)
			++tot[d][!!(a[i]&(1<<d))];
	for(int i=l2;i<=r2;++i)
		for(int d=0;d<=30;++d)
			sum+=(tot[d][!(a[i]&(1<<d))]<<d)%mod;
	return sum%mod;
}
void init()
{
	n=getint(),k=getint();
	for(int i=1;i<=n;++i)
		a[i]=getint();
	sort(a+1,a+n+1);
}
void work()
{
	int now=0;
	for(int d=30;d>=0;--d)
	{
		map<int,int> m;
		for(int i=1;i<=n;++i)
			++m[(a[i]>>d)<<d];
		long long sum=0;
		now|=1<<d;
		for(auto p:m)
			sum+=(long long)p.second*m[p.first^now];
		sum/=2;
		if(sum<=k)
		{
			k-=sum;
			long long tmp=0;
			for(auto p:m)
			{
				auto func=[d](int a,int b){return (a>>d)<(b>>d);};
				auto s1=equal_range(a+1,a+n+1,p.first,func);
				auto s2=equal_range(a+1,a+n+1,p.first^now,func);
				tmp+=calc(s1.first-a,s1.second-a-1,s2.first-a,s2.second-a-1);
			}
			tmp%=mod;
			ans+=(tmp*(mod+1)/2)%mod;
			now^=1<<d;
		}
	}
	cout<<(ans+now*k)%mod<<endl;
}
int main()
{
	init();
	work();
	return 0;
}