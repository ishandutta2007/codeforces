#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

template<int MOD> struct modint{
	ull val;
	modint(ull x){ val=x%MOD; }
	modint(){}
	friend modint modpow(modint x,ull k){
		modint ret(1ULL);
		while(k>0){
			if(k&1ULL)ret*=x;
			x*=x;
			k>>=1;
		}
		return ret;
	}
	modint& operator +=(const modint& rhs){
		this->val+=rhs.val;
		if(this->val>=MOD)this->val-=MOD;
		return *this;
	}
	friend modint operator+(modint lhs, const modint& rhs){
		lhs+=rhs;
		return lhs;
	}
	modint& operator -=(const modint& rhs){
		this->val+=MOD-rhs.val;
		if(this->val>=MOD)this->val-=MOD;
		return *this;
	}
	friend modint operator-(modint lhs, const modint& rhs){
		lhs-=rhs;
		return lhs;
	}
	modint& operator *=(const modint& rhs){
		this->val*=rhs.val;
		this->val%=MOD;
		return *this;
	}
	friend modint operator*(modint lhs, const modint& rhs){
		lhs*=rhs;
		return lhs;
	}
	static vector<modint> inv_;
	static void precalc_inv_(int k){
		int t=inv_.size();
		inv_.resize(k);
		for(int i=t;i<k;i++){
			inv_[i]=modpow(modint(i),MOD-2);
		}
	}
	modint& operator /=(const modint& rhs){
		//if(rhs.val<inv_.size()){
		//	(*this)*=inv_[rhs.val];
		//}
		//else {
			(*this)*=modpow(rhs,MOD-2);
		//}
		return *this;
	}
	friend modint operator/(modint lhs, const modint& rhs){
		lhs/=rhs;
		return lhs;
	}
	
	static vector<vector<modint>> C_;
	static vector<modint> fac,inv_fac;
	static void precalc_C_(int k){
		C_.resize(k,vector<modint>(k));
		for(int i=0;i<k;i++){
			C_[i][0]=C_[i][i]=1;
			for(int j=1;j<=i-1;j++){
				C_[i][j]=C_[i-1][j-1]+C_[i-1][j];
			}
		}
	}
	static void precalc_fac(int k){
		fac.resize(k);
		inv_fac.resize(k);
		fac[0]=inv_fac[0]=1;
		for(int i=1;i<k;i++){
			fac[i]=fac[i-1]*i;
			inv_fac[i]=modpow(fac[i],MOD-2);
		}
	}
	static modint C(ll n,ll k,int type=0){
		if(k<0||k>n)return 0;
		if(type==0){
			return C_[n][k];
		}
		else {
			return fac[n]*inv_fac[k]*inv_fac[n-k];
		}
	}
};
template<int MOD> vector<modint<MOD>> modint<MOD>::inv_;
template<int MOD> vector<vector<modint<MOD>>> modint<MOD>:: C_;
template<int MOD> vector<modint<MOD>> modint<MOD>::fac;
template<int MOD> vector<modint<MOD>> modint<MOD>::inv_fac;

const int MOD=1000000007;
typedef modint<MOD> mi;

struct UF{
	vector<int> par,r;
	UF(int n){ init(n); }
	UF(){}
	void init(int n=-1){
		if(n==-1)n=par.size();
		par.resize(n);
		r.resize(n);
		iota(par.begin(),par.end(),0);
		fill(r.begin(),r.end(),0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
 	bool same(int x,int y){ return find(x)==find(y); }
	void unit(int x,int y){
		if(same(x,y))return;
		x=find(x);
		y=find(y);
		if(r[x]>r[y])swap(x,y);
		par[x]=y;
		if(r[x]==r[y])r[y]++;
	}
};

int n;
ll a[400010],b[400010];

void solve(){
	UF uf(n);
	for(int i=0;i<n;i++)uf.unit(a[i],b[i]);
	mi ret=1;
	for(int i=0;i<n;i++)if(uf.find(i)==i)ret+=ret;
	printf("%lld\n",ret.val);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){ scanf("%d",&a[i]); a[i]--; }
		for(int i=0;i<n;i++){ scanf("%d",&b[i]); b[i]--; }
		solve();
	}
}