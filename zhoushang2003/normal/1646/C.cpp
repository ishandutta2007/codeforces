#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,p[99],n,A,s,c;
signed main()
{
	cin>>t,p[0]=1;
	for(int i=1;i<15;i++)
		p[i]=i*p[i-1];
	while(t--&&cin>>n)
	{
		A=99;
		for(int i=0;i<(1<<15);i++)
		{
			s=c=0;
			for(int j=0;j<15;j++)
				if(i>>j&1)
					s+=p[j],c++;
			if(s<=n)
				A=min(A,c+__builtin_popcountll(n-s));
		}
		cout<<A<<'\n';
	}
}