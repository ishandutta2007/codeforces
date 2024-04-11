#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,x,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>x)
	{
		map<int,int>p;
		for(int i=1;i<=n;i++)
			cin>>a[i],p[a[i]]++;
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=n;i++)
			if(p[a[i]])
				p[a[i]*x]?p[a[i]*x]--:A++,p[a[i]]--;
		cout<<A<<'\n';
	}
}