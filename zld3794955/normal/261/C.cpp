#include<bits/stdc++.h>
using namespace std;
const int N=60;
long long n,t,f[N][N]={};
int main()
{	
	cin>>n>>t;
	bool flag=false;
	for(int d=0;d<=50;++d)
		if((1ll<<d)==t)
		{
			flag=true,t=d;
			break;
		}
	if(!flag)
	{
		puts("0");
		return 0;
	}
	++t,n+=2;
	f[0][0]=1;
	for(int i=1;(1ll<<i)<=n;++i)
	{
		f[i][0]=f[i][i]=1;
		for(int j=1;j<i;++j)
			f[i][j]=f[i-1][j-1]+f[i-1][j];
	}
	long long sum=t==1 ? -1 : 0;
	for(int d=50;d>=0;--d)
		if((1ll<<d)<=n)
		{
			if(t>=0)
				sum+=f[d][t];
			//cout<<"d="<<d<<" t="<<t<<endl;
			--t;
			n-=1ll<<d;
		}
	cout<<sum<<endl;
	return 0;
}