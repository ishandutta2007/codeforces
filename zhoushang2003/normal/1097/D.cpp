#include<iostream>
using namespace std;
const int M=51,K=1e4+1;
const long long D=1e9+7;
int k,c;
long long n,t,a[K][M],s,A=1;
long long P(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		b/=2,(a*=a)%=D;
	}
	return t;
}
int main()
{
	cin>>n>>k;
	for(long long p=2;p*p<=n;p++)
		if(n%p==0)
		{
			c=s=0;
			while(n%p==0)
				n/=p,c++;
			for(int i=0;i<=k;i++)
				for(int j=0;j<=c;j++)
					a[i][j]=0;
			a[0][c]=1;
			for(int i=0;i<k;i++)
				for(int j=0;j<=c;j++)
				{
					t=a[i][j]*P(j+1,D-2);
					for(int l=0;l<=j;l++)
						(a[i+1][l]+=t)%=D;
				}
			for(int i=0;i<=c;i++)
				(s+=a[k][i]*P(p,i))%=D;
			(A*=s)%=D;
		}
	if(n>1)
		(A*=((n-1)%D*P(P(2,k),D-2))%D+1)%=D;
	cout<<A;
	return 0;
}