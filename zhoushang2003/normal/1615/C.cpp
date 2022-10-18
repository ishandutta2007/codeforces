#include<bits/stdc++.h>
using namespace std;
const int I=1e9;
string s,t;
int T,n,x,y,z,A;
int main()
{
	cin>>T;
	while(T--&&cin>>n>>s>>t)
	{
		x=y=z=0,A=I;
		for(int i=0;i<n;i++)
			x+=s[i]-'0',y+=t[i]-'0',z+=s[i]!=t[i];
		if(x==y)
			A=z;
		if(x==n-y+1)
			A=min(A,n-z);
		cout<<(A==I?-1:A)<<'\n';
	}
}