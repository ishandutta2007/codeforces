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

int n;
int c[102];
int b[102];
int q;
int x[100010];

mi dp[102][10002];

int solve(int X){
	for(int i=0;i<102;i++)for(int j=0;j<10002;j++)dp[i][j]=0;
	dp[0][0]=1;
	int sum[2]={0,0};
	for(int i=0;i<n;i++){
		for(int j=0;j<10002;j++){
			dp[i+1][j]+=dp[i][j];
			if(j+c[i]+1<10002)dp[i+1][j+c[i]+1]-=dp[i][j];
		}
		for(int j=0;j+1<10002;j++){
			dp[i+1][j+1]+=dp[i+1][j];
		}
		sum[1]+=sum[0];
		if(i+1<n)sum[0]+=b[i];
		for(int j=0;j<min((i+1)*X+sum[1],10002);j++)dp[i+1][j]=0;
	}
	mi ret=0;
	for(int i=0;i<10002;i++)ret+=dp[n][i];
	return (int)ret.val;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	for(int i=0;i<n-1;i++)scanf("%d",&b[i]);
	scanf("%d",&q);
	for(int i=0;i<q;i++)scanf("%d",&x[i]);
	
	int MIN=100000,MAX=-100000;
	int sum[2]={0,0};
	for(int i=0;i<n;i++){
		sum[1]+=sum[0];
		MIN=min(MIN,-(sum[1]/(i+1))-1);
		if(i+1<n)sum[0]+=b[i];
	}
	MAX=101-sum[1]/n;
	vector<int> ret;
	for(int i=MIN;i<=MAX;i++){
		ret.push_back(solve(i));
	}
	for(int i=0;i<q;i++){
		int r;
		if(x[i]<MIN)r=0;
		else if(x[i]>MAX)r=ret.size()-1;
		else r=x[i]-MIN;
		printf("%d\n",ret[r]);
	}
}