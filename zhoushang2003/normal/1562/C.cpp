#import<bits/stdc++.h>
using namespace std;
int n,A,B,C,D;
string s;
int main()
{
	for(cin>>n;cin>>n>>s;)
	{
		s=' '+s,A=1,B=n-1,C=2,D=n;
		for(int i=1;i<=n/2;i++)
			if(s[i]=='0')
				A=i,C=i+1,B=D=n;
		for(int i=n/2+1;i<=n;i++)
			if(s[i]=='0')
				A=C=1,B=i,D=i-1;
		cout<<A<<' '<<B<<' '<<C<<' '<<D<<'\n';
	}
}