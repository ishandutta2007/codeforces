// luogu-judger-enable-o2
/*
State: Accepted 
*/
#include <bits/stdc++.h>

const int kMaxN = 2e5 + 5;
const double kEps = 5e-12;
const double kInf = 1e4;

int n;
double a[kMaxN];

double Check(double x) {
	double f = 0, g = 0, ans = 0;
	for(int i = 0; i < n; ++i) {
		f = std::max(f + a[i] - x, (double)0);
		g = std::min(g + a[i] - x, (double)0);
		ans = std::max({fabs(f), fabs(g), ans});
	}
	return ans;
}
double Solve() {
	double l = -kInf, r = kInf, midl, midr, fmidl, fmidr;
	while(r - l > kEps) {
		midl = l + (r - l) / 3; fmidl = Check(midl);
		midr = (midl + r) / 2; fmidr = Check(midr);
		if(fmidl > fmidr) l = midl;
		else r = midr;
	}
	return fmidl;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lf", a + i);
	printf("%.8lf", Solve());
	return 0;
}