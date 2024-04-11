#include<bits/stdc++.h>
using namespace std;
const int L=100100,M=30;
long long a[M]={};
char ch[L]={};
map<long long,int> m[M];
int main()
{	
	for(int i=0;i<26;++i)
		cin>>a[i];
	cin>>(ch+1);
	int l=strlen(ch+1);
	long long v=0,ans=0;
	for(int i=1;i<=l;++i)
	{
		ans+=m[ch[i]-'a'][v];
		v+=a[ch[i]-'a'];
		++m[ch[i]-'a'][v];
	}
	cout<<ans<<endl;
	return 0;
}