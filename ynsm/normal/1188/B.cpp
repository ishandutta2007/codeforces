#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, p, k;
map<int, int> s;
ll ans;
int main()
{
	cin >> n >> p >> k;
	while(n--){
		ll x;
		cin >> x;
		x = (x * x % p * x % p * x % p - k * x % p + p) % p;
		ans += s[x]++; 
	}
	cout << ans;
	return 0;
}