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

int main()
{
	int n, k, ans;
	ans = 0;

	cin >> k >> n;
	k &= 1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		x &= 1;
		if(i == n - 1)
			ans ^= x;
		else
			ans ^= x & k;
	}
	if(!ans)            
		cout << "even";
	else
		cout << "odd";
	
	return 0;
}