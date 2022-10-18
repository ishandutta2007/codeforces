#include<iostream>
using namespace std;
const int N=1000;
int n,k,x;
long long a[N],f[N][N],M;
int main()
{
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(i<k)
			f[i][1]=a[i];
		for(int j=1;j<n;j++)
			if(f[i][j]>0)
				for(int l=i+1;l<=i+k;l++)
					f[l][j+1]=max(f[l][j+1],f[i][j]+a[l]);
	}
	for(int i=n-k;i<n;i++)
		M=max(M,f[i][x]);
	if(M==0)
		cout<<-1;
	else
		cout<<M;
	return 0;
}