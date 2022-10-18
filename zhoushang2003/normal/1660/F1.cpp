#include<bits/stdc++.h>
using namespace std;
int t,n,A,c[9999],x;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
	{
		s=' '+s,A=0;
		for(int i=1;i<=n;i++)
			c[i]=c[i-1]+(s[i]=='+'?-1:1);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if((x=c[j]-c[i-1])>=0&&x%3==0)
					A++;
		cout<<A<<'\n';
	}
}