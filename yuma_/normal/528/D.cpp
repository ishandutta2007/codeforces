#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = double;
const ld eps = 1e-9;
//
//using Graph = vector<vector<int>>;
//
//int dfs(const Graph&g, const int now, vector<int>&ch_cnts) {
//	ch_cnts[now]++;
//	for (auto&& e : g[now]) {
//		ch_cnts[now] += dfs(g, e, ch_cnts);
//	}
//	return ch_cnts[now];
//}
//
//struct HL_Edge {
//	int from;
//	int to;
//	bool heavy;
//};
//
//void dfs2(const Graph&g, vector<vector<HL_Edge>>&hl_tree, const int now, const vector<int>&ch_cnts) {
//
//	int max_ch_id = 1;
//	{
//		int max_ch_num = -1;
//		for (auto&&e : g[now]) {
//			if (max_ch_num < ch_cnts[e]) {
//				max_ch_num = ch_cnts[e];
//				max_ch_id = e;
//			}
//		}
//	}
//	for (auto e : g[now]) {
//		bool heavy = (e == max_ch_id);
//
//		hl_tree[now].push_back(HL_Edge{ now,e,heavy });
//	}
//	return;
//}
//
//void HL(const vector<vector<int>>&ro_tree) {
//	vector<int>ch_cnts(ro_tree.size());
//
//	dfs(ro_tree, 0, ch_cnts);
//
//	vector<vector<HL_Edge>>hl_tree(ro_tree.size());
//
//	dfs2(ro_tree, hl_tree, 0, ch_cnts);
//}
//
//namespace FastFourierTransform
//{
//	using C = complex< double >;
//
//	void DiscreteFourierTransform(vector< C > &F, bool rev)
//	{
//		const int N = (int)F.size();
//		const double PI = (rev ? -1 : 1) * acos(-1);
//		for (int i = 0, j = 1; j + 1 < N; j++) {
//			for (int k = N >> 1; k > (i ^= k); k >>= 1);
//			if (i > j) swap(F[i], F[j]);
//		}
//		C w, s, t;
//		for (int i = 1; i < N; i <<= 1) {
//			for (int k = 0; k < i; k++) {
//				w = polar(1.0, PI / i * k);
//				for (int j = 0; j < N; j += i * 2) {
//					s = F[j + k];
//					t = C(F[j + k + i].real() * w.real() - F[j + k + i].imag() * w.imag(),
//						F[j + k + i].real() * w.imag() + F[j + k + i].imag() * w.real());
//					F[j + k] = s + t, F[j + k + i] = s - t;
//				}
//			}
//		}
//		if (rev) for (int i = 0; i < N; i++) F[i] /= N;
//	}
//
//	vector< int> Multiply(const vector<int > &A, const vector<int > &B)
//	{
//		int sz = 1;
//		while (sz <= A.size() + B.size()) sz <<= 1;
//		vector< C > F(sz), G(sz);
//		for (int i = 0; i < A.size(); i++) F[i] = A[i];
//		for (int i = 0; i < B.size(); i++) G[i] = B[i];
//		DiscreteFourierTransform(F, false);
//		DiscreteFourierTransform(G, false);
//		for (int i = 0; i < sz; i++) F[i] *= G[i];
//		DiscreteFourierTransform(F, true);
//		vector< int > X(A.size() + B.size() - 1);
//		for (int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
//		return (X);
//	}
//};

using ll = long long;

// 
constexpr int mod = 7 * 17 * (1 << 23) + 1; // == 998244353 !!

int mod_inv(ll a, ll m) {
	ll b = mod, u = 1, v = 0;
	while (b > 0) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	return (u % m + m) % m;
}

class FMT {
public:
	FMT() {
		omega.resize(omega_max + 1);
		int x = primitive_root;
		for (int i = omega_max; i >= 0; --i) {
			omega[i] = x;
			x = (1LL * x * x) % mod;
		}
	}

