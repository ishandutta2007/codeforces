#include <bits/stdc++.h>
using namespace std;
const int N=2005,M=200005,mod=1e9+7;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,X,Y,Fac[M],Inv[M];
int dp[N];
struct Point{
	int x,y;
}p[N];
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
bool cmp(Point a,Point b){
	if (a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
void HASH(){
	sort(p+1,p+n+1,cmp);
	int _n=1;
	for (int i=2;i<=n;i++)
		if (p[i].x!=p[i-1].x||p[i].y!=p[i-1].y)
			p[++_n]=p[i];
	n=_n;
}
int main(){
	Fac[0]=Inv[0]=1;
	for (int i=1;i<M;i++){
		Fac[i]=1LL*Fac[i-1]*i%mod;
		Inv[i]=Pow(Fac[i],mod-2);
	}
	X=read(),Y=read(),n=read();
	for (int i=1;i<=n;i++)
		p[i].x=read(),p[i].y=read();
	n++;
	p[n].x=X,p[n].y=Y;
	HASH();
	memset(dp,0,sizeof dp);
	for (int i=1;i<=n;i++){
		int x=p[i].x,y=p[i].y;
		dp[i]=C(x+y-2,x-1);
		for (int j=0;j<i;j++)
			if (p[j].x<=p[i].x||p[j].y<=p[i].y){
				int xj=p[j].x,yj=p[j].y;
				dp[i]=(-1LL*dp[j]*C(x+y-xj-yj,x-xj)+dp[i])%mod;
			}
	}
	printf("%d",(dp[n]+mod)%mod);
	return 0;
}