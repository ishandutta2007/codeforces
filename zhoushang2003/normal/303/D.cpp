#include<bits/stdc++.h>
using namespace std;
long long t,n,x;
void C(int b,int n)
{
	t=1;
	for(int i=2;i<n;i++)
	{
		(t*=b)%=n;
		if(t==1)
			return;
	}
	cout<<b;
	exit(0);
}
int main()
{
	cin>>n>>x,n++;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
		{
			cout<<-1;
			return 0;
		}
	for(int i=x-1;i>1;i--)
		if(i%n!=0)
			C(i,n);
	cout<<-1;
	return 0;
}