#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
int k,x,n,m;
const int N = 55;
int A[N],B[N],AB[N],BA[N],BB[N];

void init() {
	scanf("%lld%lld%lld%lld",&k,&x,&n,&m);
	A[1] = 1;
	A[2] = 0;
	for (int i=3; i<=k; i++) A[i] = A[i - 2] + A[i - 1];
	B[1] = 0;
	B[2] = 1;
	for (int i=3; i<=k; i++) B[i] = B[i - 2] + B[i - 1];
	AB[1] = AB[2] = 0 ;
	AB[3] = AB[4] = 1;
	for (int i=5; i<=k; i++) AB[i] = AB[i - 2] + AB[i - 1];
	BA[1] = BA[2] = BA[3] = 0 ;
	BA[4] = 1;
	for (int i=5; i<=k; i++) BA[i] = BA[i - 2] + BA[i - 1] + ((i % 2LL) == 0LL);
	BB[1] = BB[2] = BB[3] = BB[4] = 0; BB[5] = BB[6] = 1;
	for (int i=7; i<=k; i++) BB[i] = BB[i - 2] + BB[i - 1] + ((i % 2LL) == 1LL);
//	for (int i=1; i<=k; i++) cout << BB[i] << ' ';
//	puts("");
}

void log(int a,int b,int ab,int ba,int ana,int lenAd) {
	int ra = n - a * 2 - ab - ba;
	int rb = m - b * 2 - ba - ab - lenAd;
	rep (i,ba) putchar('C');
	rep (i,a)  printf("AC");
	rep (i,ra) putchar('B');
	rep (i,ab) putchar('A');
	puts("");
	rep (i,(ab || ana)) putchar('C');
	rep (i,b)  printf("AC");
	rep (i,rb) putchar('B');
	rep (i,(ba || ana)) putchar('A');
	puts("");
}

void solve() {
	rep (a,n) rep (b,m) rep(ab,2) rep(ba,2)  for (int ana = (ba & ab) ;ana<2;ana++ ){
		int lenAd = (ana * 2 - ba - ab) * ana; 
		if (ba + a * 2 + ab > n) continue;
		if (ab + b * 2 + ba + lenAd > m) continue;
		if (a * A[k] + b * B[k] + 
			ab * AB[k] + ba * BA[k] + 
			(ana) * BB[k] != x) continue;
//		cout << a << ' ' << b << ' ' << ab << ' ' << ba << endl;
//		cout << A[k] << ' ' << B[k] << ' ' << AB[k] << ' ' << BA[k] << ' ' << BB[k] << endl;
		log(a,b,ab,ba,ana,lenAd);
		exit(0);
	}
	puts("Happy new year!");
}

#undef int
int main() {
	init();
	solve();
	return 0;
}