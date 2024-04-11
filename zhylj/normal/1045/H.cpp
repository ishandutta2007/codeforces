#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

ll fac[kN], fac_inv[kN];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < kN; ++i) fac[i] = fac[i - 1] * i % kMod;
	fac_inv[kN - 1] = QPow(fac[kN - 1], kMod - 2);
	for(int i = kN - 2; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
}
ll C(int a, int b) {
	if(b > a) return 0;
	if(a == b) return 1;
	//printf("%d %d %lld %lld %lld\n", a, b, fac[a], fac_inv[b]);
	return fac[a] * fac_inv[a - b] % kMod * fac_inv[b] % kMod;
}
ll SgCalc(int cnt_sg_1, int cnt_1, int cnt_sg_0, int cnt_0) {
	return C(cnt_1 - 1, cnt_sg_1 - 1) * C(cnt_0 - 1, cnt_sg_0 - 1) % kMod;
}

ll Calc(char s[], int n, int a, int b, int c, int d) {
//	printf("%s\n", s + 1);
	ll ret = 0;
	for(int i = 2; i <= n; ++i) {
		int cnt_sg_1 = b + 1, cnt_1 = d + cnt_sg_1,
			cnt_sg_0 = c, cnt_0 = a + cnt_sg_0;
		if(cnt_0 + cnt_1 == n - i + 1 && abs(cnt_sg_0 - cnt_sg_1) <= 1) {
			//printf("%d: %d %d %d %d\n", i, cnt_sg_0, cnt_0, cnt_sg_1, cnt_1);
			//printf("%lld\n", SgCalc(cnt_sg_1, cnt_1, cnt_sg_0, cnt_0));
			ret = (ret + SgCalc(cnt_sg_1, cnt_1, cnt_sg_0, cnt_0)) % kMod;
		}
	}
	//printf("====\n");
	//printf("ret = %lld\n", ret);
	for(int i = 2; i <= n; ++i) {
		int cnt_sg_1 = b, cnt_1 = d + cnt_sg_1,
			cnt_sg_0 = c + 1 - (s[i - 1] == '1'), cnt_0 = a + cnt_sg_0 - (s[i - 1] == '0');
	//	printf("%d: %d %d %d %d\n", i, cnt_sg_0, cnt_0, cnt_sg_1, cnt_1);
		if(s[i] == '1' && cnt_0 + cnt_1 == n - i + 1 && abs(cnt_sg_0 - cnt_sg_1) <= 1) {
			ret = (ret + SgCalc(cnt_sg_1, cnt_1, cnt_sg_0, cnt_0)) % kMod;
		}
		if(s[i - 1] == '0' && s[i] == '0') --a;
		if(s[i - 1] == '0' && s[i] == '1') --b;
		if(s[i - 1] == '1' && s[i] == '0') --c;
		if(s[i - 1] == '1' && s[i] == '1') --d;
		//printf("%d %c %c %d %d %d %d\n", i, s[i - 1], s[i], a, b, c, d);
		if(a < 0 || b < 0 || c < 0 || d < 0) break;
	}
	return ret;
}

bool Check(char s[], int n, int a, int b, int c, int d) {
	int a0 = 0, b0 = 0, c0 = 0, d0 = 0;
	for(int i = 1; i < n; ++i) {
		int x = s[i] - '0', y = s[i + 1] - '0';
		if(x == 0 && y == 0) ++a0;
		if(x == 0 && y == 1) ++b0;
		if(x == 1 && y == 0) ++c0;
		if(x == 1 && y == 1) ++d0;
	}
	return a0 == a && b0 == b && c0 == c && d0 == d;
}

char A[kN], B[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		Init();
		scanf("%s%s", A + 1, B + 1);
		int n, m, a, b, c, d; rd(a, b, c, d);
		if(abs(b - c) > 1) { printf("0\n"); return 0; }
		n = strlen(A + 1); m = strlen(B + 1);
		ll ans_A = Calc(A, n, a, b, c, d),
		   ans_B = Calc(B, m, a, b, c, d);
		ans_B += Check(B, m, a, b, c, d);
		ll ans = (ans_B - ans_A + kMod) % kMod;
		printf("%lld\n", ans);
	} return 0;
}