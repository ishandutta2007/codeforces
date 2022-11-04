#include<bits/stdc++.h>
using namespace std;
const int N=205,mo=10007;
struct Mat{
	int n;
	int a[315][315];
	Mat(){
		memset(a,0,sizeof(a));
	}
	friend Mat operator *(const Mat &a,const Mat &b){
		Mat c; c.n=a.n;
		for (int i=0;i<a.n;i++)
			for (int j=0;j<a.n;j++)
				if (a.a[i][j])
					for (int k=0;k<a.n;k++)
						c.a[i][k]=(c.a[i][k]+a.a[i][j]*b.a[j][k])%mo;
		return c;
	}
	friend Mat operator ^(Mat a,int b){
		Mat c; c.n=a.n;
		for (int i=0;i<c.n;i++) c.a[i][i]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) c=c*a;
		return c;
	}
}A,B;
void pre(int times){
	for (int i=0;i<309;i++) A.a[i][i+1]=1;
	for (int i=0;i<205;i++) A.a[i][i]=24;
	for (int i=0;i<105;i++) A.a[205+i][205+i]=25;
	A.n=310; A=A^times;
	for (int i=0;i<310;i++) B.a[i][i+1]=1;
	for (int i=0;i<205;i++) B.a[i][i]=24;
	for (int i=0;i<105;i++) B.a[206+i][206+i]=25;
	B.a[205][205]=26; B.n=311; B=B^times;
}

void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}

int func(int nd24,int nd25,int nd26){
	if (nd26) return B.a[205-nd24][205+nd25];
	return A.a[205-nd24][204+nd25];
}

int dp[N][N][N];
char s[N];
int n,k;
int work(int odd){
	int ans=0;
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=n+1;j++)
			if (i==j+1||i==j+2||(i==j&&odd))
				for (int k=0;k<=102;k++)
					if (dp[i][j][k]!=0){
						int moves=n-(j-i+1)-k;
						int nd25=k,nd24=moves-k,nd26=0;
						if (i>=j+1) nd26++; else nd25++;
						int tmp=func(nd24,nd25,nd26);
						if (odd&&i>=j+1) tmp=tmp*26%mo;
						ans=(ans+tmp*dp[i][j][k])%mo;
					}
	return ans;
}

int main(){
	scanf("%s%d",s+1,&k);
	n=strlen(s+1);
	dp[1][n][0]=1;
	for (int d=n;d>=1;d--)
		for (int i=1,j=d;j<=n;i++,j++)
			for (int k=0;k<=102;k++)
				if (s[i]==s[j])
					upd(dp[i+1][j-1][k+1],dp[i][j][k]);
				else{
					upd(dp[i+1][j][k],dp[i][j][k]);
					upd(dp[i][j-1][k],dp[i][j][k]);
				}
	k+=n; pre(k/2);
	int ans=work(k%2);
	printf("%d",ans);
}