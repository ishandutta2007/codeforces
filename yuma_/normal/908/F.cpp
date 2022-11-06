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
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}



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
Mod mod_pow(const Mod a, const long long  n) {
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
	
using ll = long long int;


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

struct aa{
	int u;
	int v;
	ll cost;
};
bool operator <(const aa&l,const aa&r){
	return l.cost<r.cost;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	int N;cin>>N;
	int r_id=-1,g_id=-1,b_id=-1;

	ll answer=0;
	vector<ll>xs(N);
	vector<aa>r_edges,b_edges;
	UnionFind uf(N);

	for(int id=0;id<N;++id){
		int a;
		char ch;cin>>a>>ch;
		xs[id]=a;
		if(ch=='G'){
			
			
			if(r_id!=-1){
				r_edges.push_back(aa{r_id,id,xs[id]-xs[r_id]});
			}
			if(b_id!=-1){
				b_edges.push_back(aa{b_id,id,xs[id]-xs[b_id]});
			}

			
			sort(r_edges.begin(),r_edges.end());
			sort(b_edges.begin(),b_edges.end());
			ll nanswer=0;
			if(g_id!=-1)uf.unionSet(g_id,id);
			for(auto e:r_edges){
				if(uf.root(e.u)!=uf.root(e.v)){
					uf.unionSet(e.u,e.v);
					nanswer+=e.cost;
				}
			}
			//WHATS(answer)
			for(auto e:b_edges){
				if(uf.root(e.u)!=uf.root(e.v)){
					uf.unionSet(e.u,e.v);
					nanswer+=e.cost;
				}
			}
			if(g_id==-1){
				answer+=nanswer;
			}else{
				answer+=min(xs[id]-xs[g_id]+nanswer,(xs[id]-xs[g_id])*2);
			}
			r_edges.clear();
			b_edges.clear();
			//WHATS(answer)
			g_id=id;
			b_id=-1;
			r_id=-1;
		}else if(ch=='R'){
			if(g_id!=-1){
				r_edges.push_back(aa{g_id,id,xs[id]-xs[g_id]});
			}
			if(r_id!=-1){
				r_edges.push_back(aa{r_id,id,xs[id]-xs[r_id]});
			}
			r_id=id;
		}else if(ch=='B'){
			if(g_id!=-1){
				b_edges.push_back(aa{g_id,id,xs[id]-xs[g_id]});
			}
			if(b_id!=-1){
				b_edges.push_back(aa{b_id,id,xs[id]-xs[b_id]});
			}
			b_id=id;
		}
	}
	
	sort(r_edges.begin(),r_edges.end());
	sort(b_edges.begin(),b_edges.end());
	//WHATS(answer)
	ll nanswer=0;
	for(auto e:r_edges){
		if(uf.root(e.u)!=uf.root(e.v)){
			uf.unionSet(e.u,e.v);
			nanswer+=e.cost;
		}
	}
	//WHATS(answer)
	for(auto e:b_edges){
		if(uf.root(e.u)!=uf.root(e.v)){
			uf.unionSet(e.u,e.v);
			nanswer+=e.cost;
		}
	}
	cout<<answer+nanswer<<endl;
	return 0;
}