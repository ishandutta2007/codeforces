#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,x,y,A,p,q;
string s;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
	{
		m=s.size(),s=' '+s,x=y=A=p=q=0;
		for(int i=1;i<=m;i++)
			s[i]=='D'?x++:y++;
		if(x*y==0)
		{
			cout<<n<<'\n';
			continue;
		}
		for(int i=m;i&&p<x&&q<y;i--)
			s[i]=='D'?A+=n-y:A+=n-x,s[i]=='D'?p++:q++;
		cout<<(n-x)*(n-y)+A+m-p-q<<'\n';
	}
}