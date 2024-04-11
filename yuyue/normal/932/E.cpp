#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=1e9+7,M=5050;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL s[M][M];
int n,k;
void init(){
	s[0][0]=1;
	F(i,1,k){
		F(j,1,i){
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%mod;
		}
	}
}
int main(){
	n=read(); k=read();
	int nn=min(n,k);
	LL coe=1,ans=0;
	init();
	F(i,0,nn){
		ans=(ans+s[k][i]*coe%mod*fast(2,n-i))%mod;
		coe=coe*(n-i)%mod;
	}
	cout<<ans<<"\n";
    return 0;
}