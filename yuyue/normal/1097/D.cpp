#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#pragma GCC optimize(2) 
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=1e9+7;
LL n;
int K;
vector<LL> pr;
vector<int> mx;
LL dp[10100][60],inv[110];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int main(){
	cin>>n>>K;
	LL tmp=n;
	for (int i=2;1ll*i*i<=tmp;i++){
		if (tmp%i==0){
			int a=0;
			while (tmp%i==0) tmp/=i,a++; 
			pr.pb(i); mx.pb(a);
		}
	}
	F(i,0,100) inv[i]=fast(i,mod-2);
	if (tmp>1) pr.pb(tmp),mx.pb(1); 
	LL ans=1;
	F(i,0,SZ(pr)){
		LL prime=pr[i],C=mx[i];
		ms(dp,0);
		dp[K][C]=1; 
		DF(j,K-1,0){
			F(k,0,C){
				F(l,k,C){
					dp[j][k]=(dp[j][k]+1ll*dp[j+1][l]*inv[l+1])%mod; 
				}
			}
		}
//		cout<<dp[0][1]<<" "<<dp[0][0]<<" "<<prime<<"\n";
		LL tmp=0;
		F(j,0,C){
			tmp=(tmp+dp[0][j]*fast(prime%mod,j))%mod;
		}
//		cout<<tmp<<"   fuck\n"; 
		ans=ans*tmp%mod;
	}
	cout<<ans<<"\n";
	return 0;
}