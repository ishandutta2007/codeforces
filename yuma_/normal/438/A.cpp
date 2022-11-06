#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
using namespace std;

#include<assert.h>
const int mod = 1000000009;

struct Mod {
	int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	Mod(int n) : num((n % mod + mod) % mod) { ; }
	operator int() { return num; }
};

Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(long long int a, Mod b) { return Mod(a) + b; }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(long long int a, Mod b) { return Mod(a) - b; }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(long long int a, Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator+=(long long int &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator-=(long long int &a, Mod b) { return a = a - b; }
Mod operator*=(Mod &a, Mod b) { return a = a * b; }
Mod operator*=(long long int &a, Mod b) { return a = a * b; }
Mod operator^(Mod a, int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) {
	assert(b != 0);
	return a * inv(b);
}
Mod operator/(long long int a, Mod b) {
	assert(b != 0);
	return Mod(a) * inv(b);
}

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(int a, int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}


vector<vector<Mod>> keisann(const vector<vector<Mod>>l, const vector<vector<Mod>>r) {
	vector<vector<long long int>> ll(l.size(), vector<long long int>(l[0].size())), rr(r.size(), vector<long long int>(r[0].size()));
	for (int i = 0; i < l.size(); ++i) {
		for (int j = 0; j < l[0].size(); ++j) {
			ll[i][j] = l[i][j].num;
		}
	}
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < r[0].size(); ++j) {
			rr[i][j] = r[i][j].num;
		}
	}
	vector<vector<Mod>>ans(l.size(), vector<Mod>(r[0].size()));
	assert(l[0].size() == r.size());
	for (int h = 0; h < l.size(); ++h) {
		for (int w = 0; w < r[0].size(); ++w) {
			long long int aa = 0;
			for (int i = 0; i < r.size(); ++i) {

				aa += (ll[h][i] * rr[i][w]) % mod;
				//ans[h][w] += l[h][i] * r[i][w];
			}
			ans[h][w] = aa%mod;
		}
	}
	return ans;
}

vector<vector<Mod>>powgyou(vector<vector<Mod>>a, const long long int n) {
	assert(a.size() == a[0].size());
	if (n == 0) {
		vector<vector<Mod>>ans(a);
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans.size(); ++j) {
				ans[i][j] = 0;
			}
		}
		for (int i = 0; i < ans.size(); ++i) {
			ans[i][i] = 1;
		}
		return ans;
	}
	if (n == 1)return a;
	else {
		vector<vector<Mod>>ans(a.size(), vector<Mod>(a[0].size(), 0));
		ans = powgyou(a, n / 2);
		ans = keisann(ans, ans);
		if (n % 2) {
			ans = keisann(ans, a);
		}
		return ans;

	}
}
//#define FOR(i,a,b) for(int i=(a);i<(b);++i)
//#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
//class segtree
//{
//public:
//	vector<int> seg;
//	int size;
//	segtree(int n)
//	{
//		size = 1;
//		while (size < n)  size *= 2;
//		seg.resize(size * 2, -1);
//	}
//
//	void update(int k, int v)
//	{
//		k += size - 1;
//		seg[k] = v;
//		while (k > 0)
//		{
//			k = (k - 1) / 2;
//			seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]);
//		}
//	}
//
//	int query(int v)
//	{
//		int k = 0;
//		while (k < size - 1)
//		{
//			if (seg[k * 2 + 1] < v)
//			{
//				k = k * 2 + 1;
//			}
//			else
//			{
//				k = k * 2 + 2;
//			}
//		}
//		return k - (size - 1);
//	}
//};


#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int m, n, a, b;

struct P {
	int y;
	int x;
	int muki;
	int time;
	P(int a, int b, int c, int d) {
		y = a; x = b; muki = c; time = d;
	}
};
class Compare {
public:
	bool operator()(const P&l, const P&r) {
		return l.time > r.time;
	}
};

int afield[52][52];

int ans[52][52][4];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>connects(N, vector<int>(N));

	vector<int>vs;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		vs.push_back(a);
	}
	vector<pair<int, int>>aas;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b; a--; b--;
		connects[a].push_back(b);
		connects[b].push_back(a);
		aas.push_back(make_pair(a, b));
	}
	long long int ans = 0;
	for (int i = 0; i < M; ++i) {
		ans += min(vs[aas[i].first], vs[aas[i].second]);
	}
	cout << ans << endl;
	return 0;
}