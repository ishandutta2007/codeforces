#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<ll MOD=1000000007>
struct modint{
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
};

typedef modint<1000000007> mi;

int n;
string s,t;

mi cnt[100010][26];
mi cnt0[26];
void init(){
	for(int i=0;i<26;i++){
		cnt[0][i]=0;
		cnt0[i]=0;
	}
	cnt[0][t[0]-'a']+=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<26;j++){
			cnt[i][j]=cnt[i-1][j]+cnt[i-1][j];
		}
		cnt[i][t[i]-'a']+=1;
	}
	for(int i=0;i<s.size();i++){
		cnt0[s[i]-'a']+=1;
	}
}

string str[500];

mi solve(int start, int goal){
	if(start>goal)return mi(0);
	if(str[start].size()==1){
		mi ret=0;
		if(start==0){
			ret+=cnt0[str[start][0]-'a']*modpow(mi(2),goal);
		}
		if(goal>0)ret+=cnt[goal-1][str[start][0]-'a'];
		if(start>1)ret-=cnt[start-2][str[start][0]-'a']*modpow(mi(2),goal-start+1);
		return ret;
	}
	mi ret=0;
	if(start==0){
		for(int i=0;i<=s.size();i++){
			bool ok=true;
			string &nex=str[start+1]; nex="";
			for(int j=0;j<str[start].size();j++){
				int r=(j+(s.size()+1)-i)%(s.size()+1);
				if(r<s.size()){
					if(str[start][j]!=s[r]){
						ok=false;
						break;
					}
				}
				else nex+=str[start][j];
			}
			if(ok){
				if(nex.size()==0)ret+=modpow(mi(2),goal);
				else ret+=solve(start+1,goal);
			}
		}
	}
	else {
		for(int i=0;i<=1;i++){
			bool ok=true;
			string &nex=str[start+1]; nex="";
			for(int j=0;j<str[start].size();j++){
				int r=(j+2-i)%2;
				if(r==0){
					if(str[start][j]!=t[start-1]){
						ok=false;
						break;
					}
				}
				else nex+=str[start][j];
			}
			if(ok)ret+=solve(start+1,goal);
		}
	}
	return ret;
}

int main(){
	cin.tie(0);
	
	int q;
	cin>>n>>q>>s>>t;
	init();
	for(;q>0;q--){
		int k;
		string str_;
		cin>>k>>str_;
		str[0]=str_;
		printf("%lld\n",solve(0,k).val);
	}
}