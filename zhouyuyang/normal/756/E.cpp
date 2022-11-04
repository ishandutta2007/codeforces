#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
#define N 300005
using namespace std;
int dp[2][N*20],mx[2];
int a[N],b[N],c[N],s[N];
int n,l,t;
char S[N];
void upd(int t,int x,int v){
	dp[t][x]=(dp[t][x]+v)%mo;
	mx[t]=max(mx[t],x);
}
void Div(int x,int &v){
	ll tmp=0;
	for (int i=l;i;i--){
		tmp=tmp*1000000000+s[i];
		s[i]=tmp/x; tmp%=x;
	}
	v=tmp;
	for (;l>1&&!s[l];l--);
}
int main(){
	scanf("%d",&n);
	a[1]=1;
	for (int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%s",S+1);
	int len=strlen(S+1);
	reverse(S+1,S+len+1); 
	l=len/9+(len%9!=0);
	for (int i=1;i<=l;i++)
		for (int j=min(i*9,len);j>(i-1)*9;j--)
			s[i]=s[i]*10+S[j]-'0';
	a[n+1]=1e9;
	for (int i=1;i<=n;i++)
		if (a[i+1]>1) Div(a[i+1],c[i]);
	if (l!=1||s[1]!=0) return puts("0"),0;
	dp[t][0]=1; dp[t][1]=mo-1; mx[t]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=mx[t];j++)
			dp[t][j]=(dp[t][j]+dp[t][j-1])%mo;
		for (int j=0;j<=mx[t];j++)
			if (dp[t][j]){
				int k=(c[i]-j%a[i+1]+a[i+1])%a[i+1];
				int l=(j+k-c[i])/a[i+1];
				int r=b[i]/a[i+1]+1-(b[i]%a[i+1]<k);
				upd(t^1,l,dp[t][j]);
				upd(t^1,l+r,mo-dp[t][j]);
				dp[t][j]=0;
			}
		mx[t]=0; t^=1;
	}
	printf("%d\n",dp[t][0]);
}