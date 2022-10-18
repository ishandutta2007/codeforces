#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,a[N],b[N],q[N],s,t,f[N];
long long V(int i,int j)
{
	return f[j]+a[i]*b[j];
}
double S(int i,int j)
{
	return ((double)f[i]-f[j])/(b[j]-b[i]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	s=1;
	for(int i=1;i<=n;i++)
	{
		while(s<t-1&&V(i,q[s])>V(i,q[s+1]))
			s++;
		f[i]=V(i,q[s]);
		while(t>1&&S(q[t-1],q[t])>S(q[t],i))
			t--;
		q[++t]=i;
	}
	cout<<f[n];
	return 0;
}