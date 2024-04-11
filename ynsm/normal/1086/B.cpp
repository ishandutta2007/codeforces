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

int n, s, x, cnt[N];
int main(){
	cin >> n >> s;
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		cnt[v]++;
		cnt[u]++;
	}
	for(int i = 1; i <= n; i++)
		if(cnt[i] == 1)
			x++;
	cout << fixed << setprecision(20) << 2.0 * s / x << endl;
	return 0;
}