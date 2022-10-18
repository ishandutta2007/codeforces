#include<bits/stdc++.h>
using namespace std;
int n,t,s,d,M=1e9,A;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>d;
		while(s<t)
			s+=d;
		if(s<M)
			M=s,A=i; 
	}
	cout<<A;
	return 0;
}