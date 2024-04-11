#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

int t, n, m, p;
string s[105];
bool used[105];
deque <string> q;

int main() {
	cin >> n >> m;
	fu(i, 1, n) cin >> s[i];
	fu(i, 1, n) {
		if(used[i]) continue;
		fu(j, i + 1, n) {
			bool f = 1;
			fu(k, 1, m) if(s[i][k - 1] != s[j][m - k]) f = 0;
			if(!f) continue;
			q.push_front(s[i]), q.push_back(s[j]);
			used[i] = used[j] = 1;
			break;
		}
		if(!used[i]) {
			bool f = 1;
			fu(k, 1, m / 2) if(s[i][k - 1] != s[i][m - k]) f = 0;
			if(f) p = i; 
		}
	}
	cout << (q.size() + (p != 0)) * m << endl;
	fu(i, 1, q.size() / 2) cout << q.front(), q.pop_front();
	if(p) cout << s[p];
	fu(i, 1, q.size()) cout << q.front(), q.pop_front(); 
	return 0;
}