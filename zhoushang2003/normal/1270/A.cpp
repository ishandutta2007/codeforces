#include<bits/stdc++.h>
using namespace std;
const int N=101;
int t,n,a,b,x[N],y[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n>>a>>b)
	{
		for(int i=1;i<=a;i++)
			cin>>x[i];
		for(int i=1;i<=b;i++)
			cin>>y[i];
		for(int i=1;i<=a;i++)
			if(x[i]==n)
				cout<<"YES"<<'\n';
		for(int i=1;i<=b;i++)
			if(y[i]==n)
				cout<<"NO"<<'\n';
	}
	return 0;
}