#include<bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;

ll T,n,m,SG[N];
char str[N];

ll ask(ll u)
{
	if(u<=1) return 0;
	if(SG[u]!=-1) return SG[u];
	if(u>200) return SG[u]=ask(u-34);
	ll i;
	map<ll,bool>mm;
	for(i=0;i<=u-2;i++)
	{
		mm[ask(i)^ask(u-i-2)]=1;
	}
	for(i=0;mm.count(i);i++);
	return SG[u]=i;
}

int main()
{
	memset(SG,-1,sizeof(SG));
	ll i,j;
	cin>>T;
	while(T--)
	{
		ll R,B,ans;
		ans=R=B=0;
		scanf("%lld%s",&n,str+1);
		for(i=1;i<=n;i++)
		{
			if(str[i]=='R') R++;
			else if(str[i]=='B') B++;
		}
		if(R>B)
		{
			puts("Alice");
			continue;
		}
		if(R<B)
		{
			puts("Bob");
			continue;
		}
		for(i=1;i<=n;i=j)
		{
			for(j=i+1;j<=n && str[j]!=str[j-1];j++);
//			cout<<" "<<j-i<<endl;
			ans^=ask(j-i);
		}
		puts(ans?"Alice":"Bob");
	}
}