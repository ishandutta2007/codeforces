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

int solve(){
	int x, ans;
	cin >> x;
	ans = 0;
	for(int i = 0; i < 30; i++){
		if(((1 << i) - 1) == x){
			for(int i = 2; i * i <= x; i++)
				if(x % i == 0)
					return x / i;
			return 1;
		}
		ans = ((1 << i) - 1);
		if(((1 << i) - 1) > x)
			break;
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
		cout << solve() << endl;
	return 0;
}