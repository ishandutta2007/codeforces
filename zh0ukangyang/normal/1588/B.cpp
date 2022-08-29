#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20, M = 200, mod = 998244353;
int n ;
ll query (int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	fflush(stdout);
	ll w;
	w = 0;
//	L(i, l, r) L(j, i + 1, r) w += a[i] > a[j];
	cin >> w;
//	cout << w << '\n';
	return w;	
} 
ll C(int x) {
	return (ll) x * (x - 1) / 2;
}
ll getC(ll x) {
	ll v = sqrt (x * 2) - 3;
	v = max(v, 0LL);
	L(z, 1, 10) {
		if(C(v) == x) return v;
		++v;
	}
	return -1;
}
void Main () {
	cin >> n;
	ll all = query (1, n);
	int l = 1, r = n, ns = -1;
	while (true) {
		int mid = (l + r) >> 1;
		ll W = query (1, mid); 
		if(W == all) r = mid + 1;
		else if(W == 0) l = mid;
		else break;
	}
	ll mid = (l + r) >> 1;
	ll x = query (1, mid);
	ll y = query (1, mid - 1);
//	cout << "mid = " << mid << '\n'; 
	ll len = x - y;
	mid -= len;
//	cout << x << ' ' << y << '\n';
//	cout << "len = " << len << '\n';
//	cout << "real mid = " << mid << '\n';
	ll gw = query (1, mid);
	if(gw) {
		ll Z =  query (mid, n);
		cout << "! " << mid - getC(gw) << ' ' << mid << ' ' << mid + getC(Z) - 1 << endl;
	} else {
		l = mid + 1;
		while (l <= r) {
			int hmid = (l + r) >> 1;
//			cout << l << ' ' << r << '\n';
			if(query (mid, hmid) == C(hmid - mid + 1)) ns = hmid, l = hmid + 1;
			else r = hmid - 1;
		}
		++ns; 
		ll Z = query (ns, n);
		cout << "! " << mid << ' ' << ns << ' ' << ns + getC(Z) - 1 << endl;
	}
	fflush(stdout);
	
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}