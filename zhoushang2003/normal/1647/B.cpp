#include<bits/stdc++.h>
using namespace std;
int t,n,m,A;
string s[999];
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]=' '+s[i];
		A=1;
		for(int i=1;i<n;i++)
			for(int j=1;j<m;j++)
				if((s[i][j]=='1')+(s[i+1][j]=='1')+(s[i][j+1]=='1')+(s[i+1][j+1]=='1')==3)
					A=0;
		puts(A?"YES":"NO");
	}
}