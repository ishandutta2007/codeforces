#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
#pragma GCC optimize(2)
#pragma GCC target("avx") 
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int P[M],ct;
bool p[M];
void sieve(int n){
	for (int i=2;i<=n;i++){
		if (!p[i]) P[++ct]=i;
		for (int j=1;j<=ct&&P[j]*i<=n;j++){
			p[i*P[j]]=1;
			if (i%P[j]==0) break;
		}
	}
}
int id1[M],id2[M],b;
LL g[M],a[M],val[M],n;
inline int home(LL x){
	return (x<=b ? id1[x] : id2[n/x]);
}
int main(){
	cin>>n; b=sqrt(n); sieve(b);
	LL ans=0;
	F(i,1,ct){
		if (1ll*P[i]*P[i]*P[i]<=n) ans++;
	}
//	cout<<ans<<"  hh \n";
	int m=0;
	for (LL i=1;i<=n;i=n/a[m]+1){
		a[++m]=n/i; g[m]=a[m]-1; val[m]=i;
		LL j=a[m];
		j<=b ? id1[j]=m : id2[n/j]=m;
	}
	F(i,1,ct){
		LL sq=1ll*P[i]*P[i];
		double inv=1.0/P[i];
		for (int j=1;j<=m&&sq<=a[j];j++){
			g[j]-=g[home((LL)(a[j])*inv+1e-9)]-i+1;
		}
	}
//	cout<<g[1]<<"\n";
	F(i,1,m){
		LL num=g[i]-g[i+1];
		if (val[i]<a[i]){
//			ans=(ans+num*g[home(val[i])]);
		}
		else{
			ans=(ans+num*(g[home(val[i])]-g[i+1])-num);
		}
	}
	cout<<ans<<"\n";
	return 0;
}