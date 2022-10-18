#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,p[N],x,y,l,r,f[N],d;
bool C(int k,int x)
{
	f[0]=1;
	if(x)
		f[x]=max(k+1,p[1]+1);
	for(int i=max(1,x+1);i<n;i++)
	{
		if(f[i-1]>=p[i])
			f[i]=p[i]+k+1;
		else if(f[i-1]>=p[i]-k)
			f[i]=p[i]+1,d=min(d,p[i]-k);
		else
			f[i]=f[i-1];
		if(i>1&&f[i-2]>=p[i]-k)
			f[i]=max(f[i],p[i-1]+k+1);
	}
	return f[n-1]>=min(m,m+p[x]-k);
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<n;i++)
		cin>>p[i];
	x=m-p[n-1]+p[0];
	for(int i=0;i<n-1;i++)
		if(p[i+1]-p[i]>x)
			x=p[i+1]-p[i],y=i+1;
	rotate(p,p+y,p+n),r=m;
	for(int i=n-1;i>=0;i--)
		if((p[i]-=p[0])<0)
			p[i]+=m;
	while(l<r)
		if(C((l+r)/2,-1)||C((l+r)/2,0)||C((l+r)/2,1))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	cout<<l;
	return 0;
}