#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;

const int N = 107;
int n, a[N], w[N][N], dp[N][N];
bool vis[N];
int h[N];
void Main () {
	me(w, 0x3f);
	cin >> n;
	L(i, 1, n) cin >> a[i];
//	L(i, 1, n) {
//		int cnt = 0;
//		
//		L(j, i, n) {
//			if(a[i] <= n) {
//				h[a[i]] += 1;
//			}
//			while(h[cnt]) 
//				 ++cnt;
//			w[i][j] = cnt + 1;
//		}
//		me(cnt, 0); 
//	}
	ll ns = 0;
	L(i, 1, n) {
		if(a[i] == 0) 
			ns += (ll) i * (n - i + 1);
		ns += (ll) i * (n - i + 1);
	}
	cout << ns << '\n';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) Main ();
	
	return 0;
}