#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

long long int nans = 0;
vector<long long int>as;
int K;
struct Mo_Query {
	int id;

	//[l,r)
	int l;
	int r;

	Mo_Query(const int id_, const int l_, const int r_) :
		id(id_), l(l_), r(r_) {
	}

};

//Mo's Algorighm
//

class Mo_Algo {
public:
	vector<vector<Mo_Query>>squares;

	Mo_Algo(int size_) : squares(static_cast<size_t>(sqrt(size_ - 1) + 1))
	{
		sums[0] = 1;
	}
	map<long long int, int>sums;

	//v()
	//to_right
	inline void add(const int v, const bool to_right = false) {

		int nv = v;
		long long int num;
		if (to_right) {
			nv++;
			num = as[nv] - K;
		}
		else {
			num = as[nv] + K;
		}
		//
		auto it = sums.find(num);
		if (it != sums.end()) {
			nans += it->second;
		}
		
		sums[as[nv]]++;


	}

	//v()
	//to_right
	inline void rem(const int v, const bool to_right = false) {

		int nv = v;
		long long int num;
		if (to_right) {
			nv++;
			num = as[nv] - K;
		}
		else {
			num = as[nv] + K;
		}

		sums[as[nv]]--;
		auto it = sums.find(num);
		if (it != sums.end()) {
			nans -= it->second;
		}

	}

	long long int getans() {

		//
		return nans;
	}

	//[l,r)
	//0
	vector<long long int > solve(const  vector<Mo_Query> &querys) {
		for (const auto q : querys) {
			squares[q.l / (squares.size())].push_back(q);
		}
		for (auto& asquare : squares) {
			sort(asquare.begin(), asquare.end(), [](const  Mo_Query &l, const  Mo_Query &r) {
				return l.r < r.r;
			});
		}

		vector<long long int >anss(querys.size());

		for (const auto& square : squares) {
			if (square.size()) {
				int nl = square[0].l;
				int nr = square[0].l;
				sums.clear();
				sums[as[nl]] = 1;
				nans = 0;
				for (const auto& q : square) {
					const int ql(q.l);
					const int qr(q.r);
					assert(ql <= qr);
					while (nr < qr) {
						add(nr, true);
						nr++;
					}
					while (nl > ql) {
						--nl;
						add(nl, false);
					}
					while (nr > qr) {
						--nr;
						rem(nr, true);
					}
					while (nl < ql) {
						rem(nl, false);
						nl++;
					}

					anss[q.id] = getans();
				}
			}
			
		}
		return anss;
	}
};

long long int take(map<long long int, int>&mp) {
	auto x = mp.begin()->first;
	mp[x]--;
	if (mp[x] == 0)mp.erase(x);
	return x;
}

int main() {
	int N; cin >> N;
	vector<long long int>as(N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		as[i] = a;
	}
	sort(as.begin(), as.end());
	long long int ans = 0;
	{
		map<long long int, int>mp;
		for (auto a : as) {
			mp[a]++;
		}
		if (N % 2 == 0) {
			auto x=take(mp);
			auto y = take(mp);
			ans += x + y;
			mp[x + y]++;
			
		}
		for (int i = 0; i < (N-1) / 2; ++i) {
			auto x = take(mp);
			auto y = take(mp);
			auto z = take(mp);
			ans += x + y + z;
			mp[x + y + z]++;
		}
	}
	cout << ans << endl;
	return 0;
}