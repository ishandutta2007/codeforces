#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[999999];
string S;
main()
{
	for(cin>>n;cin>>n>>m>>S;)
	{
		S=' '+S+S;
		for(int i=1;i<2*n;i++)
			s[i]=s[i-1]+(S[i]=='1');
		if(m*s[n]%n!=0)
		{
			puts("-1");
			continue;
		}
		for(int i=m;i<2*n;i++)
			if(s[i]-s[i-m]==m*s[n]/n)
				if(i<=n)
					cout<<"1 "<<i-m+1<<' '<<i<<'\n',i=2*n;
				else
					cout<<"2 1 "<<i-n<<' '<<i-m+1<<' '<<n<<'\n',i=2*n;
	}
}