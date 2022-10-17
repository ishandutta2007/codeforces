#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second
template<int MOD=1000000007>
struct modint{
	/*static modint inv[2005];
	static void init(){
		for(int i=0;i<2005;i++)inv[i]=modpow(modint(i),MOD-2);
	}*/
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
	modint& operator /=(const modint& rhs){
		(*this)*=modpow(rhs,MOD-2);
		//(*this)*=inv[rhs.val];
		return *this;
	}
	friend modint operator/(modint lhs, const modint& rhs){
		lhs/=rhs;
		return lhs;
	}
};
//template<int MOD>
//modint<MOD> modint<MOD>::inv[2005];

const int MOD=998244353;
typedef modint<MOD> mi;

mi C[4100][4100];
void init_C(){
	for(int i=0;i<4100;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<=i-1;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
}

mi ret;
void solve(int n,int m){
	for(int i=1;i<=m-1;i++){
		mi sum=0;
		for(int j=1;j<=n-1;j++){
			mi temp=C[j-1+m-i][j-1]*C[n-j+m-i-1][n-j];
			mi ret_=2*sum+temp;
			sum+=temp;
			ret_*=C[i-1+j][j]*C[i+n-j-1][i];
			ret+=ret_;
		}
	}
}

int main(){
	init_C();
	int n,m;
	cin>>n>>m;
	solve(n,m);
	solve(m,n);
	cout<<ret.val<<endl;
}