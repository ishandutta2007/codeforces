#include<bits/stdc++.h>
using namespace std;
const int N=8,n=7,S=1<<n,mod=1000000007;
struct matrix
{
	long long a[S][S];
}f,ans;
int w[N]={},s=2;
matrix operator*(const matrix &m1,const matrix &m2)
{
	static matrix tmp;
	for(int i=0;i<s;++i)
		for(int j=0;j<s;++j)
			tmp.a[i][j]=0ll;
	for(int i=0;i<s;++i)
		for(int j=0;j<s;++j)
			for(int x=m1.a[i][j],k=0;k<s;++k)
				(tmp.a[i][k]+=x*m2.a[j][k])%=mod;
	return tmp;
}
int main()
{
	for(int i=0;i<S;++i)
		f.a[i][i]=ans.a[i][i]=1;
	for(int t=1;t<=n;++t,s<<=1)
	{
		cin>>w[t];
		for(int i=0;i<s;++i)
			for(int j=0;j<s;++j)
			{
				int tot[N][2]={};
				tot[0][0]=1;
				for(int k=0;k<t;++k)
				{
					tot[k+1][0]=tot[k+1][1]=tot[k][0]+tot[k][1];
					if(!(i&(1<<k)) && !(j&(1<<k)))
						tot[k+1][0]-=tot[k][0];
				}
				f.a[i][j]=tot[t][0];
			}
		for(int y=w[t]; y ; f=f*f,y>>=1)
			if(y&1)
				ans=f*ans;
	}
	cout<<ans.a[0][0]<<endl;
	return 0;
}