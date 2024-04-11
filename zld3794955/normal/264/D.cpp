#include<bits/stdc++.h>
using namespace std;
const int L=1000010;
char s[L]={},t[L]={};
int n,m;
void init()
{
	gets(s+1);
	gets(t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;++i)
		s[i]=s[i]=='R' ? 3 : s[i]=='B' ? 1 : 2;
	for(int i=1;i<=m;++i)
		t[i]=t[i]=='R' ? 3 : t[i]=='B' ? 1 : 2;
}
void work()
{
	long long ans=0;
	int l=1,r=1,tot[4][4]={};
	for(int i=1;i<=n;++i)
	{
		while(r<m && t[r]!=s[i])
			++r,++tot[(int)t[r-1]][(int)t[r]];
		//cout<<"i="<<i<<" l="<<l<<" r="<<r<<" d="<<tot[(int)s[i]][(int)s[i-1]]<<endl;
		ans+=r-l+1;
		if(s[i]!=s[i-1])
			ans-=tot[(int)s[i]][(int)s[i-1]];
		if(l<=m && t[l]==s[i])
			++l,--tot[(int)t[l-1]][(int)t[l]];
		if(r<m)
			++r,++tot[(int)t[r-1]][(int)t[r]];
	}
	cout<<ans<<endl;
}
int main()
{	
	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	init();
	work();
	return 0;
}