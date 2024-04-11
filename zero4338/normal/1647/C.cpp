#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=105;
int n,m;
bool a[maxn][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)
		{
			string s;cin>>s;
			for(int j=0;j<m;j++)a[i][j+1]=(s[j]-'0');
		}
		if(a[1][1]){puts("-1");continue;}
		int cnt=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnt+=a[i][j];
		printf("%d\n",cnt);
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j])
				{
					if(i!=1)printf("%d %d %d %d\n",i-1,j,i,j);
					else if(j!=1)printf("%d %d %d %d\n",i,j-1,i,j);
				}
			}
		}
	}
}