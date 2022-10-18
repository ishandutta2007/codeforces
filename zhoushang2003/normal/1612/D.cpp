#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b,x;
int G(int a,int b)
{
	if(a>b)
		swap(a,b);
	if(!a)
		return 0;
	if(b>=x&&(b-x)%a==0)
		return 1;
	return G(a,b%a);
}
signed main()
{
	cin>>t;
	while(t--&&cin>>a>>b>>x)
		cout<<(G(a,b)?"YES":"NO")<<'\n';
}