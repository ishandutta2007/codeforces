#include<bits/stdc++.h>
using namespace std;
#define int long long
char y;
int n,m,A,x;
string s;
int C(int x)
{
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
signed main()
{
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)
		A+=C(i);
	while(m--&&cin>>x>>y)
	{
		for(int i=x-2;i<=x;i++)
			if(0<i&&i<=n-2)
				A-=C(i);
		s[x]=y;
		for(int i=x-2;i<=x;i++)
			if(0<i&&i<=n-2)
				A+=C(i);
		cout<<A<<'\n';
	}
}