#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=3005,mod=1e9+7;
int n;
int a[N];
int dp[N][N];
int lcs[N][N];
char s[26][10]={
"0",
"1",
"00",
"01",
"10",
"11",
"000",
"001",
"010",
"011",
"100",
"101",
"110",
"111",
"0000",
"0001",
"0010",
"0100",
"0110",
"0111",
"1000",
"1001",
"1010",
"1011",
"1100",
"1101"};
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int check(int x,int y,char *s){
	int l=strlen(s);
	if (x+l-1>y)
		return 0;
	For(i,0,l-1)
		if (s[i]-'0'!=a[x+i])
			return 0;
	return 1;
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		For(j,1,n)
			if (a[i]==a[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else
				lcs[i][j]=0;
	For(i,1,n){
		dp[i][i+1]=1;
		Fod(j,i,1)
			For(k,0,25)
				if (check(j,i,s[k]))
					Add(dp[i][j],dp[i][j+strlen(s[k])]);
	}
	int ans=0;
	For(i,1,n){
		int lc=0;
		For(j,1,i-1)
			lc=max(lc,lcs[i][j]);
		For(j,1,i-lc)
			Add(ans,dp[i][j]);
		cout<<ans<<endl;
	}
	return 0;
}