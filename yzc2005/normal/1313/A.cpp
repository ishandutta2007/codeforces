 #include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fail puts("NO"), exit(0)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
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

int t, a[3];

int main() {
	for(rd(t); t; --t) {
		fu(i, 0, 2) rd(a[i]);
		int ans = 0;
		fu(i, 1, 3) {
			if(i == 1) fu(j, 0, 2) if(a[j]) ++ans, --a[j];
			if(i == 2) {
				fu(j, 0, 2)
					fu(k, j + 1, 2)
						if(a[j] && a[k]) 
							++ans, --a[j], --a[k];
			}
			if(i == 3) if(a[0] && a[1] && a[2]) ++ans;
			//cout << ans << endl;
			sort(a, a + 3), reverse(a, a + 3);
		}
		printf("%d\n", ans);
	}
	return 0;
}