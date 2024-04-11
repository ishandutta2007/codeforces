#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,A;
string s;
signed main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		A=99;
		for(int i=0;i<s.size();i++)
			for(int j=i+1;j<s.size();j++)
				if(((s[i]-'0')*10+s[j]-'0')%25==0)
					A=min(A,(int)s.size()-i-2);
		cout<<A<<'\n';
	}
	return 0;
}