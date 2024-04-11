#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
	
using ll=long long ;



const int mod =998244353;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 102400

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

vector<Mod>get_dp(const vector<int>x_connects){
	int x_sum=accumulate(x_connects.begin(),x_connects.end(),0);

	vector<vector<Mod>>x_dp(x_connects.size()+1,vector<Mod>(x_sum+1));
	x_dp[0][0]=1;
	for(int i=0;i<x_connects.size();++i){
		for(int now=0;now<=x_sum;++now){
			for(int use=0;use<=x_connects[i]/2;++use){
				if(now+use>x_sum)continue;
				else{
					x_dp[i+1][now+use]+=x_dp[i][now]*comb(x_connects[i]-use,use);
				}
			}
		}
	}
	return x_dp[x_connects.size()];
}

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	map<int ,map<int,vector<pair<int,int>>>>mp;
	for(int i=0;i<N;++i){
		int x,y,z;cin>>x>>y>>z;
		mp[x][y].push_back(make_pair(z,i+1));
	}
	vector<pair<int,int>>answers;
	vector<pair<int,int>>ps1;
	for(auto mm:mp){
		int x=mm.first;
		vector<pair<int,int>>ps2;
		for(auto m:mm.second){
			int y=m.first;
			sort(m.second.begin(),m.second.end());
			for(int i=0;i+1<m.second.size();i+=2){
				answers.emplace_back(m.second[i].second,m.second[i+1].second);
			}
			if(m.second.size()%2){
				ps2.emplace_back(m.second.back());
			}
		}
		for(int i=0;i+1<ps2.size();i+=2){
			answers.emplace_back(ps2[i].second,ps2[i+1].second);
		}
		if(ps2.size()%2){
			ps1.emplace_back(ps2.back());
		}
	}
	for(int i=0;i+1<ps1.size();i+=2){
		answers.emplace_back(ps1[i].second,ps1[i+1].second);
	}
	for(int i=0;i<N/2;++i){
		cout<<answers[i].first<<' '<<answers[i].second<<endl;
	}
	return 0;
}