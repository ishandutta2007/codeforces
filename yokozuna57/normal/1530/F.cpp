#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef unsigned int ull;

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

const int MOD=31607;
typedef modint<MOD> mi;

int n;
int a[22][22];

mi f[22];
mi X[22];
mi Y[21][1<<21];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
	
	for(int i=0;i<n;i++){
		f[i]=1;
		for(int j=0;j<n;j++)f[i]*=a[i][j];
	}
	X[0]=1;
	for(int i=0;i+1<22;i++){
		X[i+1]=X[i]*10000;
	}
	for(int j=0;j<n;j++){
		for(int s=0;s<(1<<n);s++){
			Y[j][s]=1;
			for(int i=0;i<n;i++){
				if((s>>i)&1)Y[j][s]*=a[i][j];
			}
		}
	}
	
	mi ret=0;
	for(int s=0;s<(1<<(n+2));s++){
		//bool used[22][22];
		//for(int i=0;i<n;i++)for(int j=0;j<22;j++)used[i][j]=false;
		int X_cnt[21]={};
		int Y_cnt[21]={};
		for(int i=0;i<n;i++){ X_cnt[i]=n; Y_cnt[i]=(1<<n)-1; }
		
		mi ret_=1;
		int cnt=0;
		int XX=0,YY=0;
		for(int i=0;i<n;i++){
			if((s>>i)&1){
				ret_*=f[i];
				cnt++;
				XX++;
				YY+=1<<i;
			}
		}
		for(int j=0;j<n;j++){ X_cnt[j]-=XX; Y_cnt[j]-=YY; }
		if((s>>(n-1+1))&1){
			for(int i=0;i<n;i++){
				if((s>>i)&1){}
				else{
					ret_*=a[i][i];
					X_cnt[i]--;
					Y_cnt[i]-=1<<i;
				}
			}
			cnt++;
		}
		if((s>>(n-1+2))&1){
			for(int i=0;i<n;i++){
				if((s>>i)&1){}
				else if(i==n-1-i&&(s>>n)&1){}
				else{
					ret_*=a[i][n-1-i];
					X_cnt[n-1-i]--;
					Y_cnt[n-1-i]-=1<<i;
				}
			}
			cnt++;
		}
		
		if((cnt&1)==0)ret_*=MOD-1;
		for(int j=0;j<n;j++){
			ret_*=MOD+X[X_cnt[j]].val-Y[j][Y_cnt[j]].val;
		}
		ret+=ret_;
	}
	mi inv=1; inv/=10000;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)ret*=inv;
	ret+=1;
	cout<<ret.val<<endl;
}