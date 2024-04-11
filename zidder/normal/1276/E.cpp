#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<pair<long long, long long> > solution(long long* a){
	// a, b -> 2b - a, b
	// max 500 steps
	// max 10^18
	// a <= b <= c <= d ->

	vector<pair<long long, long long> > result;
	auto srt = [&](){
		sort(a, a+4);
	};
	auto symmetry = [&](long long a, long long b){
		return 2 * b - a;
	};
	auto act = [&](int i, int j){
		if (a[i] == a[j]) return;
		result.emplace_back(a[i], a[j]);
		a[i] = symmetry(a[i], a[j]);
	};
	auto bring_in = [&](){
		sort(a, a+3);
		// bring a[3] into a[0] to a[2]

		// mid -> left, mid -> right, ... until the largest lies inside
		// then pack back the same way you unpacked
		// if d \in (a, b) and you perform (a over b), do (d over b) as well
		// will pack and take d with you
		// 3 * log d / log 1.618 (fibo)
		vector<pair<int, int> > tmp;
		bool b = false;
		while (symmetry(a[3], a[2]) < a[0]){
			b = !b;
			if (b){
				act(1, 2);
				tmp.emplace_back(1, 2);
			} else {
				act(1, 0);
				tmp.emplace_back(1, 0);
			}
			sort(a, a+3);
		}
		reverse(tmp.begin(), tmp.end());
		act(3, 2);
		for (auto& p : tmp){
			act(p.first, p.second);
			sort(a, a+3);
			if (a[3] < a[0] && symmetry(a[3], a[0]) <= a[2]){
				act(3, 0);
			}
			if (a[3] > a[2] && symmetry(a[3], a[2]) >= a[0]){
				act(3, 2);
			}
		}
	};
	srt();
	if (a[3] - a[0] > 1){
		while (symmetry(a[3], a[2]) < a[0] || symmetry(a[0], a[1]) > a[3]){
			if (symmetry(a[3], a[2]) < a[0]){
				bring_in();
			} else {
				act(0, 1);
				srt();
				bring_in();
			}
			srt();
		}
	}

	// we can make a, b, c very close, and do the procedure
	{
		bool b = false;
		while (a[3] - a[0] > 1){
			b = !b;
			bool inside;
			if (b){
				inside = (symmetry(a[0], symmetry(symmetry(a[1], a[2]), a[3])) <= a[2]);
			} else {
				inside = (symmetry(a[3], symmetry(symmetry(a[2], a[1]), a[0])) >= a[1]);
			}
			if (inside){
				if (b){
					act(1, 2);
					act(1, 3);
					act(0, 1);
				} else {
					act(2, 1);
					act(2, 0);
					act(3, 2);
				}
			} else {
				if (b){
					act(0, 1);
				} else {
					act(3, 2);
				}
			}
			srt();
		}
	}
	// cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;

	if (a[0] > 0){
		while (a[3] > 1){
			if (symmetry(a[3], a[0]) >= 0){
				act(3, 0);
			} else if (a[3] != a[1] && symmetry(a[3], a[1]) >= 0) {
				act(3, 1);
			} else if (a[3] != a[2] && symmetry(a[3], a[2]) >= 0) {
				act(3, 2);
			} else {
				if (a[2] < a[3]){
					act(3, 2);
					act(3, 0);
				} else {
					act(3, 1);
					act(3, 0);
				}
			}
			srt();
		}
	} else if (a[0] < 0){
		while (a[0] < 0){
			if (symmetry(a[0], a[3]) <= 1){
				act(0, 3);
			} else if (a[0] != a[2] && symmetry(a[0], a[2]) <= 1) {
				act(0, 2);
			} else if (a[0] != a[1] && symmetry(a[0], a[1]) <= 1) {
				act(0, 1);
			} else {
				if (a[0] < a[1]){
					act(0, 1);
					act(0, 3);
				} else {
					act(0, 2);
					act(0, 3);
				}
			}
			srt();
		}
	}
	// cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
	return result;
}

void solve(int test_ind){
	long long a[4];
	long long b[4];
	for (int i=0;i<4;++i) scanf("%lld", &a[i]);
	long long ga = 0;
	for (int i=0;i<4;++i) ga = __gcd(abs(a[i]-a[0]), ga);
	for (int i=0;i<4;++i) scanf("%lld", &b[i]);
	long long gb = 0;
	for (int i=0;i<4;++i) gb = __gcd(abs(b[i]-b[0]), gb);
	if (ga != gb){
		cout << -1 << endl;
		return;
	}
	if (ga == 0) {
		if (a[0] == b[0]){
			cout << 0 << endl;
		} else {
			cout << -1 << endl;
		}
		return;
	}
	if ((a[0] % ga+ga)%ga != (b[0] % gb+gb)%gb){
		cout << -1 << endl;
		return;
	}

	long long add = a[0];
	for (int i=3;i>=0;--i){
		b[i] = (b[i] - a[0]) / gb;
		a[i] = (a[i] - a[0]) / ga;
		// the same g
	}

	long long sa = 0;
	for (int i=0;i<4;++i) sa += !!(a[i]%2);
	long long sb = 0;
	for (int i=0;i<4;++i) sb += !!(b[i]%2);
	
	if (sa != sb) { // number of odds
		cout << -1 << endl;
		return;
	}

	bool bl = true;
	for (int i=0;i<4;++i) if (a[i] != a[0]) bl = false;
	if (bl){
		for (int i=0;i<4;++i) if (b[i] != a[0]) bl = false;
		if (bl){
			cout << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return;
	}

	vector<pair<long long, long long> > sola = solution(a), solb = solution(b);
	reverse(solb.begin(), solb.end());
	for (int i=0;i<solb.size();++i){
		sola.emplace_back(2 * solb[i].second - solb[i].first, solb[i].second);
	}
	cout << sola.size() << endl;
	for (auto &p: sola){
		cout << p.first * ga + add << " " << p.second * ga + add << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}