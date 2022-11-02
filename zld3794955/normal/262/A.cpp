#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
char ch[15]={};
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>(ch+1);
		int l=strlen(ch+1),s=0;
		for(int j=1;j<=l;++j)
			s+=(ch[j]=='4' || ch[j]=='7');
		ans+=s<=k;
	}
	cout<<ans<<endl;
}