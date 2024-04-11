#include <bits/stdc++.h>
//pray for me. 
using namespace std;
typedef long long ll;
#define mem(a, x) memset(a, x, sizeof(a))
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

const int N = 5005;
int t, n, ans;
string s, s1, anss;

int main() {
	for(rd(t); t; --t) {
		rd(n); cin >> s;
		ans = 0, s1.resize(n), anss.resize(n);
		fu(k, 1, n) {
			int tot = -1;
			fu(i, k, n) s1[++tot] = s[i - 1];
			if((n - k) & 1) fu(i, 1, k - 1) s1[++tot] = s[i - 1];
			else fd(i, k - 1, 1) s1[++tot] = s[i - 1];
			if(!ans || s1 < anss) anss = s1, ans = k;
		} 
		cout << anss << endl << ans << endl;
	}
	return 0;
}