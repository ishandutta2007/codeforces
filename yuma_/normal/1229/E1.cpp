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



const int mod = 1000000007;
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

#define MAX_MOD_N 1024000

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
map<int,int>mp;
void init(vector<vector<Mod>>&pers){
	vector<int>v(3,0);
	for(int i=0;i<3;++i)v.push_back(1);
	int id=0;
	do{
		int tt=0;
		for(int k=0;k<6;++k){
			if(v[k])tt^=(1<<k);
		}
		mp[tt]=id;
		id++;
	}while(next_permutation(v.begin(),v.end()));

	int N;cin>>N;
	int s=3-(N+1)/2;
	for(int i=0;i<s;++i)pers[i][i]=Mod(1);
	for(int i=s;i<s+N;++i){
		for(int j=s;j<s+N;++j){
			int p;cin>>p;
			pers[i][j]=Mod(p)/Mod(100);
		}
	}
	for(int i=s+N;i<6;++i)pers[i][i]=Mod(1);
}
vector<Mod> solve(const vector<vector<Mod>>&pers,int al=0){
	vector<Mod>l_nums(1<<20);
	for(int xx=0;xx<(1<<18);++xx){
		vector<vector<int>>haves(3,vector<int>(6));
		Mod per=1;
		for(int i=0;i<3;++i){
			for(int j=0;j<6;++j){
				int k=i*6+j;
				if(xx&(1<<k)){
					haves[i][j]=true;
					per*=pers[al+i][j];
				}else{
					per*=(Mod(1)-pers[al+i][j]);
				}
			}
		}
		int flags=0;
		for(int i=0;i<6;++i){
			if(!haves[0][i])continue;
			for(int j=0;j<6;++j){
				if(!haves[1][j])continue;
				if(i==j)continue;
				for(int k=0;k<6;++k){
					if(!haves[2][k])continue;
					if(i==k)continue;
					if(j==k)continue;
					else{
						int anum=0;
						anum^=(1<<i);
						anum^=(1<<j);
						anum^=(1<<k);
						flags |=(1<<mp[anum]);
					}
				}
			}
		}
		l_nums[flags]+=per;
	}
	return l_nums;
}
int main() {
	ios::sync_with_stdio(false);

	vector<vector<Mod>>pers(6,vector<Mod>(6));
	
	init(pers);
	//cout<<3<<endl;

	auto u_nums=solve(pers,0);
	auto d_nums=solve(pers,3);
	for(int x=1;x<(1<<20);x<<=1){
		for(int i=0;i<(1<<20);++i){
			if((i&x)==0){
				d_nums[i^x]+=d_nums[i];
			}
		}
	}
	//cout<<3<<endl;
	Mod answer=0;
	for(int i=0;i<(1<<20);++i){
		if(u_nums[i].num){
			//WHATS(i)
			int need=0;
			{
				for(int x=0;x<20;++x){
					if(i&(1<<x)){
						need|=(1<<(19-x));
					}
				}
			}
			//WHATS(u_nums[i].num)
			int pp=((1<<20)-1)^i;
			//WHATS(pp)
			
			Mod nanswer=u_nums[i]*(Mod(1)-d_nums[((1<<20)-1)^need]);
			answer+=nanswer;
		}
	}
	cout<<answer.num<<endl;
	
	return 0;
}