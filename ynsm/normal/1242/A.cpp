#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll n;
vector< ll > v;
int main()
{
	cin >> n;
	for(ll i = 2; i * i <= n; i++)
		if(n % i== 0){
			v.pb(i);
			while(n % i == 0)
				n /= i;		 	
		}
	if(n > 1)
		v.pb(n);
	if(v.size() == 1)
		printf("%lld", v[0]);
	else
		printf("1");
	return 0;
}