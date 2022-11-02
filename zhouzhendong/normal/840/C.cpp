#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
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
const int N=305,mod=1e9+7;
int n;
int a[N],vis[N],s[N];
int v[N],vc=0;
int dp[N][N];
bool check(int x,int y){
	int g=__gcd(x,y);
	x/=g,y/=g;
	int sqx=sqrt(x),sqy=sqrt(y);
	return sqx*sqx==x&&sqy*sqy==y;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int C[N][N],Fac[N];
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	clr(vis);
	For(i,1,n)
		if (!vis[i]){
			int cnt=0;
			For(j,i,n)
				if (!vis[j]&&check(a[i],a[j]))
					vis[j]=1,cnt++;
			v[++vc]=cnt;
			s[vc]=s[vc-1]+v[vc];
		}
//	for (int i=1;i<=vc;i++)printf("%d ",v[i]);puts("");
	for (int i=Fac[0]=1;i<N;i++)
		Fac[i]=(LL)Fac[i-1]*i%mod;
	for (int i=0;i<N;i++)
		C[i][i]=C[i][0]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	clr(dp);
	dp[0][0]=1;
	For(i,1,vc)
		For(j,0,s[i-1]+1)
			if (dp[i-1][j])
				For(k,1,min(v[i],s[i-1]+1))
					For(t,0,min(j,k))
						Add(dp[i][j+(v[i]-k)-t],(LL)dp[i-1][j]*Fac[v[i]]%mod*C[v[i]-1][k-1]%mod*C[j][t]%mod*C[s[i-1]+1-j][k-t]%mod);
//	For(i,0,vc){
//		For(j,0,s[i])
//			printf("%5d ",dp[i][j]);
//		puts("");
//	}
	cout<<dp[vc][0]<<endl;
	return 0;
}