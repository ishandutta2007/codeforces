#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

int T, n;
vector <vector <int> > v;
vector <int> flag, emp;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n; v.clear();
		flag.clear(), emp.clear();
		emp.push_back(1);
		v.push_back(emp);
		flag.push_back(1);
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			if (i == 1) continue;
			if (a == 1) {
				vector <int> ne;
				ne = v.back();
				ne.push_back(1);
				flag.push_back(1);
				v.push_back(ne);
			}
			else {
				for (int j = v.size() - 1; j >= 0; j--) {
					if (flag[j] && v[j].back() == a - 1) {
						v.push_back(v[j]);
						flag[j] = 0, flag.push_back(1);
						v[v.size() - 1].pop_back();
						v[v.size() - 1].push_back(a);
						break;
					}
					flag[j] = 0;
				}
			}
		}
		for (vector <int> a : v) {
			for (int b = 0; b < a.size(); b++)
				cout << a[b] << "\n."[b != a.size() - 1];
		}
	}
	return 0;
}