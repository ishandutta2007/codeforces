#include<iostream>
using namespace std;
const int N=1001;
bool v;
int n,x,a[N],A[N][N],c;
int main()
{
	cin>>n;
	for(int i=1;i<=n*n;i++)
	{
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=n/2;i++)
		for(int j=1;j<=n/2;j++)
			for(int k=1;k<N;k++)
				if(a[k]>=4)
					A[i][j]=A[n+1-i][j]=A[i][n+1-j]=A[n+1-i][n+1-j]=k,a[k]-=4,k=N;
	if(n%2==1)
	{
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<N;j++)
				if(a[j]>=2)
					A[n/2+1][i]=A[n/2+1][n+1-i]=j,a[j]-=2,j=N;
		for(int i=1;i<=n/2;i++)
			for(int j=1;j<N;j++)
				if(a[j]>=2)
					A[i][n/2+1]=A[n+1-i][n/2+1]=j,a[j]-=2,j=N;
		for(int i=1;i<N;i++)
			if(a[i]>=1)
				A[n/2+1][n/2+1]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!A[i][j])
				v=true;
	if(v)
		cout<<"NO";
	else
	{
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<A[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}