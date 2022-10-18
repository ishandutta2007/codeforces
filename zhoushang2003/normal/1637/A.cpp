#include<bits/stdc++.h>
using namespace std;
int t,n,a[99999],v;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		v=1;
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1])
				v=0;
		puts(v?"NO":"YES");
	}
}