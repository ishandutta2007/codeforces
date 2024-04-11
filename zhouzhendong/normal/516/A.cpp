#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=20,S2=105,S3=60,S5=15,S7=15;
int n,tot[4];
LL dp[S2+1][S3+1][S5+1][S7+1];
int lists[N][4]={
{0,0,0,0},
{0,0,0,0},
{1,0,0,0},
{0,1,0,0},
{2,0,0,0},
{0,0,1,0},
{1,1,0,0},
{0,0,0,1},
{3,0,0,0},
{0,2,0,0}
};
char s[N];
int cntd(LL x){
	int tot=0;
	for (int i=9;i>=2;i--)
		tot+=x&63LL,x>>=6;
	return tot;
}
bool bigger(LL a,LL b){
	int c1=cntd(a),c2=cntd(b);
	if (c1!=c2)
		return c1>c2;
	for (int i=9;i>=2;a>>=6,b>>=6,i--)
		if ((a&63LL)!=(b&63LL))
			return (a&63LL)>(b&63LL);
	return 0;
}
int main(){
	scanf("%d%s",&n,s);
	for (int i=2;i<=9;i++)
		for (int j=0;j<4;j++)
			lists[i][j]+=lists[i-1][j];
	memset(tot,0,sizeof tot);
	for (int i=0;i<n;i++)
		for (int j=0;j<4;j++)
			tot[j]+=lists[s[i]-'0'][j];
	memset(dp,-1LL,sizeof dp);
	dp[0][0][0][0]=0;
	for (int s2=0;s2<=tot[0];s2++)
		for (int s3=0;s3<=tot[1];s3++)
			for (int s5=0;s5<=tot[2];s5++)
				for (int s7=0;s7<=tot[3];s7++)
					for (int i=2;i<=9;i++){
						int t2=s2-lists[i][0];
						int t3=s3-lists[i][1];
						int t5=s5-lists[i][2];
						int t7=s7-lists[i][3];
						if (t2<0||t3<0||t5<0||t7<0)
							continue;
						if (dp[t2][t3][t5][t7]==-1)
							continue;
						LL now=dp[t2][t3][t5][t7]+(1LL<<((9-i)*6));
						if (dp[s2][s3][s5][s7]==-1||bigger(now,dp[s2][s3][s5][s7]))
							dp[s2][s3][s5][s7]=now;
					}
	LL x=dp[tot[0]][tot[1]][tot[2]][tot[3]];
	for (int i=9;i>=2;i--,x>>=6)
		for (int j=0;j<(x&63LL);j++)
			putchar('0'+i);
	return 0;
}