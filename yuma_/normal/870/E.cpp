#include "bits/stdc++.h"

using namespace std;
#pragma warning(disable:4996)



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
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}

//mod extend euclid 
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
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

int main() {
	int N;cin>>N;
	vector<pair<int,int>>ps;
	map<int,vector<int>>x_mp,y_mp;
	for (int i = 0; i < N; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		ps.push_back(make_pair(a,b));
		x_mp[a].push_back(i);
		y_mp[b].push_back(i);
	}
	UnionFind uf(N);
	for (auto am : x_mp) {
		for (int i = 0; i < am.second.size() - 1; ++i) {
			uf.unionSet(am.second[i],am.second[i+1]);
		}
	}
	for (auto am : y_mp) {
		for (int i = 0; i < am.second.size() - 1; ++i) {
			uf.unionSet(am.second[i], am.second[i + 1]);
		}
	}
	map<int,vector<int>>ids;
	for (int i = 0; i < N; ++i) {
		ids[uf.root(i)].push_back(i);
	}
	Mod answer=1;
	for (auto idd : ids) {
		auto v(idd.second);
		vector<int>xs,ys;
		for (auto n : v) {
			xs.emplace_back(ps[n].first);
			ys.emplace_back(ps[n].second);
		}
		sort(xs.begin(),xs.end());
		sort(ys.begin(),ys.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
		ys.erase(unique(ys.begin(),ys.end()),ys.end());
		int sum=xs.size()+ys.size();
		if (sum > v.size()) {
			assert(sum==v.size()+1);
			answer*=mod_pow(2,sum)-Mod(1);
		}
		else {
			answer*=mod_pow(2,sum);
		}
	}
	cout<<answer.num<<endl;
	return 0;
	
}