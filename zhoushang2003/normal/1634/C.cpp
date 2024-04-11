#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
		if(k==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				cout<<i<<'\n';
		}
		else if(n&1)
			puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=n;i+=2)
			{
				for(int j=1;j<=k;j++)
					cout<<(i-1)*k+2*j-1<<' ';
				puts("");
				for(int j=1;j<=k;j++)
					cout<<(i-1)*k+2*j<<' ';
				puts("");
			}
		}
}