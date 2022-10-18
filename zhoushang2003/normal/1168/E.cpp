#include<bits/stdc++.h>
using namespace std;
const int N=4096;
int n,a[N],x,p[N],q[N],P[N],Q[N],k;
int main()
{
	cin>>n,n=1<<n;
	for(int i=0;i<n;i++)
		cin>>a[i],x^=a[i],p[i]=q[i]=P[i]=Q[i]=i;
	if(x)
	{
		cout<<"Fou";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		x=i;
		while((p[x]^q[x])!=a[x])
		{
			k=P[a[x]^q[x]],swap(P[p[x]],P[p[k]]),swap(p[x],p[k]);
			if(k>i)
				break;
			swap(Q[q[k]],Q[q[i+1]]),swap(q[k],q[i+1]),x=k;
		}
	}
	cout<<"Shi"<<'\n';
	for(int i=0;i<n;i++)
		cout<<p[i]<<' ';
	cout<<'\n';
	for(int i=0;i<n;i++)
		cout<<q[i]<<' ';
	return 0;
}