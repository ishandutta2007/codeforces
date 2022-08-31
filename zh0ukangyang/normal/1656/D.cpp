#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int m, a[N];
int deg[N];

vi e[N];
void dfs(int x, int fa, int w) {
	if(deg[x] == 2) a[x] = - 2 * w;
	else a[x] = w * (2 - deg[x]);
//	cout << x << " : " << "w = " << w << '\n';
	for(const int &v : e[x]) if(v != fa) dfs(v, x, w);
}

ll calc(ll n) {
	if(n <= 10) {
		L(i, 2, n) {
			int sum = i * (i + 1) / 2;
			if(sum > n) break ;
			if((n - sum) % i == 0) {
				return i;
			}
		}
		return -1;
	}
	if(n % 2 == 1) 
		return 2;
	return calc(n / 2);
}

ll n;
void Main () {
	cin >> n;
	ll pn = n ;
	int cnt = 0;
	while(n % 2 == 0) {
		cnt += 1;
		n /= 2;
	}
	if(n == 1) {
		cout << -1 << '\n';
		return ;
	}
	__int128 k = (__int128) n * (n + 1) / 2;
	if(k <= pn) {
		cout << n << '\n';
	} else {
		cout << (1LL << (cnt + 1)) << '\n';
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}