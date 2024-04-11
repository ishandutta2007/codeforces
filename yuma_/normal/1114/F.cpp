#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;



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
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}

typedef pair<Mod,long long> Value1;
typedef pair<Mod,long long> Value2;
const Value1 Zero1(Mod(1),0);
const Value2 Zero2(Mod(1),0);

struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
	lazy_segtree(int n,vector<Value1>&val) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = N; i < N + val.size(); ++i) {
			dat[i].sum=val[i-N];
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return make_pair(l.first*r.first,l.second|r.second);
	}

	void lazy_func(const int k, const int a, const int b) {
		Mod aa=dat[k].sum.first*
			(dat[k].lazy.first.num==1?Mod(1):mod_pow(dat[k].lazy.first,b-a));
		long long int  bb=dat[k].sum.second|dat[k].lazy.second;

		dat[k].sum=make_pair(aa,bb);
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return make_pair(l.first*r.first,l.second|r.second);
	}

	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}

	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);

	}

	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .

		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); //.
			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .

		if (b <= l || r <= a) //[a,b)[l,r)
			return Zero1;

		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}

		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}
};



int main() {
	hurui(300);

	vector<vector<int>>cnts(301, vector<int>(62));
	vector<long long int>flags(301);
	for (int i = 2; i <= 300; ++i) {
		int rest = i;
		for (int j = 0; j < 62; ++j) {
			while (true) {
				if (rest%primes[j] == 0) {
					cnts[i][j]++;
					flags[i] |= (1ll << j);
					rest /= primes[j];
				}
				else {
					break;
				}
			}
		}
	}
	int N, Q; scanf("%d %d", &N, &Q);
	int num = 1;
	while (num<N)num *= 2;
	//starry_sky_tree tree(num);

	vector<Value1>vals(num,Zero1);
	for (int i = 0; i < N; ++i) {
		int a; scanf("%d", &a);
		long long int flag = flags[a];
		Value1 val = make_pair(Mod(a), flag);
		vals[i] = (val);
	}
	vector<Mod>invs(62);
	for (int i = 0; i < 62; ++i) {
		invs[i]=Mod(1)/Mod(primes[i]);
	}
	lazy_segtree tree(num, vals);
	char chs[10];
	for (int q = 0; q < Q; ++q) {
		scanf(" %s", chs);
		int l, r;
		scanf("%d %d", &l, &r); l--;
		if (chs[0] == 'T') {
			auto p = tree.get(l, r);

			Mod answer = p.first;
			for (int i = 0; i < 62; ++i) {
				if (p.second&(1ll << i)) {
					answer *= primes[i] - 1;
					answer *=invs[i];
				}
			}
			printf("%d\n", answer.num);
		}
		else {
			int x; scanf("%d", &x);
			long long int flag = flags[x];
			tree.update(l, r, make_pair(Mod(x), flag));
		}
	}
	return 0;
}