#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;
struct Mod {
public:
	int num;
	Mod() :Mod(0) { ; }
	Mod(long long int n) :num(((n%mod) + mod) % mod) {
	}
	operator int() { return num; }
};
Mod operator+(const Mod&a, const Mod&b) { return Mod((a.num + b.num) % mod); }
Mod operator-(const Mod&a, const Mod&b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(const Mod&a, const Mod&b) { return Mod(((long long)a.num*b.num) % mod); }
Mod operator^(const Mod&a, const int n) {
	if (n == 0)return Mod(1);
	Mod res = (a*a) ^ (n / 2);
	if (n % 2)res = res*a;
	return res;

}
Mod inv(const Mod a) {
	return a ^ (mod - 2);
}
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a*inv(b);
}
#define MAX_MOD_N 1024
Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = Mod(1);
	for (int i = 0; i<amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
vector<int>ds;
map<pair<int, int>, Mod>con_memo, memo;
Mod con(int one_con, int two_con) {

	if (con_memo.find(make_pair(one_con, two_con)) == con_memo.end()) {
		if (one_con == 0 && two_con == 0)return con_memo[make_pair(one_con, two_con)] = Mod(1);
		if (one_con == 0 && two_con == 1)return con_memo[make_pair(one_con, two_con)] = Mod(0);
		if (one_con == 0 && two_con == 2)return con_memo[make_pair(one_con, two_con)] = Mod(0);
		if (one_con % 2)return con_memo[make_pair(one_con, two_con)] = Mod(0);
		else {
			if (one_con&&two_con) {
				return con_memo[make_pair(one_con, two_con)] =
					Mod(one_con - 1)*con(one_con - 2, two_con) +
					Mod(two_con)*con(one_con, two_con - 1);
			}
			else if (one_con) {
				return con_memo[make_pair(one_con, two_con)] =
					Mod(one_con - 1)*con(one_con - 2, two_con);
			}
			else if (two_con) {
				return con_memo[make_pair(one_con, two_con)] =
					comb(two_con - 1, 2)*con(one_con + 2, two_con - 3);
			}
			else {
				assert(false);
				return Mod(0);
			}
		}
	}
	return con_memo[make_pair(one_con, two_con)];

}
Mod solve(const int now, const int num) {
	if (now == ds.size()) {
		if (num)return Mod(0);
		else return Mod(1);
	}
	else if (!num) {
		return Mod(0);
	}
	if (now + num>ds.size())return Mod(0);
	else {
		if (memo.find(make_pair(now, num)) != memo.end())return memo[make_pair(now, num)];
		int threenum = 0, twonum = 0;
		for (int i = now; i<now + num; ++i) {
			if (ds[i] == 3)threenum++;
			else twonum++;
		}
		//direct
		Mod ans = 0;
		for (int two_a = 0; two_a <= twonum; ++two_a) {
			//one connect
			int two_b = twonum - two_a;
			//direct
			for (int three_a = 0; three_a <= threenum; ++three_a) {
				//one connect
				for (int three_b = 0; three_a + three_b <= threenum; ++three_b) {
					//two connect
					int three_c = threenum - three_a - three_b;
					Mod con_cnt = con(two_b + three_b, three_c);
					int nextnum = two_a + three_a * 2 + three_b;
					Mod pattern = 1;
					{
						int rest = nextnum;
						for (int i = 0; i<two_a + three_b; ++i) {
							pattern = pattern*comb(rest, 1);
							rest--;
						}
						for (int i = 0; i<three_a; ++i) {
							pattern = pattern*comb(rest, 2);
							rest -= 2;
						}
						assert(rest == 0);
					}
					if ((con_cnt*pattern).num == 0)continue;
					ans = ans + comb(twonum,two_a)*comb(threenum,three_a)*comb(threenum-three_a,three_b)*con_cnt*pattern*solve(now + num, nextnum);
				}
			}
		}
		return memo[make_pair(now, num)] = ans;
	}
}
int main() {
	init();
	int N; cin >> N; 
	for (int i = 0; i<N; ++i) {
		int d; cin >> d;
		ds.push_back(d);
	}
	Mod ans(solve(1, ds[0]));
	cout << ans.num << endl;
	return 0;
}