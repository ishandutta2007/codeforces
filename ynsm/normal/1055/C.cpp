#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 1e9;
const ll INF = 1e18;

int main(){               
	ll la, ra, ta;        
	ll lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	
	ll g = __gcd(ta, tb);
	ll d = ((lb - la) % g + g) % g;
	ll ans = min(ra - la, rb - lb + (d % g + g) % g) - d;
	
	swap(la, lb);
	swap(ra, rb);
	swap(ta, tb);
	d = ((lb - la) % g + g) % g;
	ans = max(ans, min(ra - la, rb - lb + (d % g + g) % g) - d);
	cout << max(ans + 1, 0ll);
	return 0;
}