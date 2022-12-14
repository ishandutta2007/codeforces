#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,I=1e9;
int n,m,c,A=-1,B,a[N]; 
int main()
{
	cin>>n>>m;
	if(n==1||n==2)
	{
		if(m==0)
			for(int i=1;i<=n;i++)
				cout<<i<<' ';
		else
			cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		c+=(i-1)/2;
		if(c<m)
			A=i;
	}
	if(c<m)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=A;i++)
		for(int j=i+1;j<=A;j++)
		{
			a[i+j]++;
			if(i+j<=A)
				B++;
		}
	for(int i=1;i<=A;i++)
		cout<<i<<' ';
	for(int i=A+1;i<=2*A;i++)
		if(a[i]+B==m)
		{
			cout<<i<<' ';
			break;
		}
	for(int i=A+2;i<=n;i++)
		cout<<I-(n-i)*5000<<' ';
	return 0;
}