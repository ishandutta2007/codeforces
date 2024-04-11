#include<bits/stdc++.h>
using namespace std;
int t,n,x,s,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		A=s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			if(x==0)
				A++,s++;
			s+=x;
		}
		cout<<A+(s==0)<<'\n';
	}
	return 0;
}