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
const int M=1111,mod=1e9+7;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL ans=1;
int main(){
	LL x;
	LL n;
	vector<LL> p;
	cin>>x>>n;
	for (int i=2;i*i<=x;i++){
		if (x%i==0){
			p.pb(i);
			while (x%i==0) x/=i;
		}
	}
	if (x!=1) p.pb(x);
	F(i,0,SZ(p)){
//		cout<<p[i]<<"\n";
		for (LL y=p[i],mi=1;y<=n;mi++,y*=p[i]){
			ans=ans*fast(p[i],n/y)%mod;
			if (y>n/p[i]) break;
		}
		
	}
	cout<<ans<<"\n"; 
	return 0;
}