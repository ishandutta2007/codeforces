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
	/*
	1-6
	2-5
	3-4
	*/
	int t;
	cin >> t;
	while(t--){
		ll x;
		cin >> x;
		if(x > 7 && x % 7 && x / 7 % 2 == 0)
			puts("YES");
		else
			puts("NO");			
	}
	return 0;
}