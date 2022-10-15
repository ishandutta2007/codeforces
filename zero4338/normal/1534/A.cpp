#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=55;
int n,m;
char s[maxn][maxn];
int r,w;
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		r=w=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='R')r=i+j;
				if(s[i][j]=='W')w=i+j;
			}
		bool flag=1;
		if(r&&w&&((r&1)==(w&1)))flag=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='R'&&((i+j)&1)!=(r&1))flag=0;
				if(s[i][j]=='W'&&((i+j)&1)!=(w&1))flag=0;
			}
		if(!flag){printf("NO\n");continue;}
		printf("YES\n");
		if(r){for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%c",(((i+j)&1)==(r&1))?'R':'W');printf("\n");}}
		else if(w){for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%c",(((i+j)&1)==(w&1))?'W':'R');printf("\n");}}
		else {for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%c",((i+j)&1)?'R':'W');printf("\n");}}
	}
	return 0;
}