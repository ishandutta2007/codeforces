#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1005;
char s[xx],t[xx];
int n,m;
bool check(int x)
{
	int tt=2;
	for(int i=x;i<n;i++)
	{
		int ss=tt;
		if(ss==m+1)return 1;
		for(int j=i-1;j>=1;j--)
		{
			if(s[j]==t[ss])ss++;
			else break;
			if(ss==m+1)return 1;
		}
		if(s[i+1]!=t[tt])return 0;
		tt++;
	}
//	puts("qwewqe");
	int i=n;
	int ss=tt;
	if(ss==m+1)return 1;
	for(int j=i-1;j>=1;j--)
	{
		if(s[j]==t[ss])ss++;
		else return 0;
		if(ss==m+1)return 1;
	}
	return 0;
}
signed main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1),m=strlen(t+1);
		int vs=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=t[1])continue;
			if(check(i))
			{
//				cout<<i<<'\n';
				vs=0;
				break;
			}
		}
		if(vs)puts("NO");
		else puts("YES");
	}
	return 0;
}