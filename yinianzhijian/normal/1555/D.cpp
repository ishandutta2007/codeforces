#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int n,m;
char s[xx];/*abc acb bac bca cab cba*/
char t[6][3]={'a','b','c','a','c','b','b','a','c','b','c','a','c','a','b','c','b','a'};
int sum[xx][6];
signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<6;j++)
			sum[i][j]=sum[i-1][j]+(s[i]!=t[j][i%3]);
	while(m--)
	{
		int l=read(),r=read();
		int ans=1e9;
		for(int i=0;i<6;i++)ans=min(ans,sum[r][i]-sum[l-1][i]);
		cout<<ans<<'\n';
	}
	return 0;
}