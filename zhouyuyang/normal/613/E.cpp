#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define Rep(i,j,k) for (int i=j;i>=k;i--)
using namespace std;
const int N=2005;
const int mo=1000000007;
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
char s[2][N],t[N];
int n,m,ans,f[N][N][2];
int lcp[2][N][N],lcs[2][N][N];
void calc(bool count){
	For(k,0,1) Rep(i,n,1) Rep(j,m,1)
		lcp[k][i][j]=(s[k][i]==t[j]?lcp[k][i+1][j+1]+1:0);
	reverse(t+1,t+m+1);
	For(k,0,1) Rep(i,n,1) Rep(j,m,1)
		lcs[k][i][j]=(s[k][i]==t[j]?lcs[k][i+1][j+1]+1:0);
	reverse(t+1,t+m+1);
	memset(f,0,sizeof(f));
	For(i,1,n+1){
		For(k,0,1) f[i][1][k]=1;
		For(j,2,i-1)
			if (!count||j*2<m)
				For(k,0,1)
					if (lcp[k][i-j][j+1]>=j&&lcs[!k][i-j][m-j+1]>=j)
						upd(f[i][2*j+1][k],1);
		For(j,1,m) For(k,0,1)
			if (i<=n&&f[i][j][k]&&s[k][i]==t[j]){
				upd(f[i+1][j+1][k],f[i][j][k]);
				if (j+1<=m&&s[!k][i]==t[j+1])
					upd(f[i+1][j+2][!k],f[i][j][k]);
				if ((m-j+1)>2&&(m-j+1)%2==0&&(!count||j>1)){
					int l=(m-j+1)/2;
					if (lcp[k][i][j]>=l&&lcs[!k][i][1]>=l)
						upd(ans,f[i][j][k]);
				}
			}
		For(k,0,1) upd(ans,f[i][m+1][k]);
	}
}
int main(){
	For(i,0,1) scanf("%s",s[i]+1);
	scanf("%s",t+1);
	n=strlen(s[0]+1);
	m=strlen(t+1);
	calc(false);
	if (m!=1){
		reverse(t+1,t+m+1);
		calc(true);
	}
	if (m==2){
		for (int i=1;i<=n;i++)
			if (s[0][i]==t[1]&&s[1][i]==t[2])
				ans--;
		for (int i=1;i<=n;i++)
			if (s[1][i]==t[1]&&s[0][i]==t[2])
				ans--;
	}
	printf("%d",(ans+mo)%mo);
}