#import<bits/stdc++.h>
using namespace std;
string s;
main()
{
	for(cin>>s;cin>>s;)
	{
		sort(s.begin(),s.end());
		cout<<s<<'\n';
	}
}