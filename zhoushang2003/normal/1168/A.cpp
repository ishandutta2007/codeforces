#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1,I=1e9;
int n,m,a[N],l,r,x,y;
bool C(int k)
{
	x=0;
	if(a[1]+k<m)
		x=a[1];
	for(int i=2;i<=n;i++)
	{
		y=I;
		if(a[i]+k>=m&&(a[i]+k)%m>=x)
			y=x;
		if(a[i]+k>=x)
			y=min(y,max(a[i],x));
		if(y>=m)
			return false;
		x=y;
	}
	return true;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	r=N;
	while(l<r)
		if(C((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	cout<<l;
	return 0;
}