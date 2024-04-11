#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;

int n, m, k;
vector<int>nums;

//[l,r)
struct Po_Query {
	 int id;
	 int l;
	 int r;
	Po_Query(const int id_, const int l_, const int r_) :
		id(id_), l(l_), r(r_) {
	}

};

class Po_Algo {
public:
	const int size;
	vector<vector<Po_Query>>squares;

	long long int nans=0;
	vector<int>sums;

	Po_Algo(int size_):size(size_),squares(static_cast<size_t>(sqrt(size-1)+1)),nans(0),sums(1<<20,0) {
	
	}


	//vvf
	void add(const int v);

	//vvfO
	void rem(const int v);

	//[l,r)
	//0X^[g
	vector<long long int > getanss(const  vector<Po_Query> &querys) {
		for (const auto q : querys) {
			squares[q.l / (squares.size())].push_back(q);
		}
		for (auto& asquare : squares) {
			sort(asquare.begin(), asquare.end(), [](const  Po_Query &l, const  Po_Query &r) {return l.r < r.r; });
		}
		vector<long long int >anss(querys.size());

		int nl = 0;
		int nr = 0;
		for (auto square : squares) {
			for (auto q : square) {
				const int ql(q.l);
				const int qr(q.r);
				while (nr < qr) { add(nr); nr++; }
				while (nl > ql) { --nl; add(nl); }
				while (nr > qr) { --nr; rem(nr); }
				while (nl < ql) { rem(nl); nl++; }

				anss[q.id]=(nans);
			}
		}
		return anss;
	}

};



//example

//vvf
void Po_Algo::add(const int v) {
	nans += sums[nums[v] ^ k];
	sums[nums[v]]++;
};

//vvfO
void Po_Algo::rem(const int v) {
	sums[nums[v]]--;
	nans -= sums[nums[v] ^ k];
}


int main() {
	cin >> n >> m >> k;
	Po_Algo po(n+1);
	int now = 0;
	nums.push_back(0);
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		now ^= a;
		nums.push_back(now);
	}
	vector<Po_Query>ques;
	for (int i = 0; i < m; ++i) {
		int l, r; cin >> l >> r;
		l--; r++;
		ques.push_back(Po_Query(i,l,r));
	}
	vector<long long int >anss(po.getanss(ques));
	for (auto ans : anss) {
		cout << ans << endl;
	}
	return 0;
}