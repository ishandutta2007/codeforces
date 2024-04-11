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

bool was[N];
int n;
int main()
{
	for(int i = 2; i < N; i++)
		for(int j = i + i; j < N; j += i)
			was[j] |= !was[i];
	for(int n = 4; n <= 1000; n++){
		bool ok = 0;
		for(int i = n; i <= n + n / 2; i++)
			if(!was[i])
				ok = 1;
		if(!ok){
			cerr << "GG";
			return 0;
		}
	}
	cin >> n;
	vector< pii > ans;
	ans.pb({1, n});
	for(int i = 1; i < n; i++)
		ans.pb({i, i + 1});
	for(int i = n, j = 1;; i++){
		if(!was[i])
			break;
		ans.pb({j, n / 2 + j});
		j++;
	}
	cout << ans.size() << endl;
	for(auto it : ans)
		cout << it.f << " " << it.s << endl;
	return 0;
}