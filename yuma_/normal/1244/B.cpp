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
	
#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
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
template<class T,class TT> ostream& operator <<(ostream &os, const map<T,TT> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
return os;
}
	
	
const int mod = 998244353;
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
	
	
using ll=long long ;
	
#define WHAT(var) cout<<__LINE__<<' '<<#var<<" : "<<var<<endl;
	
const ll amod=1e9+7;
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	
	
	return ans;
}
	
	
vector<int>chs;
vector<int>ls,rs;
using Graph=vector<vector<int>>;
Graph g;
void dfs1(int now,int from){
	chs[now]=1;
	vector<pair<int,int>>ps;
	for(auto e:g[now]){
		if(e==from)continue;
		dfs1(e,now);
		chs[now]+=chs[e];
		ps.emplace_back(chs[e],e);
	}
	sort(ps.begin(),ps.end());
	g[now].clear();
	for(auto p:ps){
		g[now].push_back(p.second);
	}
}
vector<map<int,pair<int,int>>>mps;
void dfs2(int now,int from,int& id){
	ls[now]=id;
	id++;
	map<int,pair<int,int>>mp;
	int pre=-1;
	pair<int,int>ap(-1,-1);
	for(auto e:g[now]){
		if(e==from)continue;
		int cnt=chs[e];
	
		if(pre!=cnt){
			if(pre!=-1){
				mp[pre]=make_pair(ap.first,id);
	
			}
			ap=make_pair(id,-1);
			pre=cnt;
		}
		dfs2(e,now,id);
	
	}
	if(pre!=-1){
		mp[pre]=make_pair(ap.first,id);
	}
	WHATS(now)
	WHATS(mp)
	mps[now]=mp;
	rs[now]=id;
}
	
//0-indexed
const int MAX_N=140001;

ll f[MAX_N];

void upd(int pos, ll x){
	for(; pos < MAX_N; pos |= pos + 1)
		{
			//cout<<pos<<endl;
		f[pos] += x;
		if(f[pos]>=mod)f[pos]-=mod;
		if(f[pos]<0)f[pos]+=mod;
		}
}


ll get(int pos){
	ll res = 0;
	//cout<<pos<<endl;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res%mod;
}
void pl(int pos,ll x){
	//cout<<pos<<endl;
	upd(pos,x);
}
int main(){
	ios::sync_with_stdio(false);
	int N;cin>>N;
	for(int i=0;i<N;++i){
		int M;cin>>M;
		string st;cin>>st;
		if(st.find('1')==-1){
			cout<<M<<endl;
		}else{
			auto it=find(st.begin(),st.end(),'1');
			auto jt=find(st.rbegin(),st.rend(),'1');

			int a=it-st.begin();
			int b=jt-st.rbegin();

			cout<<2*M-2*(min(a,b))<<endl;
		}
	}
	return 0;
}