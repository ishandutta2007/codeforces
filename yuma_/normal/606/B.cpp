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
	int X, Y, x0, y0; cin >> Y >> X >> y0 >> x0;
	y0--; x0--;
	string st; cin >> st;
	vector<vector<int>>f(Y, vector<int>(X,st.size()));
	f[y0][x0] = 0;
	for (int i = 0; i < st.size(); ++i) {
		switch (st[i]) {
		case 'U':
			if (y0 > 0) {
				y0--;
				f[y0][x0] = min(f[y0][x0], i + 1);
			}
			break;
		case 'R':
			if (x0 <X-1) {
				x0++;
				f[y0][x0] = min(f[y0][x0], i + 1);

			}
			break;
		case 'L':
			if (x0 > 0) {
				x0--;
				f[y0][x0] = min(f[y0][x0], i + 1);

			}
			break;
		default:
			if (y0 <Y-1) {
				y0++;
				f[y0][x0] = min(f[y0][x0], i + 1);

			}
			break;
		}
	}
	vector<int>anss(st.size() + 1);
	for (int i = 0; i < Y; ++i) {
		for (int j = 0; j < X; ++j) {
			anss[f[i][j]]++;
		}
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i != anss.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}