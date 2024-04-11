#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		map<int,int>p;
		for(int i=1;i<=n;i++)
			cin>>a[i],p[a[i]]++;
		if(p[0]&&p[1])
		{
			puts("NO");
			continue;
		}
		A=1;
		for(int i=1;i<=n;i++)
			if(p[a[i]+1]&&p[1])
				A=0;
		puts(A?"YES":"NO");
	}
}