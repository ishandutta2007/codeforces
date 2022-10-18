#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,c,a,b,n;
int L(int x)
{
	c=1;
	while(x>=(1ll<<c))
		c++;
	return c;
}
int I(int x)
{
	c=L(x);
	for(int i=0;i<c/2;i++)
		x-=((x>>i&1)-(x>>c-i-1&1))*((1ll<<i)-(1ll<<c-i-1));
	return x;
}
int C(int x)
{
	for(int i=0;i<L(y);i++)
		for(int j=0;j<L(y);j++)
			if(i+j+L(x)<=L(y))
			{
				n=x;
				for(int k=1;k<=i;k++)
					n=n*2+1;
				for(int k=1;k<=j;k++)
					n+=1ll<<L(n);
				if(n==y)
					return 1;
			}
	return 0;
}
signed main()
{
	cin>>x>>y,a=I(x*2),b=I(x*2+1);
	if(x==y||C(a)||C(I(a))||C(b)||C(I(b)))
		cout<<"YES";
	else
		cout<<"NO";
}