#include<iostream>
using namespace std;
const long long D=1e6+3,V=500002;
long long n,k,t,l,r,A=1,B,c;
long long P(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
int main()
{
	cin>>n>>k;
	if(n<61&&k>((long long)1<<n))
	{
		cout<<1<<" "<<1;
		return 0;
	}
	k--;
	r=P(2,n)-1,l=max(r-k+1,(long long)0);
	for(int i=l;i<=r;i++)
	{
		t=r-i+1;
		while(t%2==0)
			(A*=V)%=D,t/=2;
		(A*=i)%=D;
	}
	t=2;
	while(t<=k)
		c+=k/t,t*=2;
	B=P(P(2,n),k)*P(V,c)%D;
	cout<<(B-A+D)%D<<" "<<B;
	return 0;
}