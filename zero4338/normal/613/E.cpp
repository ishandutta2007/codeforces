#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define ll long long
#define ull unsigned long long
using namespace std;
const ull p=1331;
const int maxn=2e3+5;
const int mod=1e9+7;
int n,slen;
int ans1,ans2;
char gr[2][maxn],s[maxn];
ull ppow[maxn<<1],gpre[2][maxn],gsuf[2][maxn],ssum[maxn];
int f[2][maxn][maxn],g[2][maxn][maxn];
void calc()
{
	for(int i=1;i<=slen;i++)ssum[i]=ssum[i-1]*p+s[i]-'a'+1;memset(f,0,sizeof f);memset(g,0,sizeof g);
	for(int i=1;i<=n;i++)
	{
		if(gr[0][i]==s[1])g[0][i][1]=1;if(gr[1][i]==s[1])g[1][i][1]=1;
		for(int j=1;j<=i;j++)
		{
			int len=(i-j+1)*2;if(len>slen)continue;
			ull up,down,val;
			up=gpre[0][i]-gpre[0][j-1]*ppow[i-j+1];down=gsuf[1][j]-gsuf[1][i+1]*ppow[i-j+1];val=down*ppow[i-j+1]+up;
			if(val==ssum[len]){if(len==slen)ans2++;else g[0][i][len]=1;}
			up=gsuf[0][j]-gsuf[0][i+1]*ppow[i-j+1];down=gpre[1][i]-gpre[1][j-1]*ppow[i-j+1];val=up*ppow[i-j+1]+down;
			if(val==ssum[len]){if(len==slen)ans2++;else g[1][i][len]=1;}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=slen;j++)
		{
			if(gr[0][i+1]==s[j+1])f[0][i+1][j+1]=((ll)f[0][i+1][j+1]+g[0][i][j]+f[0][i][j])%mod;
			if(gr[1][i]==s[j+1])g[1][i][j+1]=(g[1][i][j+1]+f[0][i][j])%mod;
			if(gr[1][i+1]==s[j+1])f[1][i+1][j+1]=((ll)f[1][i+1][j+1]+g[1][i][j]+f[1][i][j])%mod;
			if(gr[0][i]==s[j+1])g[0][i][j+1]=(g[0][i][j+1]+f[1][i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(gr[0][i]==s[slen])ans1=((ll)ans1+f[0][i-1][slen-1]+g[0][i-1][slen-1]+(slen==1))%mod;
		if(gr[1][i]==s[slen])ans1=((ll)ans1+f[1][i-1][slen-1]+g[1][i-1][slen-1]+(slen==1))%mod;
		for(int j=i;j<=n;j++)
		{
			int len=(j-i+1)*2;if(len>slen)break;
			ull up,down,val;
			up=gpre[0][j]-gpre[0][i-1]*ppow[j-i+1];down=gsuf[1][i]-gsuf[1][j+1]*ppow[j-i+1];val=up*ppow[j-i+1]+down;
			if(val==ssum[slen]-ssum[slen-len]*ppow[len])
			{if(len==slen&&slen!=2)ans2++;else ans1=((ll)ans1+f[0][i-1][slen-len]+g[0][i-1][slen-len])%mod;}
			up=gsuf[0][i]-gsuf[0][j+1]*ppow[j-i+1];down=gpre[1][j]-gpre[1][i-1]*ppow[j-i+1];val=down*ppow[j-i+1]+up;
			if(val==ssum[slen]-ssum[slen-len]*ppow[len])
			{if(len==slen&&slen!=2)ans2++;else ans1=((ll)ans1+f[1][i-1][slen-len]+g[1][i-1][slen-len])%mod;}
		}
	}
}
int main()
{
	scanf("%s%s%s",gr[0]+1,gr[1]+1,s+1);n=strlen(gr[0]+1);slen=strlen(s+1);
	ppow[0]=1;
	for(int i=1;i<=2*n;i++)ppow[i]=ppow[i-1]*p;
	for(int i=1;i<=n;i++){gpre[0][i]=gpre[0][i-1]*p+gr[0][i]-'a'+1;gpre[1][i]=gpre[1][i-1]*p+gr[1][i]-'a'+1;}
	for(int i=n;i>=1;i--){gsuf[0][i]=gsuf[0][i+1]*p+gr[0][i]-'a'+1;gsuf[1][i]=gsuf[1][i+1]*p+gr[1][i]-'a'+1;}
	calc();reverse(s+1,s+slen+1);calc();ans1=(ans2/2+ans1)%mod;if(slen==1)ans1/=2;
	printf("%d",ans1);
	return 0;
}