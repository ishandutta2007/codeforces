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
int a[202],b[202];

int d[202][202];

mi dp[202][202];

int main(){
	dp[1][0]=1;
	dp[0][1]=0;
	for(int s=2;s<200;s++){
		for(int i=0;i<=s;i++){
			int j=s-i;
			if(i==0)dp[i][j]=0;
			else if(j==0)dp[i][j]=1;
			else dp[i][j]=(dp[i-1][j]+dp[i][j-1])/2;
		}
	}
	
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a[i],&b[i]); a[i]--; b[i]--;
	}
	
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=T_INF<int>();
	for(int i=0;i<n;i++)d[i][i]=0;
	for(int i=0;i<n-1;i++){
		d[a[i]][b[i]]=1;
		d[b[i]][a[i]]=1;
	}
	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	mi ret=0;
	for(int x=0;x<n;x++)for(int y=x+1;y<n;y++){
		for(int z=0;z<n;z++){
			if(d[z][x]+d[x][y]==d[z][y]){}
			else if(d[z][y]+d[y][x]==d[z][x])ret+=1;
			else {
				int u=(d[z][x]+d[z][y]-d[x][y])/2;
				int s=d[z][x]-u;
				int t=d[z][y]-u;
				ret+=dp[s][t];
			}
			//cerr<<x<<" "<<y<<" "<<z<<" "<<ret.val<<endl;
		}
	}
	ret/=n;
	cout<<ret.val<<endl;
}