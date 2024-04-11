#include<bits/stdc++.h>
using namespace std;
int n,s,x,c[6],A=1e9,t,I,J,K;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		c[x]++;
	}
	for(int i=s/n;i>=0;i--)
		for(int j=(s-c[3]*i)/(n-c[3]);j>=i;j--)
		{
			int k=(s-c[3]*i-c[4]*j)/c[5];
			if(k*c[5]-j*c[4]>=A)
				break;
			if(i*c[3]+j*c[4]+k*c[5]==s&&A>(t=abs(i*c[3]-j*c[4])+abs(j*c[4]-k*c[5])))
				A=t,I=i,J=j,K=k;
		}
	if(A!=1e9)
		cout<<I<<" "<<J<<" "<<K;
	else 
		cout<<-1;
	return 0;
}