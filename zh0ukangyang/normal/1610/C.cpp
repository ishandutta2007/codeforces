#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7; 
int n, a[N], b[N];
bool check(int x) {
	int now = 0;
	R(i, n, 1) 
		if(a[i] >= now && b[i] >= x - now - 1) 
			 now += 1;
	return now >= x;
}
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i] >> b[i];
//	check(2);
	int l = 1, r = n, ns = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ns << '\n';
}
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}