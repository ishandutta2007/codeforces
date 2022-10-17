#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define fr first
#define sc second

struct modint{
	static ll MOD;
	ll val;
	modint(ll x){ val=x%MOD; }
	modint(){}
	friend modint modpow(modint x,ll k){
		modint ret(1LL);
		while(k>0){
			if(k&1LL)ret*=x;
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
		this->val%=MOD;
		return *this;
	}
	friend modint operator/(modint lhs, const modint& rhs){
		lhs/=rhs;
		return lhs;
	}
	
	static vector<vector<modint>> comb;
	static void comb_init(int n){
		comb=vector<vector<modint>>(n+1,vector<modint>(n+1,0));
		comb[0][0]=1;
		for(int i=0;i<=n;i++){
			comb[i][0]=comb[i][i]=1;
			for(int j=1;j<i;j++){
				comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			}
		}
	}
};

typedef modint mi;
ll mi::MOD;
vector<vector<mi>> mi::comb;

int main(){
	ll n,m,p;
	cin>>n>>m>>p;
	
	mi::MOD=p;
	mi::comb_init(500);
	
	pair<mi,mi> dp[502];
	dp[0]=mp(1,0);
	for(int i=1;i<=n;i++){
		dp[i].fr=0;
		for(int j=1;j<=i;j++){
			dp[i].fr+=(i+1)*dp[j-1].fr*dp[i-j].fr*mi::comb[i-1][j-1];
		}
		dp[i].sc=0;
		for(int j=1;j<=n;j++){
			mi tmp=(j*(j-1)/2+(i-j)*(i-j+1)/2)*dp[j-1].fr*dp[i-j].fr;
			tmp+=(i+1)*dp[j-1].sc*dp[i-j].fr;
			tmp+=(i+1)*dp[j-1].fr*dp[i-j].sc;
			dp[i].sc+=tmp*mi::comb[i-1][j-1];
		}
	}
	
	static pair<mi,mi> dp2[502][502];
	for(int i=0;i<502;i++)for(int j=0;j<502;j++)dp2[i][j]=mp(0,0);
	dp2[0][0]=mp(1,0);
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++){
		for(int d=0;i+d+1<=n+1&&j+d<=m;d++){
			dp2[i+d+1][j+d].fr+=dp2[i][j].fr*dp[d].fr*mi::comb[j+d][d];
			dp2[i+d+1][j+d].sc+=dp2[i][j].sc*dp[d].fr*mi::comb[j+d][d]+dp2[i][j].fr*dp[d].sc*mi::comb[j+d][d];
		}
	}
	//cout<<dp2[1][0].fr.val<<" "<<dp2[1][0].sc.val<<endl;
	//cout<<dp2[4][2].fr.val<<" "<<dp2[4][2].sc.val<<endl;
	cout<<dp2[n+1][m].sc.val<<endl;
}