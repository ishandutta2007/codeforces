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
const int M=2e5+10;
const int mod=998244353,iv=(mod+1)/2;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL h[M];
int lim=1,sg[M],ct[M],de[M],q[M];
void FWT(LL *f,int op){
	for (int p=2;p<=lim;p<<=1){
		int len=p>>1;
		for (int k=0;k<lim;k+=p){
			for (int l=k;l<k+len;l++){
				LL X=f[l],Y=f[l+len];
				f[l]=(X+Y)%mod;
				f[l+len]=(X+mod-Y)%mod;
				if (op==-1){
					f[l]=f[l]*iv%mod;
					f[l+len]=f[l+len]*iv%mod;
				}
			}
		}
	}
}
int n,m;
vector<int> rv[M],v[M];
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
		rv[y].pb(x);
		de[x]++;
	}
	int l=1,r=0;
	F(i,1,n){
		if (!de[i]) q[++r]=i;
	}
	int mx=0;
	while (l<=r){
//		cout<<l<<" "<<r<<"\n";
		int x=q[l++];
		int pos=0;
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			ct[sg[y]]++;
		}
		while (ct[pos]) pos++;
		sg[x]=pos;
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			ct[sg[y]]--;
		}
		F(i,0,SZ(rv[x])){
			int y=rv[x][i];
			de[y]--;
			if (!de[y]) q[++r]=y;
		}
		mx=max(mx,sg[x]);
	}
	while (lim<=mx) lim<<=1;
	LL prob=fast(n+1,mod-2);
	F(i,1,n){
		h[sg[i]]=(h[sg[i]]+prob)%mod;
	}
//	cout<<h[0]<<" "<<h[1]<<"\n";
	FWT(h,1);
//	cout<<h[0]<<" "<<h[1]<<"\n"; 
	F(i,0,lim-1) h[i]=(mod+1-h[i])%mod;
//	h[0]++;
	F(i,0,lim-1) h[i]=fast(h[i],mod-2);
	FWT(h,-1);
	cout<<(mod+1-h[0]*prob%mod)%mod<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/