	// assertion: v.size() == 2 ^ m
	std::vector<int> fft(std::vector<int> v, bool inv) const {
		const int n = v.size();
		int logn = 0;
		{
			int sz = 1;
			while (sz < n) sz *= 2, logn++;
		}
		assert(1 << logn == n);
		assert(omega_max >= logn);
		int ww = omega[logn];
		if (inv) ww = mod_inv(ww, mod);
		for (int m = n; m >= 2; m >>= 1) {
			const int mh = m >> 1;
			int w = 1;
			for (int i = 0; i < mh; ++i) {
				for (int j = i; j < n; j += m) {
					const int k = j + mh;
					int x = v[j] - v[k];
					if (x < 0) x += mod;
					v[j] += v[k];
					if (v[j] >= mod) v[j] -= mod;
					v[k] = (1LL * w * x) % mod;
				}
				w = (1LL * w * ww) % mod;
			}
			ww = (1LL * ww * ww) % mod;
		}

		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(v[i], v[j]);
		}
		if (inv) {
			const int inv_n = mod_inv(n, mod);
			for (auto& x : v) {
				x = (1LL * x * inv_n) % mod;
			}
		}
		return v;
	}
	std::vector<int> convolution(std::vector<int> f, std::vector<int> g) const {
		int sz = 1;
		const int m = f.size() + g.size() - 1;
		while (sz < m) sz *= 2;
		f.resize(sz), g.resize(sz);
		f = this->fft(std::move(f), false); g = this->fft(std::move(g), false);
		for (int i = 0; i < sz; ++i) {
			f[i] = (1LL * f[i] * g[i]) % mod;
		}

		return this->fft(std::move(f), true);
	}

private:
	static const int omega_max = 23;
	static const int primitive_root = 31;
	std::vector<int> omega;
}ffmt;


int main() {
	int a, b, K; cin >> a >> b >> K;
	string S, T; 

	char chs[400000],cht[400000];
	scanf("%s %s",chs,cht);

	for (int i = 0; i < a; ++i) {
		S.push_back(chs[i]);
	}
	for (int i = 0; i < b; ++i) {
		T.push_back(cht[i]);
	}

	vector<vector<int>>s_haves(4, vector<int>(S.size()));
	vector<vector<int >>t_haves(4, vector<int>(T.size()));
	string name = "CATG";


	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < S.size(); ++j) {
			if (S[j] == name[i]) {
				s_haves[i][j] = 1;
			}
		}
		for (int j = 0; j < T.size(); ++j) {
			if (T[j] == name[i]) {
				t_haves[i][j] = 1;
			}
		}
		reverse(t_haves[i].begin(), t_haves[i].end());
	}

	vector<int>ns(2 * K + 1, 1);

	vector<vector<int>>tos(4,vector<int>(S.size()));

	for (int i = 0; i < 4; ++i) {
		int num=0;
		for (int j = 0; j < S.size(); ++j) {
			if (s_haves[i][j]) {
				num=K+1;
			}
			if (num) {
				tos[i][j]=true;
				num--;
			}
		}
		for (int j = S.size()-1 ;j >=0; --j) {
			if (s_haves[i][j]) {
				num = K + 1;
			}
			if (num) {
				tos[i][j] = true;
				num--;
			}
		}
	}

	vector<vector<int>>vs(4);


	for (int i = 0; i < 4; ++i) {
		auto v = ffmt.convolution(t_haves[i], tos[i]);
		vs[i] = v;
	}

	vector<int>oks(S.size() - T.size() + 1);
	vector<int>ks(4);
	for (int j = 0; j < 4; ++j) {
		int k = accumulate(t_haves[j].begin(), t_haves[j].end(), 0);
		ks[j] = k;
	}
	for (int i = 0; i <= S.size() - T.size(); ++i) {
		bool ok = true;
		for (int j = 0; j < 4; ++j) {
			int k = ks[j];
			if (vs[j][i + T.size() - 1] != k)ok = false;

		}
		if (ok)oks[i] = true;
	}
	int ans = count(oks.begin(), oks.end(), 1);
	cout << ans << endl;
	return 0;
}