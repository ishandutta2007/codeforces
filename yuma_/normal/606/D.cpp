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
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
using namespace std;


int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	Mod(int n) : num((n % mod + mod) % mod) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a)+b; }
Mod operator++(Mod &a) { return a = a + Mod(1); }
Mod operator++(Mod &a,int) {
	Mod old(a);
	++a;
	return old; 
}
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a = a - Mod(1); }
Mod operator--(Mod &a, int) {
	Mod old(a);
	--a;
	return old;
}
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
 }
Mod operator/(const long long int a, const Mod b) {
	assert(b.num != 0);
	return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
	assert(b.num != 0);
	return a = a * inv(b);
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
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

template<typename T>
vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {
	vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));
	assert(l[0].size() == r.size());
	for (unsigned int h = 0; h < l.size(); ++h) {
		for (unsigned int i = 0; i < r.size(); ++i) {
			for (unsigned int w = 0; w < r[0].size(); ++w) {
			
				ans[h][w] +=l[h][i] * r[i][w];
			}
		}
	}
	return ans;
}
template<typename T>
vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {
	assert(a.size() == a[0].size());
	if (!n) {
		vector<vector<T>>e(a.size(), vector<T>(a[0].size()));
		for (unsigned int i = 0; i < a.size(); ++i) {
			e[i][i] = 1;
		}
		return e;
	}
	if (n == 1)return a;
	else {
		vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));
		ans = powgyou(a, n / 2);
		ans = keisann(ans, ans);
		if (n % 2) {
			ans = keisann(ans, a);
		}
		return ans;
	}
}



long long int powint(long long int a, int b) {
	if (b == 0)return 1;
	if (b == 1)return a;
	else {
		long long int ans = 1;
		long long int c = powint(a, b / 2);
		ans *= c*c;
		ans *= (b % 2) ? a : 1;
		return ans;
	}
	
}

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void) {
	int N, M; cin >> N >> M;
	vector<pair<int,pair<int, bool>>>edges;
	for (int i = 0; i < M; ++i) {
		int a;bool b; cin >> a >> b;
		pair<int, pair<int, bool>>aa;
		aa = make_pair(i, make_pair(a, b));
		edges.push_back(aa);
	}

	vector<pair<int, int>>damerei;
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j <= i; ++j) {
			damerei.push_back(make_pair( i + 3,j + 2 ));
		}
	}
	sort(edges.begin(), edges.end(), [](const pair<int, pair<int, bool>>&l, pair<int, pair<int, bool>>&r) {return l.second.first == r.second.first?l.second.second>r.second.second:l.second.first < r.second.first; });
	int to = 2;
	int mudaused = 0;
	int used = 0;
	vector<pair<int, pair<int, int>>>ans;
	for (int i = 0; i < edges.size(); ++i) {
		pair<int, pair<int, bool>>edge = edges[i];
		int muda = used*(used - 1) / 2;
		if (edge.second.second) {
			ans.push_back(make_pair( edge.first,make_pair( 1,to ) ));
			to++;
			used++;
		}
		else {
			mudaused++;
			if (mudaused > muda) {
				cout << -1 << endl;
				return 0;
			}
			else { 
				ans.push_back(make_pair( edge.first,damerei[mudaused-1] ));
				

			}
		}
	}
	sort(ans.begin(),ans.end(), [](const pair<int, pair<int,int>>&l, pair<int, pair<int, int>>&r) {return l.first < r.first; });
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].second.first << " " << ans[i].second.second << endl;
	}
	return 0;
}