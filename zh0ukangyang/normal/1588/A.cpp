#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, M = 200, mod = 998244353;
int n, a[N], b[N], cnta[N], cntb[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i],  cnta[a[i] + 100] += 1;
	L(i, 1, n) cin >> b[i],  cntb[b[i] + 100] += 1;
	bool ok = true;
	int sum = 0;
	L(i, 0, M) {
		sum += cntb[i];
		if(sum < 0) {
			ok = false;
			break;
		}
		if(cnta[i] < sum)  {
			ok = false;
			break ;
		}
		sum -= cnta[i];
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
	L(i, 0, M + 2) cnta[i] = cntb[i] = 0; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}