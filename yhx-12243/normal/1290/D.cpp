#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

const int N = 1054;

int n, K, V;
bool alive[N];

inline bool query(int x) {char ch[4]; return cout << '?' << ' ' << x + 1 << endl, cin >> ch, *ch == 89;}
inline void test(int x) {alive[x] = alive[x] && !query(x);}
inline void reset()	{cout << 'R' << endl;}
inline int answer(int x) {return cout << '!' << ' ' << x << endl, 0;}

int main() {
	int i, j, I, J, o, d;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K, K = K >> (~K & 1), V = n / K;
	memset(alive, true, n);
	for (o = 0; o < V / 2; ++o, reset())
		for (i = V, j = V + 1; i > V / 2; --i, ++j) {
			I = (i + o) % V, J = (j + o) % V;
			for (d = 0; d < K; ++d) test(I * K + d);
			for (d = 0; d < K; ++d) test(J * K + d);
		}
	return answer(std::count(alive, alive + n, true));
}