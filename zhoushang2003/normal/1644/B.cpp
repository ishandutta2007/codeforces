#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
		if(n==3)
			cout<<"3 2 1\n1 3 2\n3 1 2\n";
		else
			for(int i=1;i<=n;i++,cout<<'\n')
				for(int j=1;j<=n;j++)
					cout<<(n-j+i)%n+1<<' ';
}