#import<bits/stdc++.h>
using namespace std;
int n;
string s;
main()
{
	for(cin>>n;cin>>n>>s;)
	{
		s=s+'~';
		if(s[0]<=s[1])
		{
			cout<<s[0]<<s[0]<<'\n';
			continue;
		}
		for(int i=0;i<n;i++)
			if(s[i]<s[i+1])
			{
				cout<<s.substr(0,i+1);
				for(int j=i;~j;j--)
					cout<<s[j];
				puts(""),i=n;
			}
	}
}