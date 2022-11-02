#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char ch[N]={},ans[N]={};
int n,m,t[26]={};
int main()
{
	gets(ch+1);
	m=strlen(ch+1);
	for(int i=1;i<=m;++i)
		++t[ch[i]-'a'];
	cin>>n;
	for(int l=1;l<=m;++l)
	{
		int s=0;
		for(int i=0;i<=25;++i)
			s+=(t[i]+l-1)/l;
		if(s<=n)
		{
			cout<<l<<endl;
			int tot=0;
			for(int i=0;i<=25;++i)
				for(int j=1;j<=(t[i]+l-1)/l;++j)
					ans[++tot]=i+'a';
			while(tot<n)
				ans[++tot]='a';
			puts(ans+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}