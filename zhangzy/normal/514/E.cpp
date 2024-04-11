#include<cstdio>
#include<iostream>
#include<cstring>
#define mod 1000000007
using namespace std;
long long q[133]={0};
int n,k,a[133]={0};
struct juzhen{
	long long m[105][105];
}f[31],ans,tem;
juzhen cheng(juzhen t1,juzhen t2)
{
	memset(tem.m,0,sizeof(tem.m));
	long long t;
	for (int i=1;i<=101;i++)
		for (int j=1;j<=101;j++)
		{
			t=0;
			for (int k=1;k<=101;k++)
				t=(t+t1.m[i][k]*t2.m[k][j])%mod;
			tem.m[i][j]=t;
		}
	return tem;
}
int main()
{
	cin>>n>>k;
	int x;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		a[x]++;
	}
	memset(f[0].m,0,sizeof(f[0].m));
	for (int i=1;i<=99;i++)
		f[0].m[i][i+1]=1;
	for (int j=1;j<=100;j++)
		f[0].m[100][j]=a[101-j];
	f[0].m[100][101]=1;
	f[0].m[101][101]=1;
	for (int i=1;i<30;i++)
		f[i]=cheng(f[i-1],f[i-1]);
		
	memset(ans.m,0,sizeof(ans.m));
	q[0]=1;
	for (int i=1;i<=100;i++)
	{
		q[i]=1;
		for (int j=1;j<=i;j++)
			q[i]=(q[i]+a[j]*q[i-j])%mod;
		ans.m[i][1]=q[i];
	}
	ans.m[101][1]=1;
	
	if (k<=100)
	{
		cout<<q[k];
		return 0;
	}
	
	int kk=k-100;
	for (int i=29;i>=0;i--)
	{
		if (kk>=(1<<i))
		{
			kk-=1<<i;
			ans=cheng(f[i],ans);
		}
	}
	cout<<ans.m[100][1];
}