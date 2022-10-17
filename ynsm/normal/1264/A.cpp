#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, a[N], ans;
vector< int > solve(){
    vector< int > res;
    for(int i = 0; i < n / 2; i++){
		if(a[i] != a[i + 1]){
			res.pb(i + 1);
			for(int j = i + 1; j < n / 2; j++){
				if(a[j] != a[j + 1] && i + 1 < j - i){
					res.pb(j + 1);	
					int mx = -1;
					for(int q = j + 1; q < n / 2; q++)
						if(a[q] != a[q + 1] && i + 1 < q - j)
							mx = q + 1;
					if(mx == -1)
						break;
					res.pb(mx);
					return res;
				}
			}
			break;
		}
	}
	vector< int > kek(3, 0);
	return kek;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		vector< int > ans = solve();
		printf("%d %d %d\n", ans[0], ans[1] - ans[0], ans[2] - ans[1]);
	}
	return 0;
}