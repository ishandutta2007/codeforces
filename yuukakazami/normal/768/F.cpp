#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
const int MOD = int(1e9)+7;
const int N = int(2e5)+10;
int f,w,h;

int mypow(int a,int e){ if(e==0) return 1; return e%2==0?mypow(1LL*a*a%MOD,e>>1):1LL*a*mypow(a,e-1)%MOD; }
int inv(int a){ return mypow(a,MOD-2); }

int fact[N],rfact[N];
int comb(int n,int m){return 1LL*fact[n]*rfact[m]%MOD*rfact[n-m]%MOD;}
int sumto(int n,int w){if(w==0) return n==0; return comb(n+w-1,w-1);}
int sumto(int n,int w,int lst){if(n<1LL*w*lst) return 0; return sumto(n-w*lst,w);}
void addit(int&x,int c){x+=c; if(x>=MOD) x-= MOD;}

int main(){
	fact[0] = 1; rep(i,1,N) fact[i] = 1LL * fact[i-1] * i % MOD;
	rfact[N-1] = inv(fact[N-1]); for(int i=N-2;i>=0;--i) rfact[i] = 1LL * rfact[i+1] * (i+1) % MOD;
	cin>>f>>w>>h;

	int total = 0;
	int good = 0;

	rep(L,1,f+w+1){
		rep(ft,0,2){
			int nf,nw;
			nf=(L+1)/2,nw=L/2;
			if(ft) swap(nf,nw);	
			addit(total,1LL*sumto(f,nf,1)*sumto(w,nw,1)%MOD);
			addit(good,1LL*sumto(f,nf,1)*sumto(w,nw,h+1)%MOD);
		}
	}
	int ans = 1LL*good*inv(total)%MOD;
	cout<<ans<<endl;
	return 0;
}