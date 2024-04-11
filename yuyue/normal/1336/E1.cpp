#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,mod=998244353;
int n,m;
LL a[M];
int c1(LL x){
	return __builtin_popcountll(x);
}
LL ans[100];
struct LB{
	LL b[100];
	int ct;
	void ins(LL x){
		DF(i,m-1,0){
			if (x>>i&1){
				if (!b[i]){
					b[i]=x;
					ct++;
					return ;
				}
				else x^=b[i];
			}
		}
	}
	void xiao(){
		F(i,0,m-1){
			if (b[i]){
				F(j,0,i-1){
					if ((b[i]>>j&1) && b[j]){
						b[i]^=b[j];
					}
				}	
			}
		}
	}
	LL t[60];
	void dfs(int dep,LL now,int le){
		if (dep>le){
			ans[c1(now)]++;
			return ;
		}
		dfs(dep+1,now,le);
		dfs(dep+1,now^t[dep],le);
	}
	void zuo(){
		int tot=0;
		F(i,0,m-1) if (b[i]) t[++tot]=b[i];
		dfs(1,0,ct);
	}
	LL tb[111];
	int p[111],rk[111];
	void zuo2(){
		int ct=0,tot=0;
		F(i,0,m-1) if (b[i]) p[i]=ct,rk[ct]=i,ct++,cerr<<b[i]<<"\n";
		cerr<<" base\n";
		int la=ct;
		F(i,0,m-1) if (!b[i]) p[i]=ct,rk[ct]=i,ct++;
		F(i,0,m-1) tb[p[i]]=b[i];
		F(i,0,m-1) b[i]=tb[i];
		ct=la;
		F(i,ct,m-1){
			LL tmp=(1ll<<rk[i]);
			F(j,0,ct-1){
				LL o=(b[j]>>rk[i]&1);
				tmp|=(o<<rk[j]);
			}
			t[++tot]=tmp;
//			cerr<<tmp<<"    hhhh \n";
		}
		dfs(1,0,tot);
	}
}bas;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[111],inv[111];
LL C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
LL f[111][111];
void init(){
	fac[0]=1;
	F(i,1,m) fac[i]=fac[i-1]*i%mod;
	F(i,0,m) inv[i]=fast(fac[i],mod-2);
	F(i,0,m){
		F(j,0,m){
			F(k,0,min(i,j)){
				LL tmp=(k&1 ? mod-1 : 1);
				f[i][j]=(f[i][j]+tmp*C(j,k)%mod*C(m-j,i-k))%mod;
			}
		}
	}
}


int main(){
	n=read(); m=read(); init();
	F(i,1,n) a[i]=read(),bas.ins(a[i]);
	LL coe=fast(2,n-bas.ct);
	bas.xiao();
	if (bas.ct<=17){
		bas.zuo();
		F(i,0,m) cout<<ans[i]*coe%mod<<" ";
		cout<<"\n"; 
		return 0;
	}
	bas.zuo2();
	coe=coe*fast(2,mod-1-m+bas.ct)%mod;
	F(i,0,m){
//		cerr<<ans[i]<<" ";
		LL tmp=0;
		F(j,0,m){
			tmp=(tmp+f[i][j]*ans[j])%mod;
		}
		cout<<tmp*coe%mod<<" ";
	}
	cout<<"\n";
	return 0;
}
/*
*/