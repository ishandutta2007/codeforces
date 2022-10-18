#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3;
int t,n;
string s[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<n-1;i++)
			cin>>s[i];
		A=s[1];
		for(int i=1;i<n-2;i++)
		{
			if(s[i+1][0]!=s[i][1])
				A+=s[i+1][0];
			A+=s[i+1][1];
		}
		if(A.size()<n)
			A+=A[n-2];
		if(A.size()==n)
			cout<<A<<'\n';
	}
	return 0;
}