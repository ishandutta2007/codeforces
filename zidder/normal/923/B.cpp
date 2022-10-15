#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>

using namespace std;

typedef long long			LL;
typedef long double			LD;
//typedef unsigned long long	ULL;
typedef unsigned int		UI;

//#define FILE
#define fr			first
#define sc			second
#define mp			make_pair
#define pub			push_back
#define all(x)		(x).begin(), (x).end()
#define sz(x)		LL((x).size())
#define F(i,a,b)	for (int i = a; i < b; i++)
#define R(i,a,b)	for (int i = a - 1; i >= b; i--)

const UI		N = 100005;
const LL		Mod = 1000000007;
const LL		INF = 1000000000;
const LL		INF64 = 1000000000000000000;
const LD		PI = acos(-1.0);
const LD		E = 2.7182818284590452353602874713527;
const UI		dir = 4;
const int		prime = 31;

LL gcd(LL a, LL b)		{ return a != 0 ? gcd(b%a, a) : b; }
LL lcm(LL a, LL b)		{ return a / gcd(a, b) * b; }
LL length(LL n)			{ return n < 2 ? 1 : 1 + length(n >> 1); }

template<class A, class...B> A min(A a, A b, A c, B... d) { return min(a, min(b, c, d...));	}
template<class A, class...B> A max(A a, A b, A c, B... d) { return max(a, max(b, c, d...)); }

priority_queue<LL> st;
LL T[N], V[N], n;


void input() {
	cin >> n;
	F(i, 0, n)	cin >> V[i];
	F(i, 0, n)	cin >> T[i];
}

void solve() {
	LL add = 0;
	F(i, 0, n) {
		LL current = 0;
		st.push(-(V[i] + add));

		while (!st.empty() && st.top() >= -(add + T[i])) {
			current += (-st.top() - add);
			st.pop();
		}

		add += T[i];
		current += sz(st) * T[i];
		cout << current << " ";
	}
	cout << endl;
}

int main() {

#ifdef FILE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
#endif

	int testcases = 1;
	//cin >> testcases;
	while (testcases--) {
		input();
		//clock_t start = clock();
		solve();
		//printf("---------------------\n%.5f seconds\n---------------------\n", (clock() - start + 0.) / CLOCKS_PER_SEC);
	}
	
	return 0;
}