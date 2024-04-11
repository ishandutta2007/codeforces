#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,k,a[N],b[N],t,x,p,s,A[N],C,c;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		b[i]=a[i];
	sort(b,b+n),t=b[n-m*k];
	for(int i=0;i<n;i++)
		if(a[i]>t)
			x++;
	for(int i=0;i<n;i++)
		if(a[i]==t&&x<m*k)
			x++;
		else if(a[i]==t)
			a[i]=-2e9;
	for(int i=0;i<k;i++)
	{
		c=0;
		while(c<m)
			if(a[p]>=t)
				s+=a[p++],c++;
			else
				p++;
		A[C++]=p;
	}
	cout<<s<<endl; 
	for(int i=0;i<k-1;i++)
		cout<<A[i]<<" ";
	return 0;
}