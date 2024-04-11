#include<iostream>
using namespace std;
const int N=2e5;
const long long D=1e9+7;
int n;
long long l,r,a[3],f[N][3];
int main()
{
	cin>>n>>l>>r;
	while((r-l)%3!=2&&l<=r)
		a[l%3]++,l++;
	for(int i=0;i<3;i++)
		a[i]+=(r-l+1)/3;
	for(int i=0;i<3;i++)
		f[0][i]=a[i];
	for(int k=1;k<n;k++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				(f[k][(i+j)%3]+=f[k-1][i]*a[j])%=D;
	cout<<f[n-1][0];
	return 0;
}