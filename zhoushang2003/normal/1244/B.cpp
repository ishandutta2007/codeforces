#import<bits/stdc++.h>
using namespace std;
int n,A;
string s;
main()
{
	for(cin>>n;cin>>n>>s;)
	{
		A=n,s=' '+s;
		for(int i=1;i<=n;i++)
			if(s[i]=='1')
				A=max(A,2*max(i,n-i+1));
		cout<<A<<'\n';
	}
}