#include<iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int main() {
	ll n, m, a, b; cin >> n >> m >> a >> b;
	ll gcd1 = gcd(a, b);
	ll lcm1 = a * b / gcd1;
	ll x = 0, y = 0;
	if (m >= 2 * lcm1) {
		x = (m / lcm1 - 1)*(b / gcd(a, b));
		m = m % lcm1 + lcm1;
		y = 0;
	}

	//cout<<m<<" "<<x<<endl;

	int flg = 0;
	ll tmp = 0;
	for (ll i = 0; i*a <= m; i++) {
		if ((m - a*i) % b == 0) {
			tmp = i;
			y = (m - a * i) / b;
			flg = 1;
		}
	}
	x += tmp;
	if (flg && x + y <= n) {
		cout << x << " " << y << " " << n - x - y << endl;
	}
	else cout << -1 << endl;
}