#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N]={};
bool b[N]={};
long long k,f[N]={};
int main()
{	
	cin>>n>>k;
	f[0]=f[1]=1;
	for(int i=2;i<=n;++i)
		f[i]=f[i-1]+f[i-2];
	int p=1;
	while(p<=n)
	{
		if(k<=f[n-p])
		{
			cout<<p<<' ';
			++p;
		}
		else
		{
			k-=f[n-p];
			cout<<p+1<<' '<<p<<' ';
			p+=2;
		}
	}
	cout<<endl;
	return 0;
}