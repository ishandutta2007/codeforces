#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

int dx[] = { 1,1,1,0,-1,-1,-1,0 };
int dy[] = { 1,0,-1,-1,-1,0,1,1 };



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
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
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

int main() {
	int N; cin >> N;
	vector<vector<int>>field(N + 2, vector<int>(N + 2));
	vector<vector<vector<vector<int>>>>sums(N + 2, vector<vector<vector<int>>>(N + 2,vector<vector<int>>(4,vector<int>(4))));
	vector<vector<vector<int>>>zeros(N + 2, vector<vector<int>>(N + 2, vector<int>(8)));
	
	for (int i = 1; i <= N; ++i) {
		string st; cin >> st;
		for (int j = 1; j <= N; ++j) {
			field[i][j] = st[j - 1] - '0';
		}
	}
	for (int y = 0; y <= N + 1; ++y) {
		for (int x = 0; x <= N + 1; ++x) {
			for (int k = 0; k < 4; ++k) {
				sums[y][x][k][field[y][x]] = 1;
			}
		}
	}
	for (int ny = 0; ny <= N+1; ++ny) {
		for (int nx = 0; nx <= N+1; ++nx) {
			for (int k = 0; k < 2; ++k) {
				int py = ny - dy[k];
				int px = nx - dx[k];
				if (!(px >= 0 && px <= N + 1 && py >= 0 && py <= N + 1))continue;

				int num = field[ny][nx];
				for (int l = 0; l <= 3; ++l) {
					if (l == num) {
						sums[ny][nx][k][l] = sums[py][px][k][l] + 1;
					}
					else {
						sums[ny][nx][k][l] = sums[py][px][k][l];
					}
				}
				if (num) {
					zeros[ny][nx][k] = zeros[py][px][k] + 1;
				}
				else {
					zeros[ny][nx][k] = 0;
				}
			}
		}
	}
	for (int ny = N+1; ny >= 0; --ny) {
		for (int nx = 0; nx <= N+1; ++nx) {
			for (int k = 2; k < 4; ++k) {
				int py = ny - dy[k];
				int px = nx - dx[k];
				if (!(px >= 0 && px <= N +1 && py >= 0 && py <= N + 1))continue;

				int num = field[ny][nx];
				for (int l = 0; l <= 3; ++l) {
					if (l == num) {
						sums[ny][nx][k][l] = sums[py][px][k][l] + 1;
					}
					else {
						sums[ny][nx][k][l] = sums[py][px][k][l];
					}
				}
				if (num) {
					zeros[ny][nx][k] = zeros[py][px][k] + 1;
				}
				else {
					zeros[ny][nx][k] = 0;
				}
			}
		}
	}
	for (int ny = N+1; ny >= 0; --ny) {
		for (int nx = N+1; nx >= 0; --nx) {
			for (int k = 4; k < 6; ++k) {
				int py = ny - dy[k];
				int px = nx - dx[k];
				if (!(px >= 0 && px <= N + 1 && py >= 0 && py <= N  +1))continue;
				int num = field[ny][nx];
				if (num) {
					zeros[ny][nx][k] = zeros[py][px][k] + 1;
				}
				else {
					zeros[ny][nx][k] = 0;
				}
			}
		}
	}
	for (int ny = 0; ny <= N+1; ++ny) {
		for (int nx = N+1; nx >= 0; --nx) {
			for (int k = 6; k < 8; ++k) {
				int py = ny - dy[k];
				int px = nx - dx[k];
				if (!(px >= 0 && px <= N + 1 && py >= 0 && py <= N + 1))continue;
				int num = field[ny][nx];
				if (num) {
					zeros[ny][nx][k] = zeros[py][px][k] + 1;
				}
				else {
					zeros[ny][nx][k] = 0;
				}
			}
		}
	}
	long long int ax, ay=-1;
	bool nor = false;
	ld amax = -1e18;
	for (int ny = 1; ny <= N; ++ny) {
		for (int nx = 1; nx <= N; ++nx) {
			{
				int asize = 1e5;
				for (int k = 1; k < 9; k += 2) {
					asize = min(zeros[ny][nx][k], asize);
				}
				if (!asize)continue;
				vector<int>nums(4);
				for (int k = 0; k < 4; ++k) {
					nums[k] += sums[ny][nx + asize-1][1][k] - sums[ny][nx - asize][1][k];
					nums[k] += sums[ny - asize+1][nx][3][k]-sums[ny + asize][nx][3][k] ;
					if (k == field[ny][nx])nums[k]--;
				}
				assert(!nums[0]);
				ld log_ans = nums[2] * log(2.l) + nums[3] * log(3.l);
				if (log_ans > amax) {
					amax = log_ans;
					ax = nx; ay = ny;
					nor = true;
				}
			}
			{
				int asize = 1e5;
				for (int k = 0; k < 8; k += 2) {
					asize = min(zeros[ny][nx][k], asize);
				}
				if (!asize)continue;
				vector<int>nums(4);
				for (int k = 0; k < 4; ++k) {
					nums[k] += sums[ny-asize+1][nx + asize - 1][2][k] - sums[ny+asize][nx - asize][2][k];
					nums[k] += sums[ny + asize - 1][nx+asize-1][0][k] - sums[ny - asize][nx-asize][0][k];
					if (k == field[ny][nx])nums[k]--;
				}
				assert(!nums[0]);
				ld log_ans = nums[2] * log(2.l) + nums[3] * log(3.l);
				if (log_ans > amax) {
					amax = log_ans;
					ax = nx; ay = ny;
					nor = false;
				}
			}
		}
	}
	if (ay == -1) {
		cout << 0 << endl;
	}
	else {
		const int ny = ay;
		const int nx = ax;
		Mod ans(1);
		if (nor) {
			int asize = 1e5;
			for (int k = 1; k < 9; k += 2) {
				asize = min(zeros[ny][nx][k], asize);
			}
			vector<int>nums(4);
			for (int k = 0; k < 4; ++k) {
				nums[k] += sums[ny][nx + asize - 1][1][k] - sums[ny][nx - asize][1][k];
				nums[k] += sums[ny -asize+1][nx][3][k] - sums[ny + asize][nx][3][k];
				if (k == field[ny][nx])nums[k]--;
			}
			assert(!nums[0]);
			for (int k = 0;k < 4; ++k) {
				for (int j = 0; j < nums[k]; ++j) {
					ans *= k;
				}
			}
		}
		else {
			int asize = 1e5;
			for (int k = 0; k < 8; k += 2) {
				asize = min(zeros[ny][nx][k], asize);
			}
			vector<int>nums(4);
			for (int k = 0; k < 4; ++k) {
				nums[k] += sums[ny + asize - 1][nx + asize - 1][0][k] - sums[ny - asize][nx - asize][0][k];
				nums[k] += sums[ny - asize+1][nx + asize - 1][2][k] - sums[ny + asize][nx - asize][2][k];
				if (k == field[ny][nx])nums[k]--;
			}
			assert(!nums[0]);
			for (int k = 0; k < 4; ++k) {
				for (int j = 0; j < nums[k]; ++j) {
					ans *= k;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}