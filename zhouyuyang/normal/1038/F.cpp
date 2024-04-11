#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=55; 
int n,m,ch[N][2],nxt[N],f[N][N][N],ans;
char st[N];
signed main()
{
	scanf("%d%s",&n,st+1);
	m=strlen(st+1);
	for (int i=1;i<=m;i++)ch[i-1][st[i]-'0']=i;
	for (int i=1;i<=m;i++)
	 for (int j=0;j<=1;j++)
	  if (ch[i][j]) nxt[ch[i][j]]=ch[nxt[i]][j];
	  else ch[i][j]=ch[nxt[i]][j];
	ans=1ll<<n;
	for (int i=0;i<m;i++)
	 {
		memset(f,0,sizeof(f));
		f[0][0][i]=1;
		for (int j=0;j<n;j++)
		 for (int k=0;k<m;k++)
		  for (int l=0;l<m;l++)
		   if (f[j][k][l])
		    {
				for (int p=0;p<=1;p++)
				 {
					int x=ch[k][p],y=ch[l][p];
					if (x!=m&&y!=m)f[j+1][x][y]+=f[j][k][l];
				 }
			}
		for (int j=0;j<m;j++)ans-=f[n][i][j];
	 }
	printf("%I64d",ans);
}