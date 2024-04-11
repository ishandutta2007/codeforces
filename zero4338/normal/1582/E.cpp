#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
const int maxm=500;
const ll inf=1e18;
int n,m;
int ans;
int a[maxn];
ll f[maxm][maxn],sum[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);reverse(a+1,a+n+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		m=0;while(m*m+m<=2*n)m++;
		f[1][1]=a[1];for(int i=1;i<=n;i++)f[1][i]=max(f[1][i-1],(ll)a[i]);ans=1;
		for(int i=2;i<=m;i++)
		{
			for(int j=(i*i+i)/2;j<=n;j++)
			{
				f[i][j]=f[i][j-1];
				if(sum[j]-sum[j-i]<f[i-1][j-i]){f[i][j]=max(f[i][j],sum[j]-sum[j-i]);ans=i;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}