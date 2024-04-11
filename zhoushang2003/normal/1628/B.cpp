#import<bits/stdc++.h>
using namespace std;
int n,v;
string s;
main()
{
	for(cin>>n;cin>>n;)
	{
		map<string,int>p;
		v=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s,p[s]++,reverse(s.begin(),s.end());
			if(p[s]||s.size()>1&&p[s.substr(0,2)])
				v=1;
			for(char j='a';j<='z';j++)
				if(p[s+j])
					v=1;
		}
		puts(v?"YES":"NO");
	}
}