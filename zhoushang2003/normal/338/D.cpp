#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
long long n,m,k,a[N],X,Y,d,x,y,t;
void O()
{
	cout<<"NO";
	exit(0);
}
long long E(long long a,long long b,long long &x,long long &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	long long A=E(b,a%b,x,y);
	t=x,x=y,y=t-a/b*x;
	return A;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	X=a[1];
	if(X>n)
		O();
	for(int i=2;i<=k;i++)
	{
		d=E(X,a[i],x,y);
		if((Y+i-1)%d!=0)
			O();
		x=x*(-Y-i+1)/d%(a[i]/d),Y+=x*X,X=X/d*a[i];
		if(X>n)
			O();
		Y=(Y%X+X)%X;
	}
	if(!Y)
		Y=X;
	if(Y+k-1>m)
		O();
	for(int i=1;i<=k;i++)
		if(__gcd(X,Y+i-1)!=a[i])
			O();
	cout<<"YES";
	return 0;
}