#include<bits/stdc++.h>
using namespace std;
const char C[5]={'a','e','i','o','u'};
int k,n,m;
int main()
{
	cin>>k;
	for(int n=5;n<=k;n++)
		if(k%n==0&&k/n>=5)
		{
			m=k/n;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cout<<C[(i+j)%5];
			return 0;
		}
	cout<<-1;
	return 0;
}