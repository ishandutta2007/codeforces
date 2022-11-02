#include<bits/stdc++.h>
using namespace std;
const int N=2020,mod=1000000007;
int R=1000,n,m,r,x[N]={},y[N]={},b[N]={},C[N][N]={};
int s[N][N]={};
int query(int xl,int yl,int xr,int yr)
{
	xl=max(1,xl);
	yl=max(1,yl);
	xr=min(R,xr);
	yr=min(R,yr);
	if(xl>xr || yl>yr)
		return 0;
	return s[xr][yr]-s[xl-1][yr]-s[xr][yl-1]+s[xl-1][yl-1];
}
long long ans=0;
int main()
{
	cin>>n>>m>>r;
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i]>>b[i];
		++s[x[i]][y[i]];
	}
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=1;i<=R;++i)
		for(int j=1;j<=R;++j)
			s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;++i)
	{
		int inc=query(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
		(ans+=(b[i]*1ll*b[i])%mod*((C[n][m]+mod-C[n-inc][m])%mod)%mod)%=mod;
		//cout<<"i="<<i<<" inc="<<inc<<" ans="<<ans<<endl;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
		{
			int inc1=query(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
			int inc2=query(x[j]-r,y[j]-r,x[j]+r,y[j]+r);
			int inc=query(	max(x[i],x[j])-r,max(y[i],y[j])-r,
							min(x[i],x[j])+r,min(y[i],y[j])+r);
			//cout<<"i="<<i<<" j="<<j<<" inc1="<<inc1<<" inc2="<<inc2<<" inc="<<inc<<endl;
			(ans+=(2ll*b[i]*b[j])%mod*
				((C[n][m]+0ll-C[n-inc1][m]-C[n-inc2][m]
				+C[n-(inc1+inc2-inc)][m]+mod+mod)%mod)%mod)%=mod;			
		}
	cout<<ans<<endl;
}