#include <bits/stdc++.h>
using namespace std;
const int N=200005,mod=1e9+7;
char x[N],y[N];
int Fac[N],Inv[N];
int c00,c01,c10,c11;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
int C(int n,int m){
	if (m>n||m<0)
		return 0;
	return 1LL*Fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}
int calc(int n,int m){
	if (n==0)
		return m==0;
	return C(m+n-1,n-1);
}
int check(char *s){
	int d[2][2];
	memset(d,0,sizeof d);
	int len=strlen(s+1);
	for (int i=1;i<len;i++)
		d[s[i]-'0'][s[i+1]-'0']++;
	return d[0][0]==c00&&d[0][1]==c01&&d[1][0]==c10&&d[1][1]==c11;
}
int solve(char *s,int c00,int c01,int c10,int c11){
	int d=strlen(s+1);
	int D=c00+c01+c10+c11+1;
	if (d<D)
		return 0;
	if (d>D){
		if (c10==c01)
			return 1LL*calc(c10,c00)*calc(c10+1,c11)%mod;
		else if (c10==c01+1)
			return 1LL*calc(c10,c00)*calc(c10,c11)%mod;
		return 0;
	}
//	printf("d=%d\n",d);
	int ans=0;
	for (int i=2;i<=d;i++){
		if (s[i]=='1'){
			int d00=c00,d01=c01,d10=c10,d11=c11;
			if (s[i-1]=='0')
				d00--;
			else
				d10--;
			if (min(d00,d10)>=0){
				if (d10==d01)
					ans=(1LL*calc(d10+1,d00)*calc(d10,d11)+ans)%mod;
				else if (d10+1==d01)
					ans=(1LL*calc(d01,d00)*calc(d01,d11)+ans)%mod;
			}
//			printf("%d %d :: (%d %d %d %d)\n",i,ans,d00,d01,d10,d11);
		}
		if (s[i-1]=='0'&&s[i]=='0')
			c00--;
		if (s[i-1]=='0'&&s[i]=='1')
			c01--;
		if (s[i-1]=='1'&&s[i]=='0')
			c10--;
		if (s[i-1]=='1'&&s[i]=='1')
			c11--;
		if (c00<0||c01<0||c10<0||c11<0)
			break;
	}
	return ans;
}
int main(){
	for (int i=Fac[0]=1;i<N;i++)
		Fac[i]=1LL*Fac[i-1]*i%mod;
	Inv[N-1]=Pow(Fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--)
		Inv[i-1]=1LL*Inv[i]*i%mod;
	scanf("%s%s",x+1,y+1);
	scanf("%d%d%d%d",&c00,&c01,&c10,&c11);
	int v1=solve(y,c00,c01,c10,c11)+check(y);
	int v2=solve(x,c00,c01,c10,c11);
//	printf("%d %d %d\n",v1,v2,check(y));
	printf("%d",(v1-v2+mod)%mod);
	return 0;
}