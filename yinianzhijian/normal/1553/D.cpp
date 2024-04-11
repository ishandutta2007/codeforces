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
const int xx=1e5+5;
char s[xx],t[xx];
signed main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		int n,m;
		n=strlen(s+1);
		m=strlen(t+1);
		reverse(s+1,s+n+1);
		reverse(t+1,t+m+1);
		int tt=1,top=1;
		while(top<=n)
		{
			if(s[top]==t[tt])
			{
				tt++,top++;
				if(tt==m+1)break;
			}
			else top+=2;
		}
		if(tt==m+1)puts("YES");
		else puts("NO");
	}
	return 0;
}