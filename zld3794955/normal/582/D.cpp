#include<bits/stdc++.h>
using namespace std;
const int L=1010,N=4000,mod=1000000007,D=10;
int p,t,m=0,a[N]={};
long long f[2][N][2][2]={};
void init()
{
	char ch[L]={};
	cin>>p>>t>>(ch+1);
	int l=strlen(ch+1),v[N]={},w[N]={};
	for(int i=1;i<=l;++i)
		v[i]=ch[i]-'0';
	reverse(v+1,v+l+1);

	bool flag=true;
	while(flag)
	{
		flag=false;
		long long x=0;
		for(int i=l;i>=1;--i)
		{
			x=x*10+v[i];
			w[i]=x/p;
			x%=p;
		}
		copy(w+1,w+l+1,v+1);
		while(l>0 && v[l]==0)
			--l;
		flag=bool(l);
		a[++m]=x;
	}
	/*
	cout<<"p-base digit:"<<endl;
	for(int i=m;i>=1;--i)
		cout<<a[i]<<' ';
	cout<<endl;
	*/
}
inline long long getsum(long long l,long long r)
{
	return l>r ? 0 : (r+l)*(r-l+1)/2%mod;
}
void work()
{
	if(t>m)
	{
		puts("0");
		return;
	}
	int now=1,pre=0;
	f[now][0][0][0]=getsum(1,a[1]+1);
	f[now][0][1][0]=getsum(a[1]+2,p);
	f[now][1][1][1]=getsum(1,p-2-a[1]);
	f[now][1][0][1]=getsum(p-1-a[1],p-1);
	for(int i=2;i<=m;++i)
	{
		swap(now,pre);
		for(int j=0;j<=i;++j)
			f[now][j][0][0]=f[now][j][0][1]=f[now][j][1][0]=f[now][j][1][1]=0;
		
		for(int d1=0;d1<=1;++d1)
		{
			(f[now][0][0][0]+=f[pre][0][d1][0]*getsum(1,a[i]+1-d1))%=mod;
			(f[now][0][1][0]+=f[pre][0][d1][0]*getsum(a[i]+2-d1,p))%=mod;
		}
		
		for(int j=1;j<=i;++j)
			for(int d1=0;d1<=1;++d1)
				for(int d2=0;d2<=1;++d2)
				{
					(f[now][j][0][0]+=f[pre][j][d1][d2]*getsum(!d2,a[i]-d1+!d2))%=mod;
					(f[now][j][1][0]+=f[pre][j][d1][d2]*getsum(a[i]-d1+!d2+1,p+!d2-1))%=mod;
					(f[now][j][1][1]+=f[pre][j-1][d1][d2]*getsum(d2,p-1-a[i]-!d1+d2))%=mod;
					(f[now][j][0][1]+=f[pre][j-1][d1][d2]*getsum(p-a[i]-!d1+d2,p-1+d2))%=mod;
				}
	}
	long long ans=0;
	for(int i=t;i<=m;++i)
		ans=(ans+f[now][i][0][0])%mod;
	cout<<ans<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}