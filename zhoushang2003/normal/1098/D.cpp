#import<bits/stdc++.h>
using namespace std;
#define int long long
char o;
int n,m,x,l,c[99],A,s;
multiset<int>p[99];
main()
{
	cin>>m;
	while(m--&&cin>>o>>x)
	{
		l=log2(x),A=s=0;
		if(o=='+')
			p[l].insert(x),c[l]+=x,n++;
		else
			p[l].erase(p[l].find(x)),c[l]-=x,n--;
		for(int i=0;i<99;i++)
			if(p[i].size())
				A+=(*p[i].begin()>2*s),s+=c[i];
		cout<<n-A<<'\n';
	}
}