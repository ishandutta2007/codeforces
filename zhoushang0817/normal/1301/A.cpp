#include<bits/stdc++.h>
using namespace std;
bool v;
int t;
string a,b,c;
int main()
{
	cin>>t;
	while(t--&&cin>>a>>b>>c)
	{
		v=false;
		for(int i=0;i<a.size();i++)
			if(a[i]!=c[i]&&b[i]!=c[i])
				v=true;
		if(v)
			cout<<"NO"<<'\n';
		else
			cout<<"YES"<<'\n';
	}
	return 0;
}