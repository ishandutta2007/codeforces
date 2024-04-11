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

int a[5], n;
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> a[0] >> a[1] >> n;
		a[2] = a[0] ^ a[1];
		cout << a[n % 3] << endl;
	}
	return 0;
}