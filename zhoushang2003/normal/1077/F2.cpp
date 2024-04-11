#include<iostream>
using namespace std;
const int N=5e3;
int n,k,x,p[N],s,t;
long long a[N],f[N][N],q[N],M;
int main()
{
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<k;i++)
		f[i][0]=a[i];
	for(int i=1;i<x;i++)
	{
		s=t=0,p[t]=i-1,q[t++]=f[i-1][i-1];
		for(int j=i;j<min(n,(i+1)*k);j++)
		{
			while(s<t&&p[s]+k<j)
				s++;
			f[j][i]=q[s]+a[j];
			while(s<t&&q[t-1]<f[j][i-1])
				t--;
			p[t]=j,q[t++]=f[j][i-1];
		}
	}
	for(int i=n-k;i<n;i++)
		M=max(M,f[i][x-1]);
	if(M==0)
		cout<<-1;
	else
		cout<<M;
	return 0;
}