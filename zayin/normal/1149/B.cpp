#include<bits/stdc++.h>
#define maxc 26
#define maxm 270
#define maxn 100050
#define inf 0x3f3f3f3f
using namespace std;

int n,q;
char s[maxn];

int nxt[maxn][maxc];

int len[3],st[3]={0,0,0};
char str[3][maxm];

int dp[maxm][maxm][maxm];


void Min(int &a,int b)	{
	a=min(a,b);
}

int main()	{
//	freopen("c.in","r",stdin);
	scanf("%d%d%s",&n,&q,s+1);
	for (int i=0;i<maxc;++i)
		nxt[n][i]=nxt[n+1][i]=n+1;
	for (int i=n-1;~i;--i)	{
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][s[i+1]-'a']=i+1;
	}
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	
	char op[10],ch[10];
	int p;
	while (q--)	{
		scanf("%s%d",op,&p),--p;
		st[p]=len[p];
		if (*op=='+')	{
			scanf("%s",ch);
			str[p][++len[p]]=*ch;
			for (int a=st[0];a<=len[0];++a)
				for (int b=st[1];b<=len[1];++b)
					for (int c=st[2];c<=len[2];++c)	{
						if (a)
							Min(dp[a][b][c],nxt[dp[a-1][b][c]][str[0][a]-'a']);
						if (b)
							Min(dp[a][b][c],nxt[dp[a][b-1][c]][str[1][b]-'a']);
						if (c)
							Min(dp[a][b][c],nxt[dp[a][b][c-1]][str[2][c]-'a']);
					}
		} else	{
			for (int a=st[0];a<=len[0];++a)
				for (int b=st[1];b<=len[1];++b)
					for (int c=st[2];c<=len[2];++c)	{
						dp[a][b][c]=inf;
					}
			--len[p];
		}
		st[p]=0;
		puts(dp[len[0]][len[1]][len[2]]<=n?"YES":"NO");
	}
	return 0;
}