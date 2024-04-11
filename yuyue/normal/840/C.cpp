#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
using namespace std;
const int M=303,mod=1e9+7;
int n,a[M],b[M];
int fa(int x){
	int ret=1;
	for (int i=2;i*i<=x;i++){
		if (x%i==0){
			int num=0;
			while (x%i==0) x/=i,num++;
			if (num&1) ret=ret*i;
 		}
	}
	ret=ret*x;
	return ret;
}
map<int,int> mp;
int t[M];
LL fac[M],inv[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
void init(){
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;
}
LL C(int x,int y){
	return  fac[x]*inv[y]%mod*inv[x-y]%mod;
}
LL dp[M][M];
int main(){
	cin>>n; init(); int ct=0;
	for (int i=1;i<=n;i++) cin>>a[i],b[i]=fa(a[i]);
	for (int i=1;i<=n;i++){
		if (!mp.count(b[i])) mp[b[i]]=++ct;	
		t[mp[b[i]]]++;	
//		cerr<<b[i]<<" "<<mp[b[i]]<<" "<<t[mp[b[i]]]<<" "<<ct<<"   kk\n";
	}
	dp[0][0]=1;
	int tt=0;
	for (int i=1;i<=ct;i++){
		tt+=t[i];
//		cout<<t[i]<<"  ?? \n";-
		for (int j=1;j<=t[i];j++){
			LL tmp=C(t[i]-1,j-1)*inv[j]%mod;
			for (int l=j;l<=tt;l++){
				dp[i][l]=(dp[i][l]+dp[i-1][l-j]*tmp)%mod;
			}
		}
	}
	LL ans=0;
	F(i,1,n){
		LL tmp=fac[i]*dp[ct][i]%mod;
//		cout<<tmp<<" ?? \n";
		if ((n-i)&1) tmp=mod-tmp;
		ans=(ans+tmp)%mod;
	}
	F(i,1,ct) ans=ans*fac[t[i]]%mod;
	cout<<ans<<"\n";
	return 0;
}