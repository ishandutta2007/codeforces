#include<bits/stdc++.h>
using namespace std;
long long T,a,b,p,q,l,r,Q,g,x,y;
long long C(long long a,long long b,long long c,long long n)
{
	if(!a||n<=0)
		return b/c*(n+1);
	if(a>=c||b>=c)
		return C(a%c,b%c,c,n)+a/c*(n*(n+1)/2)+b/c*(n+1);
	return (a*n+b)/c*n-C(c,c-b-1,a,(a*n+b)/c-1);
}
void E(int a,int b,long long &x,long long &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	E(b,a%b,y,x),y-=a/b*x;
}
int S(long long r)
{
	r*=x,r+=(a-r)/Q*Q;
	if(r<a)
		r+=Q;
	return r;
}
int main()
{
	cin>>T;
	while(T--&&cin>>a>>b>>p>>q)
	{
		l=0,r=q,p*=2,Q=2*q;
		while(l<r)
			if(C(p,q+(l+r)/2,Q,b)-C(p,q+(l+r)/2,Q,a-1)-C(p,q-(l+r)/2-1,Q,b)+C(p,q-(l+r)/2-1,Q,a-1))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		g=__gcd(p,Q),p/=g,Q/=g,E(p,Q,x,y);
		cout<<min(S((q-l)/g),S((q+l)/g))<<'\n';
	}
	return 0;
}