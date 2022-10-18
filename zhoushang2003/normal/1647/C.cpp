#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,m,c,A[N],B[N],C[N],D[N];
string s[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]=' '+s[i];
		if(s[1][1]=='1')
		{
			puts("-1");
			continue;
		}
		c=0;
		for(int i=1;i<=n;i++)
			for(int j=m;j>1;j--)
				if(s[i][j]=='1')
					A[++c]=i,B[c]=j-1,C[c]=i,D[c]=j;
		for(int i=n;i;i--)
			if(s[i][1]=='1')
				A[++c]=i-1,B[c]=D[c]=1,C[c]=i;
		cout<<c<<'\n';
		for(int i=1;i<=c;i++)
			cout<<A[i]<<' '<<B[i]<<' '<<C[i]<<' '<<D[i]<<'\n';
	}
}