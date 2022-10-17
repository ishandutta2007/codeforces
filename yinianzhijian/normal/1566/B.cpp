#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
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
char s[xx];
signed main(){
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),ans=2;
		int vis=1;
		for(int i=1;i<=n;i++)if(s[i]=='0')vis=0;
		if(vis)
		{
			puts("0");
			continue;
		}
		vis=1;
		for(int i=1;i<=n;i++)if(s[i]=='1')vis=0;
		if(vis)
		{
			puts("1");
			continue;
		}
		int np=1;
		while(s[np]=='1')np++;
		vis=1;
		int ed=n;
		while(s[ed]=='1')ed--;
		for(int i=np;i<=ed;i++)
		{
			if(s[i]=='1')vis=0;
		}
		if(vis)
		{
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}