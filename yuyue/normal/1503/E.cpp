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
const int mod=998244353,M=4222;
int n,m;
LL c[M][M];
void init(){
	F(i,0,M-1){
		c[i][0]=1;
		F(j,1,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
}
LL L[M],R[M],sR[M];
LL calc(bool o){
	if (o) swap(n,m);
	LL ret=0;
	F(i,1,m-1){//dividing line
		F(j,1,n-1){
			L[j]=c[i-1+j][j]*c[i+n-j-1][n-j-1]%mod;
			R[j]=c[m-i+j-1][j-1]*c[m-i-1+n-j][n-j]%mod;
			sR[j]=(sR[j-1]+R[j])%mod;
		}
		F(j,1,n-1){
//			cout<<L[j]<<" "<<R[j]<<" ?? \n";
			if (!o) ret=(ret+L[j]*sR[j])%mod;
			else ret=(ret+L[j]*sR[j-1])%mod;
		}
	}
	ret=ret*2%mod;
//	cout<<ret<<"  gan \n";
	return ret;
}
int main(){
	n=read(); m=read(); init();
	LL ans=calc(0)+calc(1);
	cout<<ans%mod<<"\n";
	return 0;
}
/*
*/